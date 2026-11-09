#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/sys/printk.h>
#include <stdlib.h>

#define STACK_SIZE 1024
#define PRIORITY 1

int saldo_vitrine = 0;

void padeiro(void *arg1, void *arg2, void *arg3) {
    while(1) {
    k_msleep(1000);

    if (saldo_vitrine < 10) {
    saldo_vitrine++;
    printk("Padeiro produziu um pao! Saldo da vitrine: %d\n", saldo_vitrine);
    }
    
    else {
        printk("Vitrine cheia.\n");
    }
}
}

void cliente(void *arg1, void *arg2, void *arg3) {
    while(1) {
    k_msleep(1500);
    saldo_vitrine--;
    printk("Cliente comprou um pao! Saldo da vitrine: %d\n", saldo_vitrine);
    }
}

K_THREAD_DEFINE(Padeiro, STACK_SIZE, padeiro,
                NULL, NULL, NULL,
                PRIORITY, 0, 0);

K_THREAD_DEFINE(Cliente, STACK_SIZE, cliente,
                NULL, NULL, NULL,
                PRIORITY, 0, 0);