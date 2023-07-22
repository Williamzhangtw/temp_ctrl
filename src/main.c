#include "task_mgmt.h"
#include "temp_ctrl.h"
#include "usr_data.h"
#include "pwr_mgmt.h"
#include "ui.h"

#define MAJOR   0
#define MINOR   1
#define PATCH   0

void setup(void)
{
    /*  --- Hardware Initialization ---  */
    uart_init();
    gpio_init();

    /*  --- Library Initialization ---  */
    ds18b20_init();
    rotary_encoder_init();

    /*  --- Application Setup ---  */
    load_usr_data();
    tasks_init();

    /*  --- Main Application ---  */
    printf("Version: %d.%d.%d\n", MAJOR, MINOR, PATCH);
    show_version();
    delayms(2000);
    show(target_temp);
    delayms(2000);
}

void loop(void)
{
    tasks_process();
}