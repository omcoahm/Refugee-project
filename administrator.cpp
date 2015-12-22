#include "administrator.h"
#include "database.h"
#include "editprofile.h"
#include "design.h"
#include <QPushButton>
#include <QDialog>
#include <QGridLayout>
#include <QDebug>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>

Administrator::Administrator()
{
    firstD=new QDialog();
    QLabel *ID=new QLabel("Username: ");
    QLabel *pw=new QLabel("Password:");
    firstD->setWindowTitle("Administrator");
    ID1=new QLineEdit();
    pw1=new QLineEdit();
    ID1->setFixedWidth(220);
    pw1->setFixedWidth(220);
    pw1->setEchoMode(QLineEdit::Password);

    QPushButton *cancel=new QPushButton("");
    QPushButton *ok=new QPushButton("");

    Design::setButton(cancel,125,30,":/Buttons/images/buttons/cancel.jpg");
    Design::setButton(ok,125,30,":/Buttons/images/buttons/ok.jpg");


    QGridLayout *lyt=new QGridLayout();
    lyt->addWidget(ID,0,1);
    lyt->addWidget(ID1,0,2);
    lyt->addWidget(pw,1,1);
    lyt->addWidget(pw1,1,2);
    lyt->addWidget(new QLabel("    "),0,0);
    lyt->addWidget(new QLabel("    "),1,0);

    QHBoxLayout *lyt1=new QHBoxLayout();
    lyt1->addWidget(ok);
    lyt1->addWidget(cancel);
    QVBoxLayout *mainlyt=new QVBoxLayout();
    mainlyt->addLayout(lyt);
    mainlyt->addLayout(lyt1);
    firstD->setLayout(mainlyt);
    firstD->setFixedSize(400,200);
    firstD->show();

    connect(cancel,SIGNAL(clicked(bool)),firstD,SLOT(close()));
    connect(ok,SIGNAL(clicked(bool)),this,SLOT(Login()));



}

void Administrator::Login()
{
    Database *myDB=new Database();
    if(myDB->Is_Administrator(ID1->text(),pw1->text()))
    {
        firstD->close();
        dlg=new QDialog();
        dlg->setWindowTitle("Administrator");
        modifyUser=new QPushButton("");
        deleteUser=new QPushButton("");
        QPushButton *done=new QPushButton("");

        QGridLayout *mainLayout=new QGridLayout();

        mainLayout->addWidget(modifyUser,0,0);
        mainLayout->addWidget(deleteUser,1,0);

        QHBoxLayout *lyt=new QHBoxLayout();
        lyt->addWidget(done);

        QVBoxLayout *lyt3=new QVBoxLayout();
        lyt3->addLayout(mainLayout);
        lyt3->addLayout(lyt);
        dlg->setLayout(lyt3);
        dlg->setFixedSize(300,200);
        dlg->show();

        connect(done,SIGNAL(clicked(bool)),dlg,SLOT(close()));
        connect(modifyUser,SIGNAL(clicked(bool)),this,SLOT(Modify_User()));
        connect(deleteUser,SIGNAL(clicked(bool)),this,SLOT(Delete_User()));

        Design::setButton(done,125,30,":/Buttons/images/buttons/done.jpg");
        Design::setButton(modifyUser,125,30,":/Buttons/images/buttons/mod.jpg");
        Design::setButton(deleteUser,125,30,":/Buttons/images/buttons/del.jpg");


    }else
        QMessageBox::warning(NULL, "Wrong input","This incident will be reported!");
}

void Administrator::Modify_User()
{
    qDebug()<<" in function modify user";
    QLabel * text=new QLabel("Please enter username of the person to be modified: ");
    userName=new QLineEdit();

    QPushButton *ok=new QPushButton("");
    QPushButton *cancelB=new QPushButton("");
    Design::setButton(ok,125,30,":/Buttons/images/buttons/mod.jpg");
    Design::setButton(cancelB,125,30,":/Buttons/images/buttons/cancel.jpg");
    QDialog *dlg1=new QDialog();
    dlg1->setWindowTitle("Administrator");
    QGridLayout *lyt=new QGridLayout();
    lyt->addWidget(text,0,0);
    lyt->addWidget(userName,0,1);
    lyt->addWidget(ok,1,0);
    lyt->addWidget(cancelB,1,1);
    dlg1->setLayout(lyt);

    dlg1->show();

    connect(ok,SIGNAL(clicked(bool)),this,SLOT(Open_User()));
    connect(cancelB,SIGNAL(clicked(bool)),dlg1,SLOT(close()));
}

void Administrator::Open_User()
{
    Database *myDB=new Database();
    if(myDB->if_username_exists(userName->text()))
    {
        EditProfile *modify=new EditProfile(userName->text());
    }
    else
        QMessageBox::information(NULL,"No user found","No user found with specified username!");
}

void Administrator::Delete_User()
{
    qDebug()<<" in function delete user";
    QLabel * text=new QLabel("Please enter username of the person to be deleted: ");
    userName=new QLineEdit();

    QPushButton *ok=new QPushButton("");
    QPushButton *cancelB=new QPushButton("");
    Design::setButton(ok,125,30,":/Buttons/images/buttons/del.jpg");
    Design::setButton(cancelB,125,30,":/Buttons/images/buttons/cancel.jpg");
    dlg1=new QDialog();
    dlg1->setWindowTitle("Administrator");
    QGridLayout *lyt=new QGridLayout();
    lyt->addWidget(text,0,0);
    lyt->addWidget(userName,0,1);
    lyt->addWidget(ok,1,0);
    lyt->addWidget(cancelB,1,1);
    dlg1->setLayout(lyt);

    dlg1->show();

    connect(ok,SIGNAL(clicked(bool)),this,SLOT(Delete_User_Finally()));
    connect(cancelB,SIGNAL(clicked(bool)),dlg1,SLOT(close()));
}

void Administrator::Delete_User_Finally()
{
    Database *myDB=new Database();
    if(myDB->if_username_exists(userName->text()))
    {
        myDB->Delete_User(userName->text());
        QMessageBox::information(NULL,"Success","User successfuly removed!");
        dlg1->close();
    }
    else
        QMessageBox::information(NULL,"No user found","No user found with specified username!");

}
