/*
 * temp_api.h
Все прототипы функций вынести в отдельный файл temp_api.h
 */

#ifndef TEMP_API_H
#define TEMP_API_H

struct temperature {
	
        int year;   // dddd (4 цифры)
        int month;  // mm (2 цифры)
        int day;    // dd (2 цифры)
        int hour;   // hh (2 цифры)
        int minute; // mm (2 цифры)
        int temperature; // от -99 до 99
	
};

void AddRecord(struct temperature *date, int count, int year, int month, int day, int hour, int minute, int temperature);
				
int addinfo(struct temperature *date);

void monthly_stats(struct temperature *date, int count, int year);

void yearly_stats(struct temperature *date, int count, int year); 

#endif
