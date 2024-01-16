#ifndef CPPCOLORS_H
#define CPPCOLORS_H

#include "QtWidgets/qapplication.h"
#include <QObject>
#include <QColor>
#include <QFont>
#include <QtGui>

class Theme : public QObject
{
Q_OBJECT
public:
    explicit Theme(QObject *parent = nullptr) : QObject(parent), m_isDarkMode(true) {}

    Q_INVOKABLE bool isDarkMode() const { return m_isDarkMode; }
    Q_INVOKABLE void changeMode() { m_isDarkMode = !m_isDarkMode; }

    Q_INVOKABLE QColor background() const { return m_isDarkMode ? QColor("#ff0000") : QColor("#e3e1d8"); }
    Q_INVOKABLE QColor surface1() const { return m_isDarkMode ? QColor("#171819") : QColor("#EFEFEF"); }
    Q_INVOKABLE QColor surface2() const { return m_isDarkMode ? QColor("#090A0C") : QColor("#CCCCCC"); }
    Q_INVOKABLE QColor text() const { return m_isDarkMode ? QColor("#D4BE98") : QColor("#333333"); }
    Q_INVOKABLE QColor textFile() const { return m_isDarkMode ? QColor("#E1D2B7") : QColor("#666666"); }
    Q_INVOKABLE QColor disabledText() const { return m_isDarkMode ? QColor("#2C313A") : QColor("#999999"); }
    Q_INVOKABLE QColor selection() const { return m_isDarkMode ? QColor("#4B4A4A") : QColor("#DDDDDD"); }
    Q_INVOKABLE QColor active() const { return m_isDarkMode ? QColor("#292828") : QColor("#FFFFFF"); }
    Q_INVOKABLE QColor inactive() const { return m_isDarkMode ? QColor("#383737") : QColor("#F0F0F0"); }
    Q_INVOKABLE QColor folder() const { return m_isDarkMode ? QColor("#383737") : QColor("#F0F0F0"); }
    Q_INVOKABLE QColor icon() const { return m_isDarkMode ? QColor("#383737") : QColor("#555555"); }
    Q_INVOKABLE QColor iconIndicator() const { return m_isDarkMode ? QColor("#D5B35D") : QColor("#FFA500"); }
    Q_INVOKABLE QColor color1() const { return m_isDarkMode ? QColor("#A7B464") : QColor("#3498DB"); }
    Q_INVOKABLE QColor color2() const { return m_isDarkMode ? QColor("#D3869B") : QColor("#E74C3C"); }

    Q_INVOKABLE QFont font() const
    {
        return QFont("Roboto Mono", QApplication::font().pixelSize());
    }

    Q_INVOKABLE QFont largeFont() const
    {
        return QFont("Roboto Mono", QApplication::font().pixelSize() * 1.6);
    }

private:
    bool m_isDarkMode;
};

#endif // CPPCOLORS_H
