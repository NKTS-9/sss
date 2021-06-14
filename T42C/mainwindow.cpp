
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_db = QSqlDatabase::addDatabase("QSQLITE"); //соединение объекта базы данных
                                    // с СУБД
    m_db.setDatabaseName("myDB7");  //определение имени базы данных
    query = new QSqlQuery(m_db); // создание объекта для запроса
    if(!m_db.open()) // проверка на ошибку при открытии или создании базы данных
        throw "can't open database";
    if(!m_db.tables().contains("Design")) // если в базе не существует таблица  Person,
        { //то создание таблицы  Person и заполнение данными
            query->clear(); // очистка запроса
      query->exec("CREATE TABLE Design(ID INTEGER PRIMARY KEY, Name VARCHAR, Style VARCHAR, Price INTEGER);");  // исполнение запроса на добавление записи
            query->clear();
            query->exec("INSERT INTO Design (ID,Name,Style,Price) VALUES (1,'picture','classic',15000);");
            query->clear();
            query->exec("INSERT INTO Design (ID,Name,Style,Price) VALUES (2, 'vasa' , 'borocco' ,4000);");
            query->clear();
            query->exec("INSERT INTO Design (ID,Name,Style,Price) VALUES (3, 'picture' , 'borocco' ,1000);");
            query->clear();
            query->exec("INSERT INTO Design (ID,Name,Style,Price) VALUES (4, 'bubs' , 'classic' ,40000);");
    }
    model = new QSqlTableModel(this,m_db); // создание
                              // редактируемой модели базы данных
    model->setTable("Design"); // создание модели таблицы  Person

    model->select(); // заполнение модели данными
    model->setEditStrategy(QSqlTableModel::OnFieldChange); // выбор стратегии
                    //  сохранения изменений в базе данных
                    //- сохранение происходит при переходе к другому полю
    ui->tableView->setModel(model); // соединение модели
                    // и ее табличного представления в форме
}

MainWindow::~MainWindow()
{
    delete ui;
    delete query;
    delete model;
}



void MainWindow::on_pushButton_ADD_clicked()
{
    if(ui->lineEdit_ID->text().isEmpty()||ui->lineEdit_N->text().isEmpty()||ui->lineEdit_S->text().isEmpty()||ui->lineEdit_P->text().isEmpty())
            return;

        QString id = ui->lineEdit_ID->text();
        QString name = ui->lineEdit_N->text();
        QString style = ui->lineEdit_S->text();
        QString price = ui->lineEdit_P->text();

        QString buf = tr("INSERT INTO Design (ID,Name,Style,Price) VALUES (")+id+tr(",'")+name+tr("','")+style+tr("',")+price+tr(");");
        query->clear();
        query->exec(buf);
        model->select();
}

void MainWindow::on_pushButton_REM_clicked()
{
    if(ui->lineEdit_ID->text().isEmpty())
           return;
       QString id = ui->lineEdit_ID2->text();
       query->clear();
       query->exec(tr("DELETE FROM Design WHERE ID=")+id);
       model->select();

}

void MainWindow::on_pushButton_ALL_clicked()
{
    model->setFilter("");
        model->select();
        ui->tableView->setModel(model);
        QMessageBox::information(0,tr("Action"),tr("All data"));// Сообщение, не обязательно
}

void MainWindow::on_pushButton_f1_clicked()
{
    model->setFilter("Price<20000");
       model->select();
       ui->tableView->setModel(model);
       QMessageBox::information(0,"Action","Filter"); //Сообщение, не обязательно

}

void MainWindow::on_pushButton_f2_clicked()
{
    model->setFilter("Price>20000");
       model->select();
       ui->tableView->setModel(model);

}

void MainWindow::on_pushButton_UPDATE_clicked()
{
    if(ui->lineEdit_ID->text().isEmpty()||ui->lineEdit_N->text().isEmpty()||ui->lineEdit_S->text().isEmpty()||ui->lineEdit_P->text().isEmpty())
            return;

        QString id = ui->lineEdit_ID->text();
        QString name = ui->lineEdit_N->text();
        QString style = ui->lineEdit_S->text();
        QString price = ui->lineEdit_P->text();

        QString buf = tr("UPDATE Design SET name='")+name+tr("' WHERE id =")+id+tr(";");
        query->clear();
        query->exec(buf);
         buf = tr("UPDATE Design SET style='")+style+tr("' WHERE id =")+id+tr(";");
        query->clear();
        query->exec(buf);
         buf = tr("UPDATE Design SET price=")+price+tr(" WHERE id =")+id+tr(";");
        query->clear();
        query->exec(buf);
        model->select();
}
