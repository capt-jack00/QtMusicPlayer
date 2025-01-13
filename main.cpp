#include <QApplication>
#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QPushButton>
#include <QProgressBar>


int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    QMainWindow mainWindow;
    QWidget centralWidget;
    QGridLayout layout;
    QPushButton playButton;
    QProgressBar musicStatus;

    centralWidget.setLayout(&layout);
    mainWindow.setCentralWidget(&centralWidget);

    playButton.setText("Play");


    layout.addWidget(&musicStatus, 0, 1);
    layout.addWidget(&playButton, 0, 0);
    mainWindow.resize(500, 800);
    mainWindow.show();
    return app.exec();
}
