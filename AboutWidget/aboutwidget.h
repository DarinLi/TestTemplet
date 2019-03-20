#ifndef ABOUTWIDGET_H
#define ABOUTWIDGET_H

#include <QDialog>
#include <QVBoxLayout>

#include "framelesshelper.h"

#include "abouttitlebarui.h"
#include "aboutcentralwidgetui.h"

class AboutWidget : public QDialog
{
    Q_OBJECT

public:
    explicit AboutWidget(QWidget *parent = nullptr);
    ~AboutWidget() override;

public:
    void setFixedSize(const QSize &);
    void setFixedSize(int w, int h);

public slots:
    void mainTitleBarButtonClicked(int id);

public:
    FramelessHelper frameLessWidget;//adjust FrameLess Widget

private:
    class AboutWidgetPrivate;
    const QScopedPointer<AboutWidgetPrivate> d;
};

#endif // MAINWIDGET_H
