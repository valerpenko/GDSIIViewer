#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "DrawingArea.h"
#include <QDebug>
#include <QtCore>
#include <QtWidgets>
#include <QFileDialog>
#include <cmath>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dArea=new DrawingArea(this);
    dArea->setFixedWidth(ui->horizontalScrollBar->width());
    dArea->setFixedHeight(ui->verticalScrollBar->height());
    ui->vertLayout->addWidget(dArea);



    //rectangle
    QLine left(400,100,400,200);
    QLine top(400,200,600,200);
    QLine right(600,200,600,100);
    QLine bottom(600,100,400,100);
    //path
    QLine pt1(0,0,50,100);
    QLine pt2(50,100,50,300);
    QLine pt3(50,300,200,300);

    //polygon
    QLine f1(150,100,300,100);
    QLine f2(300,100,300,130);
    QLine f3(300,130,200,130);
    QLine f4(200,130,200,180);
    QLine f5(200,180,150,180);
    QLine f6(150,180,150,100);

    QLine cl(0,dArea->height()-31,300,dArea->height()-31);


    LineContainer* lines=new LineContainer();
    lines->AddLine(left);
    lines->AddLine(top);
    lines->AddLine(right);
    lines->AddLine(bottom);
    lines->AddLine(pt1);
    lines->AddLine(pt2);
    lines->AddLine(pt3);
    lines->AddLine(f1);
    lines->AddLine(f2);
    lines->AddLine(f3);
    lines->AddLine(f4);
    lines->AddLine(f5);
    lines->AddLine(f6);
    lines->AddLine(cl);


    dArea->SetLineContainer(lines);


    //ui->spbZoom->setFocusPolicy(Qt::NoFocus);
    //ui->spbLayer->setFocusPolicy(Qt::NoFocus);
    //QObject::connect(ui->spbZoom,SIGNAL(valueChanged(int)),dArea,SLOT(ScaleValueChanged(int)));
    QObject::connect(ui->spbZoom,SIGNAL(valueChanged(int)),this,SLOT(ZoomValueChanged(int)));
    QObject::connect(ui->spbZoom,SIGNAL(valueChanged(int)),this,SLOT(CalculateScrolls(int)));

    QObject::connect(ui->btnOK,SIGNAL(clicked()),this,SLOT(BtnOkClick()));
    QObject::connect(ui->spbLayer,SIGNAL(valueChanged(int)),this,SLOT(LayerValueChanged(int)));

    QObject::connect(this,SIGNAL(ZoomValueUpdated(double)),dArea,SLOT(ScaleValueChanged(double)));
    QObject::connect(this,SIGNAL(ZoomValueUpdated(double)),this,SLOT(CalculateWindowPoints(double)));

    QObject::connect(ui->verticalScrollBar,SIGNAL(valueChanged(int)),dArea,SLOT(VerticalScrollValueChanged(int)));
    QObject::connect(ui->horizontalScrollBar,SIGNAL(valueChanged(int)),dArea,SLOT(HorizontalScrollValueChanged(int)));

    QObject::connect(ui->verticalScrollBar,SIGNAL(valueChanged(int)),this,SLOT(VerticalScrollChanged(int)));
    QObject::connect(ui->horizontalScrollBar,SIGNAL(valueChanged(int)),this,SLOT(HorizontalScrollChanged(int)));

    ui->spbZoom->setMaximum(5000);
    ui->spbZoom->setMinimum(100);
    ui->verticalScrollBar->setMaximum(dArea->height()/2);//ProjectHeight/2);//
    ui->horizontalScrollBar->setMaximum(dArea->width()/2);//ProjectWidth/2);//

    //CalculateScrolls(ui->spbZoom->value());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event){
}
void MainWindow::CalculateScrolls(int value)
{
    double checkVal=value/100.0;
    double newWidthMax=dArea->width()*checkVal-dArea->width();//ProjectWidth*checkVal-ProjectWidth;
    double newHeightMax=dArea->height()*checkVal-dArea->height();//ProjectHeight*checkVal-ProjectHeight;//

    //qDebug()<<"newMaxW:"<<newWidthMax;
    //qDebug()<<"newMaxY:"<<newHeightMax;

    ui->horizontalScrollBar->setMaximum(newWidthMax>1?newWidthMax:0);
    ui->horizontalScrollBar->valueChanged(ui->horizontalScrollBar->value());
    //qDebug()<<"HorMAX:"<<ui->horizontalScrollBar->maximum();
    ui->verticalScrollBar->setMaximum(newHeightMax>1?newHeightMax:0);
    ui->verticalScrollBar->valueChanged(ui->verticalScrollBar->value());
}
void MainWindow::CalculateWindowPoints(double value){
    winMinX=horScrollValue/value;
    winMinY=verScrollValue/value;

    winMaxX=dArea->width()/value+winMinX;
    winMaxY=dArea->height()/value+winMinY;

    qDebug()<<"Window borders:["<<winMinX<<","<<winMinY<<"], "<<"["<<winMaxX<<","<<winMaxY<<"]";
}

void MainWindow::ZoomValueChanged(int value){
    zoomCoef=ZoomConvert(value);
    qDebug()<<"COEF value:"<<zoomCoef;
    emit ZoomValueUpdated(zoomCoef);
}
//Calculate window position in global World
void MainWindow::HorizontalScrollChanged(int value){
    horScrollValue=value;
    //qDebug()<<"Window position in pixels:["<<horScrollValue<<","<<verScrollValue<<"]";
    CalculateWindowPoints(zoomCoef);
    //PrepareLineContainerForDrawing();
    //repaint();
}
void MainWindow::VerticalScrollChanged(int value){
    int max=ui->verticalScrollBar->maximum();
    verScrollValue=abs(value-max);
    //qDebug()<<"MAX:"<<max<<" Vert val:"<<verScrollValue;
    //qDebug()<<"VerScrVal:"<<verScrollValue;
    //qDebug()<<"Window position in pixels:["<<horScrollValue<<","<<verScrollValue<<"]";
    CalculateWindowPoints(zoomCoef);
}

void MainWindow::LayerValueChanged(int value){
    currentLayer=value;
    //LayerForView* l4v=design->GetLayerForView(value);
    //LineContainer* cont=l4v->GetLineContainerForArea(winMinX,winMinY,winMaxX,winMaxY);
    //dArea->SetLineContainer(cont);
}

void MainWindow::GetNewLayerFromDesign()
{
    layerForView=design->GetLayerForView(currentLayer);
    qDebug()<<"Layer size:"<<layerForView->GetLayerWidth()<<"x"<<layerForView->GetLayerHeight();
}

void MainWindow::PrepareLineContainerForDrawing()
{
    if(layerForView!=0)
    {
        LineContainer* cont=layerForView->GetLineContainerForArea(winMinX,winMinY,winMaxX,winMaxY);
        qDebug()<<"Layer size:"<<cont->GetAreaWidth()<<"x"<<cont->GetAreaHeight();
        dArea->SetLineContainer(cont);
    }
    else
    { //throw AnError();

    }
}

void MainWindow::BtnOkClick(){
    GetNewLayerFromDesign();
    PrepareLineContainerForDrawing();
    repaint();
}

double MainWindow::ZoomConvert(int value)
{
    return value/100.0;
}


void MainWindow::SetProjectHeight(int height){
    ProjectHeight=height;
    dArea->SetGlobalHeight(height);
}
void MainWindow::SetProjectWidth(int width){
    ProjectWidth=width;
    dArea->SetGlobalWidth(width);
}

void MainWindow::on_actionOpen_triggered()
{
    QString fName=QFileDialog::getOpenFileName(this,"Open File","E:/");
    if(!fName.isEmpty())
    {
        QFileInfo fileInfo(fName);
        QString extension=fileInfo.suffix();
        GlobalOptions::SetFileName(fName.toStdString());
        if(extension=="txt")
        {
            GlobalOptions::SetSourceType(TEXT_SOURCE);
        }
        designReader=new GDSIIDesignReader();
        try
        {
            design=designReader->MakeModel();
        }
        catch (QException ex)
        {
            QMessageBox::information(this,"Error occur","Error while building a design");
        }
        designLoaded=true;
        //QMessageBox::information(this,"Success","Design was successfully loaded");
        //QMessageBox::information(this,"File was selected",fName+" AND ext="+extension);
    }
    else
    QMessageBox::information(this,"File was not selected","No file was selected");
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}
