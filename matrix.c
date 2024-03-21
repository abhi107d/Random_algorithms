#include<stdio.h>
#include<stdlib.h>

int** make_arr(int rs,int cs){
	int** arr=malloc(rs*sizeof(int*));
	for(int i=0;i<cs;i++){
		arr[i]=malloc(cs*sizeof(int));
	}
	return arr;
}
void print(int** a,int siz){
	for(int i=0;i<siz;i++){
		for(int j=0;j<siz;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}


void copy_arr(int** a,int** b,
		int ar,int ac,
		int br,int bc,
		int rsiz,int csiz){
	
	for(int i=0;i<rsiz;i++){
		for(int j=0;j<csiz;j++){
			a[i+ar][j+ac]=b[i+br][j+bc];
		}
	}
}


int** multi(int** a,int** b,int acs,int ace,int ars,int are,int bcs,int bce,int brs,int bre){
	int** c=make_arr(are-ars,bce-bcs);
	int sum;
	for(int i=0;i<(are-ars);i++){
		for(int j=0;j<(ace-acs);j++){
			sum=0;
			for(int k=0;k<(bce-bcs);k++){
				sum=sum+a[i+ars][k+acs]*b[k+brs][j+bcs];
			}
			c[i][j]=sum;
		}
	}
	return c;
}


int** add(int** a,int** b,int size){
	int** c=make_arr(size,size);
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			c[i][j]=a[i][j]+b[i][j];
		}
	}
	return c;
}




int** rec_multi(int block,int** a,int** b,
		int acs,int ace,
		int ars,int are,
		int bcs,int bce,
		int brs,int bre){
	if(block>=ace-acs){
		return multi(a,b,acs,ace,ars,are,bcs,bce,brs,bre);
	}
	int amidc=acs+(ace-acs)/2;
	int amidr=ars+(are-ars)/2;

	int bmidc=bcs+(bce-bcs)/2;
	int bmidr=brs+(bre-brs)/2;


	int size=(ace-acs)/2;

	int** ae=rec_multi(block,a,b,acs,amidc,ars,amidr,bcs,bmidc,brs,bmidr); 
	int** bg=rec_multi(block,a,b,amidc,ace,ars,amidr,bcs,bmidc,bmidr,bre);
	int** af=rec_multi(block,a,b,acs,amidc,ars,amidr,bmidc,bce,brs,bmidr);
	int** bh=rec_multi(block,a,b,amidc,ace,ars,amidr,bmidc,bce,bmidr,bre);
	int** ce=rec_multi(block,a,b,acs,amidc,amidr,are,bcs,bmidc,brs,bmidr);
	int** dg=rec_multi(block,a,b,amidc,ace,amidr,are,bcs,bmidc,bmidr,bre);
	int** cf=rec_multi(block,a,b,acs,amidc,amidr,are,bmidc,bce,brs,bmidr);
	int** dh=rec_multi(block,a,b,amidc,ace,amidr,are,bmidc,bce,bmidr,bre);

	int** c11=add(ae,bg,size);
	int** c12=add(af,bh,size);
	int** c21=add(ce,dg,size);
	int** c22=add(cf,dh,size);
	
	int** C=make_arr(size*2,size*2);

	
	copy_arr(C,c11,0,0,0,0,size,size);
	copy_arr(C,c12,0,size,0,0,size,size);
	copy_arr(C,c21,size,0,0,0,size,size);
	copy_arr(C,c22,size,size,0,0,size,size);


	free(ae);
	free(bg);
	free(af);
	free(bh);
	free(ce);
	free(dg);
	free(cf);
	free(dh);

	free(c11);
	free(c12);
	free(c21);
	free(c22);
	return C;

}





void main(){
	int n=4;
	int A[4][4] = {
	 {1, 2, 3,27},
	 {9, 10, 11,43},
	 {17, 18, 19,2},
	 {43,3,2,22}
	 };

	int B[4][4] ={
	 {2, 1, 4,83},
	 {10, 9, 12 ,23},
	 {18, 17, 20,89},
	 {33,51,62,73}
	};
	
	int** a=make_arr(n,n);
	int** b=make_arr(n,n);

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[i][j]=A[i][j];
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			b[i][j]=B[i][j];
		}
	}

	print(a,n);
	print(b,n);

	

	int** c;
	c=rec_multi(1,a,b,0,4,0,4,0,4,0,4);

	print(c,n);








	
}
