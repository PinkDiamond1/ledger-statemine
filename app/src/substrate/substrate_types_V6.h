/*******************************************************************************
 *  (c) 2019 - 2022 Zondax GmbH
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ********************************************************************************/
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "substrate_types.h"
#include <stddef.h>
#include <stdint.h>

// Based
// https://github.com/paritytech/substrate/blob/master/node/primitives/src/lib.rs

typedef struct {
    const uint8_t* _ptr;
} pd_AccountId_V6_t;

typedef struct {
    compactInt_t value;
} pd_CompactAccountIndex_V6_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ChargeAssetIdOf_V6_t;

typedef struct {
    uint32_t value;
} pd_ClassId_V6_t;

typedef struct {
    uint32_t value;
} pd_InstanceId_V6_t;

typedef struct {
    const uint8_t* _ptr;
} pd_KeyValue_V6_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Key_V6_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountId_V6_t id;
        pd_CompactAccountIndex_V6_t index;
        pd_Bytes_t raw;
        const uint8_t* _ptr;
    };
} pd_LookupasStaticLookupSource_V6_t;

typedef struct {
    uint8_t value;
} pd_ProxyType_V6_t;

typedef struct {
    pd_BlockNumber_t height;
    uint32_t index;
} pd_Timepoint_V6_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_XcmVersion_V6_t;

typedef struct {
    pd_Compactu32_t accounts;
    pd_Compactu32_t sufficients;
    pd_Compactu32_t approvals;
} pd_DestroyWitness_V6_t;

typedef struct {
    pd_Call_t call;
} pd_OpaqueCall_V6_t;

typedef struct {
    uint8_t some;
    pd_LookupasStaticLookupSource_V6_t contained;
} pd_OptionLookupasStaticLookupSource_V6_t;

typedef struct {
    uint8_t some;
    pd_Timepoint_V6_t contained;
} pd_OptionTimepoint_V6_t;

typedef struct {
    uint64_t _len;
    uint64_t _lenBuffer;
    const uint8_t* _ptr;
} pd_BoundedVecu8_V6_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxMultiLocation_V6_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxPalletsOrigin_V6_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxVersionedMultiAssets_V6_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxVersionedMultiLocation_V6_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxVersionedXcmTasSysConfigCall_V6_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxVersionedXcmTuple_V6_t;

typedef struct {
    const uint8_t* _ptr;
} pd_CallHashOf_V6_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Keys_V6_t;

typedef struct {
    uint8_t some;
    pd_ClassId_V6_t contained;
} pd_OptionClassId_V6_t;

typedef struct {
    uint8_t some;
    pd_InstanceId_V6_t contained;
} pd_OptionInstanceId_V6_t;

typedef struct {
    uint8_t some;
    pd_ProxyType_V6_t contained;
} pd_OptionProxyType_V6_t;

typedef struct {
    uint8_t some;
    pd_XcmVersion_V6_t contained;
} pd_OptionXcmVersion_V6_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_OverweightIndex_V6_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ParachainInherentData_V6_t;

typedef struct {
    uint32_t value;
} pd_Perbill_V6_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_UpwardMessage_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAccountId_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecInstanceId_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecKeyValue_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecKey_V6_t;

typedef struct {
    uint64_t value;
} pd_WeightLimit_V6_t;

typedef struct {
    uint64_t value;
} pd_Weight_V6_t;

#ifdef __cplusplus
}
#endif
