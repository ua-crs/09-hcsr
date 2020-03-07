/*
 *     Project 09-hcsr - main.cpp
 *         Usando el sensor ultrsonico HC-SR04
 *         para medir distancias
 *
 *         Usar shield IAE
 *         Verificar cuidadosamente la conexion del sensor a la placa
 */

#include <Arduino.h>

/*
 *  Definiciones incluidas en platformio.ini
 *      TRIG_PIN    Salida de disparo
 *      ECHO_PIN    Entrada de eco
 *      SERIAL_BAUD Baud rate de port serie
 */

/*
 *  Otras constantes
 */

const double sound_speed = 0.0343;    // en centimetros/microsegundo

void
send_trigger( void )
{
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
}

long
get_pulse( void )
{
    return pulseIn( ECHO_PIN, HIGH );    // en microsegundos
}


void
setup()
{
    pinMode(TRIG_PIN, OUTPUT);     // trigPin como salida 
    digitalWrite(TRIG_PIN, LOW);

    pinMode(ECHO_PIN, INPUT);    // echoPin como entrada
    Serial.begin(SERIAL_BAUD);
}

void
loop()
{
    long duration;
    double distance;

    send_trigger();
    duration = get_pulse();

    distance = duration * sound_speed / 2;

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println( " cm" );

    delay(2000);
}
