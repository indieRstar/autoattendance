#include "dbform.hpp"

// void autoattend(unsigned char ID[10]) {
//     // Db db;
//     // auto dbptr = db.getDb();
//     // auto resptr = db.getres();
//     // auto rc = sqlite3_open(":memory:", &dbptr);
//     // rc = sqlite3_prepare_v2(dbptr, "SELECT SQLITE_VERSION()", -1, &resptr, 0);

//     // if (rc != SQLITE_OK) { fprintf(stderr, "Failed to fetch data: %s\n", sqlite3_errmsg(dbptr)); sqlite3_close(dbptr);};

//     // rc = sqlite3_step(resptr);


// }

// void autoregister() {
//     Db db;
//     auto dbptr = db.getDb();
//     auto resptr = db.getres();

//     char *sql = "DROP TABLE IF EXISTS Employees;"
//                 "CREATE TABLE Employees(Id INT, Name TEXT, Working_hours INT);"
//                 "INSERT INTO Employees VALUES();";
// }