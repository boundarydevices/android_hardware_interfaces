/*
 * Copyright (C) 2019 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "libhealthloop"

#include <cutils/klog.h>
#include <cutils/properties.h>
#include <health/utils.h>
namespace android {
namespace hardware {
namespace health {

// Periodic chores fast interval in seconds
#define DEFAULT_PERIODIC_CHORES_INTERVAL_FAST (60 * 1)
// Periodic chores fast interval in seconds
#define DEFAULT_PERIODIC_CHORES_INTERVAL_SLOW (60 * 10)

void InitHealthdConfig(struct healthd_config* healthd_config) {
    *healthd_config = {
            .periodic_chores_interval_fast = property_get_int32("ro.vendor.health.interval.fast",
                                                                DEFAULT_PERIODIC_CHORES_INTERVAL_FAST),
            .periodic_chores_interval_slow = property_get_int32("ro.vendor.health.interval.slow",
                                                                DEFAULT_PERIODIC_CHORES_INTERVAL_SLOW),
            .energyCounter = NULL,
            .boot_min_cap = 0,
            .screen_on = NULL,
    };
    KLOG_INFO(LOG_TAG, "periodic chores fast %ds slow %ds\n",
              healthd_config->periodic_chores_interval_fast,
              healthd_config->periodic_chores_interval_slow);
}

}  // namespace health
}  // namespace hardware
}  // namespace android
