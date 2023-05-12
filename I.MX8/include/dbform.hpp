#pragma once
#include <stdio.h>
#include "sqlite3.h"
#include <string>
#include <stdlib.h>
#include <cstddef>
#include "byte.h"

class Db
{
private:    
    sqlite3 *db;
    sqlite3_stmt *res;
    char *err_msg;

public:
    Db() {
        auto rc = sqlite3_open(":memory:", &db);
        if (rc != SQLITE_OK) { 
            fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
            sqlite3_close(db); };
    }

    ~Db() {
        sqlite3_finalize(res);
        sqlite3_close(db);
        
    }

    Db(const Db& other);
    Db(Db&& other) noexcept;

    Db& operator=(const Db& other);
    Db& operator=(Db&& other) noexcept; //RAII에 따른 5의법칙

    //getter
    sqlite3 *getDb() { return db; }
    sqlite3_stmt *getres() { return res; }
    char *geterr_msg() { return err_msg; }
    //setter
    void setDb(sqlite3 *db) { this->db = db; }
    void setres(sqlite3_stmt *res) { this->res = res; }
    void seterr_msg(char *err_msg) { this->err_msg = err_msg; }
    
};

class ID
{
private:
    std::string name;
    byte registration_order;
    byte IDNumber[10]; //c++사이트의 지침을 따라서 파일 위에 byte에 대한 선언을 따로해줌
    bool form;
    uint16_t attended_time;
    uint16_t attended_time_sig;
    uint16_t attended_time_pub;
    uint16_t total_working_hours;
    uint16_t tag_time;

public:
    ID(std::string name, byte IDNumber[10], bool form, uint16_t attended_time, uint16_t total_working_hours, uint16_t tag_time) : name(name), form(form), total_working_hours(total_working_hours), tag_time(tag_time) {
        for (int i = 0; i < 10; i++) {
            IDNumber[i] = IDNumber[i];
        }; //확실하지 않음 // 
    };

};

