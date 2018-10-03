#include <stdio.h>

int main(){
FILE *fp = fopen("teste.c", "r");
char  leitor;
for(int i = 0 ; i<10; i++){
	while( 1 ){
		leitor = fgetc(fp);
		printf("%c", leitor);
		if ( leitor == -1 || leitor == 'n' )
			break;
	}
	if ( leitor == -1 )
		break;
	i++;
}
fclose(fp);
return 0; }
