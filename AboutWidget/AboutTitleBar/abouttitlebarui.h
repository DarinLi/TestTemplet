#ifndef ABOUTTITLEBARUI_H
#define ABOUTTITLEBARUI_H

#include <QWidget>
#include <QPainter>
#include <QStyleOption>

#include <QLabel>
#include <QToolButton>
#include <QButtonGroup>
#include <QHBoxLayout>

class AboutTitleBarUI : public QWidget
{
    Q_OBJECT

public:
    explicit AboutTitleBarUI(QWidget *parent = nullptr);
    ~AboutTitleBarUI() override;

public:
    void titleBarCustomCreate(void);

public:
    void setWindowTitle(const QString &title);
    QString WindowTitle() const;

    void setWindowIcon(const QPixmap &icon);
    QPixmap icon() const;

    void setTitleBarHeight(const int height);
    int titleBarHeight() const;

    QButtonGroup* titleBarButtonGroup();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    class AboutTitleBarUIPrivate;
    const QScopedPointer<AboutTitleBarUIPrivate> d;
};

#endif // MAINWIDGETUI_H
