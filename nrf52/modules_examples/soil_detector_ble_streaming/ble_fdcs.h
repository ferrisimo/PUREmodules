/* Copyright (c) Nordic Semiconductor ASA
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 *   1. Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * 
 *   2. Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 * 
 *   3. Neither the name of Nordic Semiconductor ASA nor the names of other
 *   contributors to this software may be used to endorse or promote products
 *   derived from this software without specific prior written permission.
 * 
 *   4. This software must only be used in a processor manufactured by Nordic
 *   Semiconductor ASA, or in a processor manufactured by a third party that
 *   is used in combination with a processor manufactured by Nordic Semiconductor.
 * 
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#ifndef OUR_SERVICE_H__
#define OUR_SERVICE_H__

#include <stdint.h>
#include "ble.h"
#include "ble_srv_common.h"

#define BLE_UUID_FDC_BASE_UUID              {{0x23, 0xD1, 0x13, 0xEF, 0x5F, 0x78, 0x23, 0x15, 0xDE, 0xEF, 0x12, 0x12, 0x00, 0x00, 0x00, 0x00}} // 128-bit base UUID


#define BLE_UUID_FDC_SERVICE                	0xABCD // Just a random, but recognizable value
#define BLE_UUID_FDC_CH0_CHARACTERISTC_UUID     0xFDC0 // Just a random, but recognizable value
#define BLE_UUID_FDC_CH1_CHARACTERISTC_UUID     0xFDC1 // Just a random, but recognizable value
#define BLE_UUID_FDC_CH2_CHARACTERISTC_UUID     0xFDC2 // Just a random, but recognizable value



/**
 * @brief This structure contains various status information for our service. 
 * It only holds one entry now, but will be populated with more items as we go.
 * The name is based on the naming convention used in Nordic's SDKs. 
 * 'ble’ indicates that it is a Bluetooth Low Energy relevant structure and 
 * ‘os’ is short for Our Service). 
 */
typedef struct
{
	uint16_t 					conn_handle;
    uint16_t    				service_handle;     /**< Handle of Our Service (as provided by the BLE stack). */
	ble_gatts_char_handles_t 	ch0_char_handles;   /*helps fdc service know which characteristic is is on*/
	ble_gatts_char_handles_t 	ch1_char_handles;	/*helps fdc service know which characteristic is is on*/
	ble_gatts_char_handles_t 	ch2_char_handles;	/*helps fdc service know which characteristic is is on*/
}ble_fdcs_t;




void ble_fdc_service_on_ble_evt(ble_fdcs_t * p_our_service, ble_evt_t * p_ble_evt);


/**@brief Function for initializing our new service.
 *
 * @param[in]   p_our_service       Pointer to Our Service structure.
 
 */
void ble_fdcs_init(ble_fdcs_t * p_our_service);

/**@brief Function for updating and sending new characteristic values
 *
 * @details The application calls this function whenever our timer_timeout_handler triggers
 *
 * @param[in]   p_our_service                     Our Service structure.
 * @param[in]   characteristic_value     New characteristic value.
 */
 
void fdc_chx_characteristic_update(ble_fdcs_t *p_our_service, uint32_t *temperature_value,  uint16_t ch_handles_value);
void fdc_ch1_characteristic_update(ble_fdcs_t *p_our_service, int32_t *temperature_value);

#endif  /* _ OUR_SERVICE_H__ */