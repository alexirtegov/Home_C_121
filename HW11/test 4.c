/*
база данных студент
 */


#include <stdio.h>
#include <string.h>

enum{name_length = 50, b_length = 20};

struct initials {
	char name[name_length];
	char last[name_length];
};

struct person{
	struct initials fio;
	char sex;
	int old;
	char b_date[b_length];
	int mark;
};


int main(int argc, char **argv)
{
	struct person first = {
		{"Alexey", "Irtegov"},
		'M',
		37,
		"22.10.1987",
		5
	};
		
		struct person second = {
		{"Elisaveta", "Irtegova"},
		'F',
		30,
		"15.02.1994",
		5
	};
	
	
	
	
	
	//теперь изменим возраст
	first.old = 38;
	strcpy(first.b_date, "23.10.1987");
	
	printf("Person is %s %s, sex: %c, old is %d, b_date is %s, mark is %d\n", 
	first.fio.name, first.fio.last, first.sex, first.old, first.b_date, first.mark );
	
	printf("Person is %s %s, sex: %c, old is %d, b_date is %s, mark is %d\n", 
	second.fio.name, second.fio.last, second.sex, second.old, second.b_date, second.mark );
	
	return 0;
}
