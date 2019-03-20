#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QVBoxLayout>

#include "appversions.h"
#include "framelesshelper.h"

#include "maintitlebarui.h"
#include "maincentralwidgetui.h"

#include "aboutwidget.h"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget() override;

public:
    void setStyleSheet(const QString &stytle = "./theme/brightblack.qss");

    void setFixedSize(const QSize &);
    void setFixedSize(int w, int h);

public slots:
    void mainTitleBarButtonClicked(int id);
    void openAboutUI(void);

protected:
    bool event(QEvent *event) override;

public:
    FramelessHelper frameLessWidget;//adjust FrameLess Widget

private:
    class MainWidgetPrivate;
    const QScopedPointer<MainWidgetPrivate> d;
};

#endif // MAINWIDGET_H
