#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void switchState(QAbstractButton *button);
    void keyTextChanged(const QString &key);

private:
    Ui::MainWindow *ui;
    QString key;
    bool encodeState;
    QString encode(QString text, QString key);
    QString decode(QString text, QString key);
    void processChange();
};
#endif // MAINWINDOW_H
