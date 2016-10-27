//
//  SQLiteDatabase.h
//
//  Created by  on 12-1-11.
//  Copyright (c) 2012 HJC. All rights reserved.
//  E-mail: hjcapple@gmail.com
//
//********************
// omitted uSleep() related parts by Xianzhong Zhu on Jan. 13, 2013
//********************

#ifndef _SQLITEDATABASE_H_
#define _SQLITEDATABASE_H_


#include <string>
#include <vector>
#include <map>

#include "SQLiteResultSet.h"
#include "SQLiteValue.h"


class SQLiteDatabase
{
public:
    SQLiteDatabase();
    ~SQLiteDatabase();
    
    static bool isThreadSafe();
    
	bool open(const char* dbPath);
    
    //commented on 2014-9-17 because the encrption part has not been passed under Xcode Gcc 4.2 builder.
	//bool openEncrypt(const char* dbPath, const void* password, int lenPass);
	//bool openAndChangePassword(const char* dbPath, const void* oldPassword, int lenOldPass,const void* newPassword, int lenNewPass);
    
    bool close();
    
    bool cacheSQL(const char* sql);
    bool uncacheSQL(const char* sql);
    
    bool exec(const char* sql);
    bool exec(const char* sql, const SQLiteValue& v0);
    bool exec(const char* sql, const SQLiteValue& v0, const SQLiteValue& v1);
    bool exec(const char* sql, const SQLiteValue* values, int length); 
    
    SQLiteResultSet* query(const char* sql);
    SQLiteResultSet* query(const char* sql, const SQLiteValue& v0);
    SQLiteResultSet* query(const char* sql, const SQLiteValue& v0, const SQLiteValue& v1);
    SQLiteResultSet* query(const char* sql, const SQLiteValue* values, int length);
        
    bool isTableExists(const char* name) const;
 
private:
    SQLiteDatabase(const SQLiteDatabase& rhs);
    SQLiteDatabase& operator = (const SQLiteDatabase& rhs);
    
    bool databaseExists() const;
    void closeOpenedResultSets();
    void uncacheCachesResultSets();
    void resultSetDidfinalize(SQLiteResultSet* resultSet);
    int  numberOfRetries() const;
    void waitForRetry();
    
    SQLiteResultSet* findClosedCache(const char* sql);
    sqlite3_stmt* stmtPrepare(const char* sql);
    
    void bindValue(const SQLiteValue& value, int idx, sqlite3_stmt* stmt);
    void bindValues(const SQLiteValue* values, int length, sqlite3_stmt* stmt);
    
private:
    friend class SQLiteResultSet;    
    sqlite3*                                _db;
    std::string                             _dbPath;
    int                                     _numberOfRetries;
    std::vector<SQLiteResultSet*>           _openResultSets;
    std::map<std::string, SQLiteResultSet*> _cacheResultSets;
    SQLiteResultSet                         _reuseResultSet;
};

inline bool SQLiteDatabase::isThreadSafe()
{
    return sqlite3_threadsafe();
}

inline bool SQLiteDatabase::databaseExists() const 
{   
    return _db != NULL;    
}

inline int SQLiteDatabase::numberOfRetries() const     
{ 
    return _numberOfRetries;  
}

inline void SQLiteDatabase::waitForRetry()              
{ 
	//sqlite3_sleep(0.02);//milliseconds
	//do nothing
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
//	usleep(20); // microseconds             
//#endif
//
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
//Sleep(20*0.001);               
//#endif
//
}

#endif
