#include <QApplication>
#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QPushButton>
#include <QProgressBar>
#include <QMediaPlayer>
#include <QAction>
#include <QObject>

QMediaPlayer musicPlayer;

//TODO: GUI Layout needs refractoring and redesign

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    QMainWindow mainWindow;
    QWidget centralWidget;
    QGridLayout layout;
    QPushButton playButton;
    QPushButton selectButton;
    QPushButton stopButton;
    QProgressBar musicStatus;

    centralWidget.setLayout(&layout);
    mainWindow.setCentralWidget(&centralWidget);

    playButton.setText("Play");
    stopButton.setText("Stop");
    selectButton.setText("Select track");

    musicPlayer.setMedia(QUrl::fromLocalFile("/home/kociarz/Downloads/music.mp3"));

    QObject::connect(&playButton, &QPushButton::clicked, &mainWindow, [&](){
        musicPlayer.play();
    });

    QObject::connect(&stopButton, &QPushButton::clicked, &mainWindow, [&](){
        musicPlayer.stop();
    });

    QObject::connect(&selectButton, &QPushButton::clicked, &mainWindow, [&](){

    });

    layout.addWidget(&musicStatus, 1, 0);
    layout.addWidget(&playButton, 0, 0);
    layout.addWidget(&stopButton, 0, 1);
    layout.addWidget(&selectButton, 0, 2);
    mainWindow.resize(500, 800);
    mainWindow.show();
    return app.exec();
}



