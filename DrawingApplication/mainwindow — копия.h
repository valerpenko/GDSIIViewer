#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include "DrawingArea.h"
#include "src/GDSIIDesign.h"
#include "src/GDSIIDesignReader.h"
#include "src/LayerForView.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();    
private:
    Ui::MainWindow *ui;
    DrawingArea* dArea;
    void paintEvent(QPaintEvent *event);

    LayerForView* layerForView;
    GDSIIDesign* design;
    GDSIIDesignReader* designReader;

    bool designLoaded;

    double zoomCoef;
    int currentLayer;

    int horScrollValue;
    int verScrollValue;

    double winMinX;
    double winMaxX;
    double winMinY;
    double winMaxY;

    int ProjectWidth;
    int ProjectHeight;

    void SetProjectWidth(int width);
    void SetProjectHeight(int height);
    double ZoomConvert(int value);

    void GetNewLayerFromDesign();
    void PrepareLineContainerForDrawing();

signals:
    void ZoomValueUpdated(double);

private slots:
    void CalculateScrolls(int value);
    void CalculateWindowPoints(double value);
    void ZoomValueChanged(int value);
    void LayerValueChanged(int value);

    void BtnOkClick();

    void HorizontalScrollChanged(int value);
    void VerticalScrollChanged(int value);

    void on_actionOpen_triggered();
    void on_actionExit_triggered();
};

#endif // MAINWINDOW_H
