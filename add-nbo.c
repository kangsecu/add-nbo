#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <netinet/in.h>

int main(int argc,char** argv){
	if(argc!=3)
		return -1;
	FILE *fp1, *fp2;
	uint32_t a,b;
	fp1 = fopen(argv[1],"rb");
	fp2 = fopen(argv[2],"rb");
	fread(&a , sizeof(uint32_t), 1, fp1);
	fread(&b , sizeof(uint32_t), 1, fp2);

	uint32_t num1 = ntohl(a);
	uint32_t num2 = ntohl(b);
	uint32_t sum =  num1 +num2;

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",num1,num1,num2,num2,sum,sum);

	fclose(fp1);
	fclose(fp2);
	return 0;
}
