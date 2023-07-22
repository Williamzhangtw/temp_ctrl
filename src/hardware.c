void timer_isr(void)
{
    if(interrupt_1ms){
        clear_flag();
        tasks_mgmt();
    }
}