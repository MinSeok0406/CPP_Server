#pragma once
#include "DBConnection.h"

/*----------------------
*	DBConnectionPool
-----------------------*/

// 데이터베이스 커넥션 풀을 사용하는 주된 이유는 무엇
// -> 데이터베이스 연결 재사용을 통해 성능을 향상시키기 위해
// 커넥션 풀은 미리 연결을 만들어두고 재사용하여, 연결을 새로 만들 때 발생하는 오버헤드를 줄여 성능을 높여준다.

class DBConnectionPool
{
public:
	DBConnectionPool();
	~DBConnectionPool();

	bool					Connect(int32 connectionCount, const WCHAR* connectionString);
	void					Clear();

	DBConnection*			Pop();
	void					Push(DBConnection* connection);

private:
	USE_LOCK;
	SQLHENV					_environment = SQL_NULL_HANDLE;
	Vector<DBConnection*>	_connections;
};

