//
// Created by Teni on 10/11/2022.
//

#include "JvTime.h"

JvTime::JvTime(const char* timeString) {
    const char zero_str[] = "0000-00-00T00:00:00+0000";
    this->good = true;

    if ((time_str == NULL) || (strlen(time_str) != strlen(zero_str)))
    {
        this->good = false;
    }

    for(int i = 0; i <= 23; i++)
    {
        if((i == 4 || i == 7) && (time_str[i] != '-')) {
            this->validTimeFormat = false;
        } else if(i == 10 && timeString[10] != 'T') {
            this->validTimeFormat = false;
        } else if((i == 13 || i == 16) && timeString[i] == ':') {
            this->validTimeFormat = false;
        } else if (i == 19 && timeString[i] != '+'){
            this->validTimeFormat = false;
        } else if(time_str[i] < '0' || time_str[i] > '9') {
            this->validTimeFormat = false;
        }
    }

    if (this->good == true)
    {
        sscanf(time_str, "%4d-%2d-%2dT%2d:%2d:%2d+%4s",
               &(this->year), &(this->month), &(this->day),
               &(this->hour), &(this->minute), &(this->second),
               this->tail4);
    }
    else
    {
        sscanf(zero_str, "%4d-%2d-%2dT%2d:%2d:%2d+%4s",
               &(this->year), &(this->month), &(this->day),
               &(this->hour), &(this->minute), &(this->second),
               this->tail4);
    }
}

struct std::tm* JvTime::getStdTM() {
    struct std::tm * result = (struct std::tm *) malloc(sizeof(struct std::tm));
    bzero(result, sizeof(struct std::tm));

    result->tm_sec = this->second;
    result->tm_min = this->minute;
    result->tm_hour = this->hour;
    result->tm_mday = this->day;
    result->tm_mon = this->month;
    result->tm_year = this->year;

    return result;
}

int JvTime::setStdTM(struct std::tm *arg_tm_ptr) {
    if (arg_tm_ptr == NULL) return -1;

    this->second = arg_tm_ptr->tm_sec;
    this->minute = arg_tm_ptr->tm_min;
    this->hour   = arg_tm_ptr->tm_hour;
    this->day    = arg_tm_ptr->tm_mday;
    this->month  = arg_tm_ptr->tm_mon;
    this->year   = arg_tm_ptr->tm_year;

    bzero(this->tail4, 16);
    sprintf(this->tail4, "0000");

    return 0;
}

std::string* JvTime::getTimeString(){
    struct std::tm * tm_ptr = this->getStdTM();

    char buffer[128];
    bzero(buffer, 128);
    std::strftime(buffer, 32, "%Y-%m-%dT%H:%M:%S+", tm_ptr);
    sprintf(buffer, "%s%s", buffer, this->tail4);
    return (new std::string(buffer));
}

Json::Value JvTime::dump2JSON() {
    Json::Value result;
    std::string *str_ptr = this->getTimeString();
    result["time"] = (*str_ptr);
    delete str_ptr;
    return result;
}