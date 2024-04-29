#include "arduino.h"

Arduino::Arduino()
{
    data="";
    arduino_port_name="";
    arduino_is_available=false;
    serial=new QSerialPort;
}

QString Arduino::getarduino_port_name()
{
    return arduino_port_name;
}

QSerialPort *Arduino::getserial()
{
   return serial;
}
int Arduino::connect_arduino() {
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()) {
        if (serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()) {
            if (serial_port_info.vendorIdentifier() == arduino_uno_vendor_id && serial_port_info.productIdentifier() == arduino_uno_producy_id) {
                arduino_is_available = true;
                arduino_port_name = serial_port_info.portName();
            }
        }
    }

    if (arduino_is_available) {
        serial->setPortName(arduino_port_name);
        if (serial->open(QSerialPort::ReadWrite)) {
            qDebug() << "Serial port opened successfully";

            serial->setBaudRate(QSerialPort::Baud9600);
            serial->setDataBits(QSerialPort::Data8);
            serial->setParity(QSerialPort::NoParity);
            serial->setStopBits(QSerialPort::OneStop);
            serial->setFlowControl(QSerialPort::NoFlowControl);
            qDebug() << "Arduino connected on port: " << arduino_port_name;
            return 0; // Success
        } else {
            qDebug() << "Failed to open serial port. Error: " << serial->errorString();
            return 2; // Failed to open serial port
        }
    } else {
        qDebug() << "Arduino not found";
        return 1; // Arduino not found
    }
}

int Arduino::close_arduino()

{

    if(serial->isOpen()){
            serial->close();
            return 0;
        }
    return 1;


}

 QByteArray Arduino::read_from_arduino()
{
    if(serial->isReadable()){
         data=serial->readAll(); //récupérer les données reçues

         return data;
    }
 }

 int Arduino::write_to_arduino(QByteArray d)
 {
     if (serial->isOpen() && serial->isWritable()) {
         if (serial->write(d) == -1) {
             qDebug() << "Failed to write to serial port:" << serial->errorString();
             return 1; // Return failure code
         } else {
             qDebug() << "Data written to serial port successfully";
             return 0; // Return success code
         }
     } else {
         qDebug() << "Serial port is not open or not writable";
         return 1; // Return failure code
     }
 }
