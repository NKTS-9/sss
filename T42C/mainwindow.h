#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_ADD_clicked();

    void on_pushButton_UPDATE_clicked();

    void on_pushButton_REM_clicked();

    void on_pushButton_ALL_clicked();

    void on_pushButton_f1_clicked();

    void on_pushButton_f2_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase m_db; // объект базы данных
       QSqlQuery* query; // указатель на запрос
       QSqlTableModel* model; // указатель на таблицу данных в приложении

};

#endif // MAINWINDOW_H
