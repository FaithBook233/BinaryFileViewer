/*
	**������������������ļ���λ���� 
	**�������Ȩ��FaithBook-_- 
*/ 

#include<stdio.h>
#include<windows.h>

char toChar(int i){//��0-15֮�����������󷵻�ʮ�������ַ� 
	if(i<10)
		return i+'0';
	else return i+'A'-10;
}

int main(){
	char *filename = (char*)malloc (sizeof(char)*8); 
	puts("Easy Byte Viewer Powered By FaithBook-_-");
	puts("\n�뽫�ļ���˳��������ͬһĿ¼��");
	printf("\n�����ļ�ȫ��[�ļ���+��չ��]:  ");
	gets(filename);
	printf("\n���ݴ�����..."); 
	FILE *fp,*cp;
	if((fp = fopen(filename,"rb")) == NULL){
		printf("No Such File!!!\n");
		system("pause");
		return -1;
	}
		
	cp = fopen("�������.txt","w");
	fputs("Easy Byte Viewer Powered By FaithBook-_-\n\n",cp);
	fputs(filename,cp);
	fputs(" ���������\n",cp); 
	
	long i = 0;
	int j=0,k,n,str[17];
	
	while((k = fgetc(fp) )!= EOF){
		if(!(i%16)){
			//�����ַ�������
			if(i){
				fputs("\t",cp);
				for(n = 0;n<j;n++){
					if(str[n]>=32 && str[n]<=126 )
						fputc(str[n],cp);
					else fputc('.',cp);
				}
				j = 0;
			}
			fputs("\n��[",cp);
			
			fputc((i/16+1)/10000000%10 + '0',cp);
			fputc((i/16+1)/1000000%10 + '0',cp);
			fputc((i/16+1)/100000%10 + '0',cp);
			fputc((i/16+1)/10000%10 + '0',cp);
			fputc((i/16+1)/1000%10 + '0',cp);
			fputc((i/16+1)/100%10 + '0',cp);
			fputc((i/16+1)/10%10 + '0',cp);
			fputc((i/16+1)%10 + '0',cp);
			fputs("]��  :  ",cp);
		}
		
		fputc(toChar(k/16),cp); 
		fputc(toChar(k%16),cp);
		str[j++] = k; 
		
		if(!(i%2-1))
			fputc(' ',cp);
		i++;
	}
	//��֤���һ�в���ʱ�ĸ�ʽ 
	for(n = 0;n<16-j;n++){
		fputs("  ",cp);
	}
	for(n = 0;n<j;n++){
		fputs(" ",cp);
	}
	fputc('\t',cp);
	for(n = 0;n<j;n++){
		if(str[n]>=32 && str[n]<=126 )
			fputc(str[n],cp);
		else fputc('.',cp);
	}
	
	fputs("\n\n",cp);
	fputs(filename,cp);
	fputs(" �������",cp); 
	fclose(fp);
	fclose(cp);
	printf("\n\n���ݴ������!!!\n\n�������ļ��ѱ���Ϊ���������.txt��\n\n���򼴽��رմ�ҳ��򿪷������\n");
	Sleep(2000);
	system("start �������.txt");
	return 0;
}
