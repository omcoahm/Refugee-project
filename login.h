#ifndef LOGIN_H
#define LOGIN_H
#include <QString>

class Login
{
public:
    Login( );
    bool is_correct(QString ID,QString pw);
};

#endif // LOGIN_H
