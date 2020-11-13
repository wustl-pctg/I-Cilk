#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv){
  char buf[128]="";
  FILE* f=fopen(argv[1],"r");
  FILE* out=fopen("sites.txt","wa");
  while(fgets(buf, 128, f)){
    int index=0;
    while(buf[index]!=','){
      index++;
    }
    index++;
    int index2=0;
    while(buf[index2+5]){
	index2++;
      }
    buf[index2+4]='/';
      if(!strncmp(buf+index2,".com",4)){
    fprintf(out, "http://www.%s\n", buf+index);
    fprintf(out, "https://www.%s\n", buf+index);
      }
  }
  fclose(f);
  fclose(out);
}
