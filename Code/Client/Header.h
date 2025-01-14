#ifndef HEADER_H
#define HEADER_H

#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsEffect>
#include <QPainterPath>
#include <QColor>
#include <QGraphicsSceneEvent>
#include <QGraphicsObject>
#include <QObject>
#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include <QtNetwork>
#include <QTimer>
#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsItemAnimation>
#include <QGraphicsTextItem>
#include <QTextBlockFormat>
#include <QTextCursor>
#include <QOpenGLWidget>
#include <QAbstractSocket>
#include <QFile>
#include <QDialog>
#include <QFileDialog>
#include <QKeyEvent>
#include <QStyleOptionGraphicsItem>
#include <QStyle>

const int SCENE_WIDTH = 512;
const int SCENE_HEIGHT = 288;
const int EDIT_LINE_HEIGHT = 54;
const QString version = "0.0.1";
const QColor LightPink(255,182,193),Pink(255,192,203),Crimson(220,20,60),LavenderBlush(255,240,245),PaleVioletRed(219,112,147),HotPink(255,105,180),DeepPink(255,20,147),MediumVioletRed(199,21,133),Orchid(218,112,214),Thistle(216,191,216),Plum(221,160,221),Violet(238,130,238),Magenta(255,0,255),Fuchsia(255,0,255),DarkMagenta(139,0,139),Purple(128,0,128),MediumOrchid(186,85,211),DarkVoilet(148,0,211),DarkOrchid(153,50,204),Indigo(75,0,130),BlueViolet(138,43,226),MediumPurple(147,112,219),MediumSlateBlue(123,104,238),SlateBlue(106,90,205),DarkSlateBlue(72,61,139),Lavender(230,230,250),GhostWhite(248,248,255),Blue(0,0,255),MediumBlue(0,0,205),MidnightBlue(25,25,112),DarkBlue(0,0,139),Navy(0,0,128),RoyalBlue(65,105,225),CornflowerBlue(100,149,237),LightSteelBlue(176,196,222),LightSlateGray(119,136,153),SlateGray(112,128,144),DoderBlue(30,144,255),AliceBlue(240,248,255),SteelBlue(70,130,180),LightSkyBlue(135,206,250),SkyBlue(135,206,235),DeepSkyBlue(0,191,255),LightBLue(173,216,230),PowDerBlue(176,224,230),CadetBlue(95,158,160),Azure(240,255,255),LightCyan(225,255,255),PaleTurquoise(175,238,238),Cyan(0,255,255),Aqua(212,242,231),DarkTurquoise(0,206,209),DarkSlateGray(47,79,79),DarkCyan(0,139,139),Teal(0,128,128),MediumTurquoise(72,209,204),LightSeaGreen(32,178,170),Turquoise(64,224,208),Auqamarin(127,255,170),MediumAquamarine(0,250,154),MediumSpringGreen(0,255,127),MintCream(245,255,250),SpringGreen(60,179,113),SeaGreen(46,139,87),Honeydew(240,255,240),LightGreen(144,238,144),PaleGreen(152,251,152),DarkSeaGreen(143,188,143),LimeGreen(50,205,50),Lime(0,255,0),ForestGreen(34,139,34),Green(0,128,0),DarkGreen(0,100,0),Chartreuse(127,255,0),LawnGreen(124,252,0),GreenYellow(173,255,47),OliveDrab(85,107,47),Beige(245,245,220),LightGoldenrodYellow(250,250,210),Ivory(255,255,240),LightYellow(255,255,224),Yellow(255,255,0),Olive(128,128,0),DarkKhaki(189,183,107),LemonChiffon(255,250,205),PaleGodenrod(238,232,170),Khaki(240,230,140),Gold(255,215,0),Cornislk(255,248,220),GoldEnrod(218,165,32),FloralWhite(255,250,240),OldLace(253,245,230),Wheat(245,222,179),Moccasin(255,228,181),Orange(255,165,0),PapayaWhip(255,239,213),BlanchedAlmond(255,235,205),NavajoWhite(255,222,173),AntiqueWhite(250,235,215),Tan(210,180,140),BrulyWood(222,184,135),Bisque(255,228,196),DarkOrange(255,140,0),Linen(250,240,230),Peru(205,133,63),PeachPuff(255,218,185),SandyBrown(244,164,96),Chocolate(210,105,30),SaddleBrown(139,69,19),SeaShell(255,245,238),Sienna(160,82,45),LightSalmon(255,160,122),Coral(255,127,80),OrangeRed(255,69,0),DarkSalmon(233,150,122),Tomato(255,99,71),MistyRose(255,228,225),Salmon(250,128,114),Snow(255,250,250),LightCoral(240,128,128),RosyBrown(188,143,143),IndianRed(205,92,92),Red(255,0,0),Brown(165,42,42),FireBrick(178,34,34),DarkRed(139,0,0),Maroon(128,0,0),White(255,255,255),WhiteSmoke(245,245,245),Gainsboro(220,220,220),LightGrey(211,211,211),Silver(192,192,192),DarkGray(169,169,169),Gray(128,128,128),DimGray(105,105,105),Black(0,0,0);
const qint64 payloadSize = 64 * 1024;
#endif // HEADER_H
