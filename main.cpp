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


//TODO: Do something with spacing in between buttons and progress bar

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    QMediaPlayer musicPlayer;
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

    musicStatus.setMaximum(1000000);

    musicPlayer.setMedia(QUrl::fromLocalFile("/home/kociarz/Downloads/music.mp3"));

    QObject::connect(&playButton, &QPushButton::clicked, &mainWindow, [&](){
        musicPlayer.play();
    });

    QObject::connect(&stopButton, &QPushButton::clicked, &mainWindow, [&](){
        musicPlayer.stop();
    });

    QObject::connect(&selectButton, &QPushButton::clicked, &mainWindow, [&  ](){

    });

    QObject::connect(&musicPlayer, &QMediaPlayer::durationChanged, &musicPlayer, [&](qint64 duration){
        musicStatus.setMaximum(duration);
        qDebug() <<  "Maximum duration of the song is: " << duration;
    });


    QObject::connect(&musicPlayer, &QMediaPlayer::positionChanged, &musicPlayer, [&](qint64 position){
        musicStatus.setValue(position);
        qDebug() << "Position:" << position;
    });

    QObject::connect(&musicPlayer, &QMediaPlayer::mediaStatusChanged, &musicPlayer, [&](QMediaPlayer::MediaStatus status){
        if(status == QMediaPlayer::LoadedMedia){
            qDebug() << "Media loaded";
        }
        else if(status == QMediaPlayer::InvalidMedia){
            qDebug() << "Something went wrong!";
        };
    });


    //musicStatus.setMaximum(200);
    //musicStatus.setValue(150);

    layout->addWidget(&musicStatus);
    layout->addWidget(&playButton);
    layout->addWidget(&stopButton);
    layout->addWidget(&selectButton);
    mainWindow.resize(500, 300);
    mainWindow.show();
    return app.exec();
}



