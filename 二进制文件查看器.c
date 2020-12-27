/*
	**程序用于输出二进制文件的位数据 
	**软件所有权归FaithBook-_- 
*/ 

#include<stdio.h>
#include<windows.h>

char toChar(int i){//将0-15之间的整数处理后返回十六进制字符 
	if(i<10)
		return i+'0';
	else return i+'A'-10;
}

int main(){
	char *filename = (char*)malloc (sizeof(char)*8); 
	puts("Easy Byte Viewer Powered By FaithBook-_-");
	puts("\n请将文件与此程序放置于同一目录下");
	printf("\n输入文件全名[文件名+扩展名]:  ");
	gets(filename);
	printf("\n数据处理中..."); 
	FILE *fp,*cp;
	if((fp = fopen(filename,"rb")) == NULL){
		printf("No Such File!!!\n");
		system("pause");
		return -1;
	}
		
	cp = fopen("分析结果.txt","w");
	fputs("Easy Byte Viewer Powered By FaithBook-_-\n\n",cp);
	fputs(filename,cp);
	fputs(" 分析结果：\n",cp); 
	
	long i = 0;
	int j=0,k,n,str[17];
	
	while((k = fgetc(fp) )!= EOF){
		if(!(i%16)){
			//输入字符并换行
			if(i){
				fputs("\t",cp);
				for(n = 0;n<j;n++){
					if(str[n]>=32 && str[n]<=126 )
						fputc(str[n],cp);
					else fputc('.',cp);
				}
				j = 0;
			}
			fputs("\n第[",cp);
			
			fputc((i/16+1)/10000000%10 + '0',cp);
			fputc((i/16+1)/1000000%10 + '0',cp);
			fputc((i/16+1)/100000%10 + '0',cp);
			fputc((i/16+1)/10000%10 + '0',cp);
			fputc((i/16+1)/1000%10 + '0',cp);
			fputc((i/16+1)/100%10 + '0',cp);
			fputc((i/16+1)/10%10 + '0',cp);
			fputc((i/16+1)%10 + '0',cp);
			fputs("]行  :  ",cp);
		}
		
		fputc(toChar(k/16),cp); 
		fputc(toChar(k%16),cp);
		str[j++] = k; 
		
		if(!(i%2-1))
			fputc(' ',cp);
		i++;
	}
	//保证最后一行不足时的格式 
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
	fputs(" 分析结果",cp); 
	fclose(fp);
	fclose(cp);
	printf("\n\n数据处理完成!!!\n\n处理后的文件已保存为《分析结果.txt》\n\n程序即将关闭此页面打开分析结果\n");
	Sleep(2000);
	system("start 分析结果.txt");
	return 0;
}
