#include "dbform.hpp"

void autoattend(unsigned char ID[10]) {
    Db db;
    auto rc = sqlite3_open(":memory:", &db.db); //private이라서... 
    rc = sqlite3_prepare_v2(db.db, "SELECT SQLITE_VERSION()", -1, &res, 0);
    

}