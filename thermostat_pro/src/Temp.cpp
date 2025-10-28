#include "Temp.h"

float readCurrentTemperature() {
    int analogValue = analogRead(TEMP_PIN);
    return (1 / (log(1 / (1023. / analogValue - 1)) 
                / BETA + 1.0 / 298.15) - 273.15);
}