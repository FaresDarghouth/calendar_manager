//
// Created by squip on 01/11/2023.
//

#include "main.h"
#include "part3.h"

int main() {
    setbuf(stdout, NULL);
    p_appointment myAppointment = ScanAppointment();
    getAppointment(myAppointment);
    return 0;
}