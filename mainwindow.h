#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <windows.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_lineEdit_size_editingFinished();

    void on_pushButton_set_size_10_clicked();

    void on_pushButton_set_size_200_clicked();

    void on_pushButton_set_size_random_clicked();

    void on_pushButton_bubble_clicked();

    void on_pushButton_gnome_clicked();

    void on_pushButton_quick_clicked();

    void on_pushButton_hair_clicked();

    void on_pushButton_makaka_clicked();

    void on_tableWidget_itemChanged(QTableWidgetItem *item);

private:
    Ui::MainWindow *ui;
    int array[200];
    int size = 0;
    int swipes = 0;
    int iterations = 0;

    bool check();
    bool check_numbers();

    void setTable(int size);
    void table_function( std::pair<int, int> (*function) (int size, int *array_prt));
};
#endif // MAINWINDOW_H
