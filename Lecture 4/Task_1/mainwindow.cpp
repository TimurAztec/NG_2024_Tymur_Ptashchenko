#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_player = new QMediaPlayer(this);
    m_audioOutput = new QAudioOutput(this);

    m_player->setAudioOutput(m_audioOutput);
    ui->s_volume->setValue(m_audioOutput->volume());
    ui->p_position->setValue(0);
    ui->s_volume->setRange(0, 100);

    connect (ui->b_select, &QPushButton::clicked, this, &MainWindow::setSong);
    connect (ui->s_volume, &QSlider::valueChanged, this, &MainWindow::updateVolume);
    connect (ui->s_position, &QSlider::valueChanged, this, &MainWindow::updatePositionSlider);
    connect (ui->b_playPause, &QPushButton::clicked, this, &MainWindow::playPause);
    connect (m_player, &QMediaPlayer::positionChanged, this, &MainWindow::updatePosition);
    connect (ui->ls_listWidget, &QListWidget::itemDoubleClicked, this, &MainWindow::playlistItemSelected);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::playPause()
{
    if (m_player->isPlaying()) {
        m_player->pause();
        ui->b_playPause->setText(">");
    } else {
        m_player->play();
        ui->b_playPause->setText("||");
    }
}

void MainWindow::next()
{

}

void MainWindow::previous()
{

}

void MainWindow::updatePosition(qint64 pos)
{
    ui->p_position->setValue(pos / (m_player->duration() / 100));
}

void MainWindow::setSong()
{
    QString path = QFileDialog::getOpenFileName(this, "Chto budem igrat'?", QDir::homePath(), "*.mp3");
    ui->l_songName->setText(path);
    ui->ls_listWidget->addItem(path);
    m_player->setSource(QUrl::fromLocalFile(path));
    ui->b_playPause->setText("||");
}

void MainWindow::playlistItemSelected(QListWidgetItem *item)
{
    QString path = item->text();
    qDebug() << item;
    ui->l_songName->setText(path);
    m_player->setSource(QUrl::fromLocalFile(path));
    ui->b_playPause->setText("||");
}

void MainWindow::updateVolume(float volume)
{
    m_audioOutput->setVolume(volume/100);
}

void MainWindow::updatePositionSlider(int pos)
{
    if (m_player->LoadedMedia) {
        m_player->pause();
        const int duration = m_player->duration();
        m_player->setPosition(static_cast<qint64>((duration/100)*pos));
        m_player->play();
    }
}
