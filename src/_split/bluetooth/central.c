#include <zephyr/kernel.h>
#include <zmk/ble.h>

extern struct k_work_q split_central_split_run_q;

#if ZMK_BLE_IS_CENTRAL

static uint8_t bat_d = 0;
static void split_central_bat_st_asked_callback(struct k_work *work) {
    for (int i = 0; i < ZMK_SPLIT_BLE_PERIPHERAL_COUNT; i++) {
        // if (peripherals[i].state != PERIPHERAL_SLOT_STATE_CONNECTED) {
        // // if (peripherals[i].state != PERIPHERAL_SLOT_STATE_CONNECTED || peripherals[i].udpate_bat_st == 0) {
        //     LOG_DBG("Skip battery status asked for unconnected peripheral %d %d", peripherals[i].state, peripherals[i].udpate_bat_st);
        //     continue;
        // }
        // int err = bt_gatt_write_without_response(peripherals[i].conn, peripherals[i].udpate_bat_st, &bat_d, sizeof(bat_d), true);
        // if (err) {
        //     LOG_ERR("Failed to send battery status asked to peripheral (err %d)", err);
        // }
    }
}
static K_WORK_DEFINE(split_central_bat_st_asked, split_central_bat_st_asked_callback);
int zmk_split_bt_call_bat_st_asked() {
    return k_work_submit_to_queue(&split_central_split_run_q, &split_central_bat_st_asked);
}

#endif