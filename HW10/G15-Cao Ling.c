/*
G15-Cao Ling

В файле input.txt дано предложение. Необходимо заменить все имена «Cao» на «Ling» и записать результат в файл output.txt.

Input format
Строка из английский букв, знаков препинания и пробелов. Не более 1000 символов.

Output format
Строка из английский букв, знаков препинания и пробелов.


Input in input.txt
Cao, Cao, Cao and Cao!!!

Output in output.txt
Ling, Ling, Ling and Ling!!!


Нужно прочитать определенный тип данных (числа) -> fscanf. если в файле записано 192 168.5 Data, вы можете извлечь это одной строкой: fscanf(file1, "%d %f %s", &a, &b, str).
Нужно прочитать текстовую строку целиком -> fgets.   fgets(buffer, SIZE, file1) - Читаем строку целиком (до \n или до SIZE-1 символов)
Нужно анализировать каждый символ поштучно -> fgetc.   while((c = fgetc(file1)) != EOF && count != SIZE-1)
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	FILE *in = fopen("input.txt", "r");
	FILE *out = fopen("output.txt", "w");
	if(in==NULL){
		perror("input.txt");
		if(out !=NULL) fclose(out);
		return 1;
	}
	if(out==NULL){
		perror("output.txt");
		fclose(in);
		return 1;
	}

	//читаем input.txt через fgets в buffer[1001]
	char buffer[1001];
	if(fgets(buffer, 1001, in) == NULL){
		printf("file read error");
		fclose(in);
		fclose(out);
		return 1;		
	}
	
	//теперь читаем из buffer[] в result[], когда встерити Cao в buffer в result кладем Ling
	char result [1001];
	int res = 0;
	
	for(int i = 0; buffer[i]!='\0'; i++){
		
		if(buffer[i] == 'C' && buffer[i+1] == 'a' && buffer [i+2] == 'o'){
			result[res++] = 'L';
			result[res++] = 'i';
			result[res++] = 'n';
			result[res++] = 'g';
			i+=2;
			continue; 
			
		} else {
		result[res++] = buffer[i];
		}
	}
	result[res] = '\0';
	fprintf(out, "%s", result);
    fclose(in);
    fclose(out);

	
	return 0;
}
