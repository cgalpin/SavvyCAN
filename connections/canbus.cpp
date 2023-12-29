#include <QObject>
#include <QDebug>
#include "canbus.h"

CANBus::CANBus()
{
    speed           = 500000;
    listenOnly      = false;
    singleWire      = false;
    active          = false;
    canFDSupported  = false;
    canFD           = false;
    dataRate        = 2000000;
}


CANBus::CANBus(const CANBus& pBus) :
    speed(pBus.speed),
    listenOnly(pBus.listenOnly),
    singleWire(pBus.singleWire),
    active(pBus.active),
    canFDSupported(pBus.canFDSupported),
    canFD(pBus.canFD),
    dataRate(pBus.dataRate){}


bool CANBus::operator==(const CANBus& bus) const{
    return  speed == bus.speed &&
            listenOnly == bus.listenOnly &&
            singleWire == bus.singleWire &&
            active == bus.active &&
            canFDSupported == bus.canFDSupported &&
            canFD == bus.canFD;
}

void CANBus::setSpeed(int newSpeed){
    //qDebug() << "CANBUS SetSpeed = " << newSpeed;
    speed = newSpeed;
}

void CANBus::setListenOnly(bool mode){
    //qDebug() << "CANBUS SetListenOnly = " << mode;
    listenOnly = mode;
}

void CANBus::setSingleWire(bool mode){
    //qDebug() << "CANBUS SetSingleWire = " << mode;
    singleWire = mode;
}

void CANBus::setActive(bool mode){
    //qDebug() << "CANBUS SetEnabled = " << mode;
    active = mode;
}

void CANBus::setCanFDSupported(bool mode){
    qDebug() << "CANBUS setCanFDSupported = " << mode;
    canFDSupported = mode;
}

void CANBus::setCanFD(bool mode){
    qDebug() << "CANBUS setCanFD = " << mode;
    canFD = mode;
}

int CANBus::getSpeed(){
    return speed;
}

int CANBus::getDataRate(){
    return dataRate;
}

void CANBus::setDataRate(int newSpeed){
    //qDebug() << "CANBUS SetSpeed = " << newSpeed;
    dataRate = newSpeed;
}

bool CANBus::isListenOnly(){
    return listenOnly;
}

bool CANBus::isSingleWire(){
    return singleWire;
}

bool CANBus::isActive(){
    return active;
}

bool CANBus::isCanFDSupported(){
    return canFDSupported;
}

bool CANBus::isCanFD(){
    return canFD;
}


QDataStream& operator<<( QDataStream & pStream, const CANBus& pCanBus )
{
    pStream << pCanBus.speed;
    pStream << pCanBus.listenOnly;
    pStream << pCanBus.singleWire;
    pStream << pCanBus.active;
    pStream << pCanBus.canFDSupported;
    pStream << pCanBus.canFD;
    pStream << pCanBus.dataRate;
    return pStream;
}

QDataStream & operator>>(QDataStream & pStream, CANBus& pCanBus)
{
    pStream >> pCanBus.speed;
    pStream >> pCanBus.listenOnly;
    pStream >> pCanBus.singleWire;
    pStream >> pCanBus.active;
    pStream >> pCanBus.canFDSupported;
    pStream >> pCanBus.canFD;
    pStream >> pCanBus.dataRate;
    return pStream;
}
