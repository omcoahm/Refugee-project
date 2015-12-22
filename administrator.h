#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <QObject>
class QDialog;
class QPushButton;
class QLineEdit;

class Administrator : public QObject
{
    Q_OBJECT
private:
    QDialog *dlg;
    QPushButton *deleteUser, *modifyUser;
    QDialog *firstD;
    QLineEdit *ID1;
    QLineEdit *pw1;
    QLineEdit *userName;
    QDialog *dlg1;

private slots:
    void Login();
    void Modify_User();
    void Delete_User();
    void Open_User();
    void Delete_User_Finally();
public:
    Administrator();
};

#endif // ADMINISTRATOR_H
