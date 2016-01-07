#include "login.h"
#include "database.h"
#include <QDebug>
Login::Login()
{

}

bool Login::is_correct(QString ID, QString pw)
{
    Database * myDB=new Database();
    if(myDB->if_username_exists(ID))
        if(pw==myDB->getPassword(ID))
            return true;

    return false;
}

