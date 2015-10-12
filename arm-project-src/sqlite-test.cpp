#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
// #include <sys.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
   int i;
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

sqlite3* open_database(char *name)
{
   sqlite3 *db;
   //char *zErrMsg = 0;
   int rc;

   rc = sqlite3_open(name, &db);

   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(0);
   }else{
      fprintf(stderr, "Opened database successfully\n");
   }
   // sqlite3_close(db);
   return db;
}

bool create_table(sqlite3 *db)
{
   // sqlite3 *db;
   char *zErrMsg = 0;
   int  rc;
   char *sql;

   // Create SQL statement
   sql = "CREATE TABLE THERMOMETER ("  \
         "ID INT PRIMARY KEY     NOT NULL," \
         "RECORDEDTIME TIMESTAMP NOT NULL DEFAULT (datetime('now', 'localtime')),"\
         "CITY           TEXT    NOT NULL," \
         "TEMPERATURE    REAL );";

   // Execute SQL statement
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   if( rc != SQLITE_OK ){
         fprintf(stderr, "SQL error: %s\n", zErrMsg);
         sqlite3_free(zErrMsg);
         return false;
   }else{
         fprintf(stdout, "Table created successfully\n");
   }
   sqlite3_close(db);
   return true;
}

bool select_data(sqlite3 *db)
{
   //sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;
   const char* data = "Callback function called";

   /* Create SQL statement */
   sql = "SELECT * from THERMOMETER";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else{
      fprintf(stdout, "Operation done successfully\n");
   }
   sqlite3_close(db);
   return true;
}

bool insert_data(sqlite3 *db)
{
   //sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;

   /* Create SQL statement */
   sql = "INSERT INTO THERMOMETER (ID,CITY,TEMPERATURE)" \
         "VALUES (1, 'Beijing',  27.0 );";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      return false;
   }else{
      fprintf(stdout, "Records created successfully\n");
   }
   sqlite3_close(db);
   return true;
}

int main(){
   char *db_name = "test.db";
   sqlite3 *db;

   db = open_database(db_name);
   create_table(db);
   insert_data(db);
   select_data(db);
   return 0;
}

