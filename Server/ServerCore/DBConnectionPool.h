#pragma once
#include "DBConnection.h"

/*----------------------
*	DBConnectionPool
-----------------------*/

// �����ͺ��̽� Ŀ�ؼ� Ǯ�� ����ϴ� �ֵ� ������ ����
// -> �����ͺ��̽� ���� ������ ���� ������ ����Ű�� ����
// Ŀ�ؼ� Ǯ�� �̸� ������ �����ΰ� �����Ͽ�, ������ ���� ���� �� �߻��ϴ� ������带 �ٿ� ������ �����ش�.

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

