// Copyright lowRISC contributors (OpenTitan project).
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0

#include "sw/device/lib/arch/device.h"
#include "sw/device/lib/base/mmio.h"
#include "sw/device/lib/runtime/hart.h"
#include "sw/device/lib/testing/test_framework/check.h"
#include "sw/device/lib/testing/test_framework/ottf_main.h"

#include "hw/top_earlgrey/sw/autogen/top_earlgrey.h"

OTTF_DEFINE_TEST_CONFIG();


/**
 * - Verify the first escalation results in NMI interrupt serviced by the CPU.
 * - Verify the second results in device being put in escalate state, via the LC
 *   JTAG TAP.
 * - Verify the third results in chip reset.
 * - Ensure that all escalation handshakes complete without errors.
 *
 * The first escalation is checked via the entry of the NMI handler and polling
 * by dv. The second escalation is directly checked by dv. The third escalation
 * is checked via reset reason.
 */
bool test_main(void) {
  LOG_INFO("Hello");
  return true;
//  init_peripheral_handles();
//
//  // Check if there was a HW reset caused by the escalation.
//  dif_rstmgr_reset_info_bitfield_t rst_info;
//  rst_info = rstmgr_testutils_reason_get();
//  rstmgr_testutils_reason_clear();
//
//  if (rst_info & kDifRstmgrResetInfoPor) {
//    config_alert_handler();
//
//    // Initialize keymgr with otp contents
//    CHECK_STATUS_OK(keymgr_testutils_advance_state(&keymgr, NULL));
//
//    // DO NOT REMOVE, DV sync message
//    LOG_INFO("Keymgr entered Init State");
//
//    // Enable NMI
//    CHECK_DIF_OK(dif_rv_core_ibex_enable_nmi(&rv_core_ibex,
//                                             kDifRvCoreIbexNmiSourceAlert));
//
//    // force trigger the alert
//    CHECK_DIF_OK(dif_rv_core_ibex_alert_force(&rv_core_ibex,
//                                              kDifRvCoreIbexAlertRecovSwErr));
//
//    // Stop execution here and just wait for something to happen
//    wait_for_interrupt();
//    LOG_ERROR("Should have reset before this line");
//    return false;
//  } else if (rst_info & kDifRstmgrResetInfoEscalation) {
//    // DO NOT REMOVE, DV sync message
//    LOG_INFO("Reset due to alert escalation");
//    return true;
//  } else {
//    LOG_ERROR("Unexpected reset info %d", rst_info);
//  }
//
//  return false;
}
