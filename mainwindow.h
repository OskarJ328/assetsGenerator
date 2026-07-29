#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QFont>
#include <QFontMetrics>
#include <QGridLayout>

#include "tiles.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
    QString imageFilePath;
    QImage CurrImage;
    QImage NewImage;

    int NewImageWidth;
    int NewImageHeight;
    QVector<uint16_t> RGB565;


    QString fontFilePath;
    QFont font;
    QFontMetrics fontMetrics;


    QGridLayout *mapLayout = nullptr;
    QVector<tile_t> tiles;
    QVector<QVector<TileType>> map;
    int mapWidth = 0;
    int mapHeight = 0;
    int tileSize;

    void connectsInit();
    void namesInit();


    void browseImageFile();
    void showImage();
    void refreshCurrentImageInfo();
    void refreshNewImageInfo();
    void changeNewImageResolution();
    void NewImageWidthChangedAction();
    void NewImageHeightChangedAction();
    void generateNewImage();
    void saveNewImage();
    void convertToRGB565();
    void generateRGB565Array();

    void browseFontFile();
    void refreshFontInfo();
    QImage generateGlyphImage(const QString &text);
    void showFontImage();
    void fontSizeChangedAction();
    QVector<uint16_t> generateGlyphArray(char c);
    void generateFontArray();

    void setMapMaxSize(int width, int height);
    void tilesComboBoxInit();
    void getCurrentTile();
    void createMap();
    void confirmMapParams();
};
#endif // MAINWINDOW_H
