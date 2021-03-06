/**
 * Copyright (C) 2012 by INdT
 * Copyright (C) 2014 Bacon2D Project
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * @author Rodrigo Goncalves de Oliveira <rodrigo.goncalves@openbossa.org>
 * @author Roger Felipe Zanoni da Silva <roger.zanoni@openbossa.org>
 */

#ifndef _SPRITEANIMATION_H_
#define _SPRITEANIMATION_H_

#include <QtCore/QState>
#include <QtCore/QPropertyAnimation>
#include <QUrl>

class SpriteSheet;
class QPropertyAnimation;

class SpriteAnimation : public QState
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QUrl source READ source WRITE setSource NOTIFY sourceChanged)
    Q_PROPERTY(int frames READ frames WRITE setFrames NOTIFY framesChanged)
    Q_PROPERTY(int frame READ frame WRITE setFrame NOTIFY frameChanged)
    Q_PROPERTY(int initialFrame READ initialFrame WRITE setInitialFrame NOTIFY initialFrameChanged)
    Q_PROPERTY(bool running READ running WRITE setRunning NOTIFY runningChanged)
    Q_PROPERTY(int loops READ loops WRITE setLoops NOTIFY loopsChanged)
    Q_PROPERTY(bool visible READ visible WRITE setVisible NOTIFY visibleChanged)
    Q_PROPERTY(int duration READ duration WRITE setDuration NOTIFY durationChanged)
    Q_PROPERTY(bool inverse READ inverse WRITE setInverse NOTIFY inverseChanged)

public:
    SpriteAnimation(QState *parent = 0);

    QString name() const;
    void setName(const QString &name);

    bool running() const;
    void setRunning(const bool &running);

    int loops() const;
    void setLoops(const int &loops);

    QUrl source() const;
    void setSource(const QUrl &source);

    int frames() const;
    void setFrames(const int &frames);

    int frame() const;
    void setFrame(const int &frame);

    int initialFrame() const;
    void setInitialFrame(const int &initialFrame);

    bool visible() const;
    void setVisible(const bool &visible);

    int duration() const;
    void setDuration(const int &duration);

    bool inverse() const;
    void setInverse(const bool &inverse);

    bool verticalMirror() const;
    void setVerticalMirror(const bool &verticalMirror);

    bool horizontalMirror() const;
    void setHorizontalMirror(const bool &horizontalMirror);

    SpriteSheet *spriteSheet();

signals:
    void runningChanged();
    void loopsChanged();
    void sourceChanged();
    void framesChanged();
    void frameChanged();
    void initialFrameChanged();
    void visibleChanged();
    void durationChanged();
    void inverseChanged();
    void finished();

private:
    QString m_name;
    SpriteSheet *m_spriteSheet;
    QPropertyAnimation *m_spriteAnimation;
    bool m_inverse;
};

#endif /* _SPRITEANIMATION_H_ */
