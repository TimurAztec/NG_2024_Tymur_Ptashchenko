#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qlistwidget.h"
#include <QMainWindow>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QSlider>

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

private:
    Ui::MainWindow *ui;
    QMediaPlayer *m_player;
    QAudioOutput *m_audioOutput;

private slots:
    void playPause();
    void next();
    void previous();
    void updatePosition(qint64 pos);
    void updatePositionSlider(int pos);
    void setSong();
    void updateVolume(float volume);
    void playlistItemSelected(QListWidgetItem *item);
};
#endif // MAINWINDOW_H
