#include <QApplication>
#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QPushButton>
#include <QProgressBar>
#include <QMediaPlayer>
#include <QAction>
#include <QObject>
#include <QVBoxLayout>

QMediaPlayer musicPlayer;

//TODO: Do something with spacing in between buttons and progress bar

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    QMainWindow mainWindow;
    QWidget centralWidget;
    QVBoxLayout *layout = new QVBoxLayout;
    QPushButton playButton;
    QPushButton selectButton;
    QPushButton stopButton;
    QProgressBar musicStatus;

    layout->setContentsMargins(10, 0, 10, 0);
    centralWidget.setLayout(layout);
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

    layout->addWidget(&musicStatus);
    layout->addWidget(&playButton);
    layout->addWidget(&stopButton);
    layout->addWidget(&selectButton);
    mainWindow.resize(500, 300);
    mainWindow.show();
    return app.exec();
}



