/*******************************************************************************
 *  (c) 2019 - 2022 Zondax AG
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
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "substrate_types.h"
#include "substrate_types_V10.h"
#include <stddef.h>
#include <stdint.h>
#ifdef LEDGER_SPECIFIC
#include "bolos_target.h"
#endif

#define PD_CALL_SYSTEM_V10 0
#define PD_CALL_TIMESTAMP_V10 3
#define PD_CALL_BALANCES_V10 10
#define PD_CALL_COLLATORSELECTION_V10 21
#define PD_CALL_SESSION_V10 22
#define PD_CALL_XCMPQUEUE_V10 30
#define PD_CALL_POLKADOTXCM_V10 31
#define PD_CALL_DMPQUEUE_V10 33
#define PD_CALL_UTILITY_V10 40
#define PD_CALL_MULTISIG_V10 41
#define PD_CALL_PROXY_V10 42
#define PD_CALL_ASSETS_V10 50
#define PD_CALL_UNIQUES_V10 51

#define PD_CALL_BALANCES_TRANSFER_ALL_V10 4
typedef struct {
    pd_AccountIdLookupOfT_V10_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V10_t;

#define PD_CALL_SESSION_SET_KEYS_V10 0
typedef struct {
    pd_Keys_V10_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V10_t;

#define PD_CALL_SESSION_PURGE_KEYS_V10 1
typedef struct {
} pd_session_purge_keys_V10_t;

#define PD_CALL_UTILITY_BATCH_V10 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V10_t;

#define PD_CALL_UTILITY_BATCH_ALL_V10 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V10_t;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#define PD_CALL_POLKADOTXCM_RESERVE_TRANSFER_ASSETS_V10 2
typedef struct {
    pd_BoxVersionedMultiLocation_V10_t dest;
    pd_BoxVersionedMultiLocation_V10_t beneficiary;
    pd_BoxVersionedMultiAssets_V10_t assets;
    pd_u32_t fee_asset_item;
} pd_polkadotxcm_reserve_transfer_assets_V10_t;
#define PD_CALL_POLKADOTXCM_LIMITED_RESERVE_TRANSFER_ASSETS_V10 8
typedef struct {
    pd_BoxVersionedMultiLocation_V10_t dest;
    pd_BoxVersionedMultiLocation_V10_t beneficiary;
    pd_BoxVersionedMultiAssets_V10_t assets;
    pd_u32_t fee_asset_item;
    pd_WeightLimit_V10_t weight_limit;
} pd_polkadotxcm_limited_reserve_transfer_assets_V10_t;
#endif

#define PD_CALL_TIMESTAMP_SET_V10 0
typedef struct {
    pd_Compactu64_t now;
} pd_timestamp_set_V10_t;

#define PD_CALL_BALANCES_FORCE_UNRESERVE_V10 5
typedef struct {
    pd_AccountIdLookupOfT_V10_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V10_t;

#define PD_CALL_COLLATORSELECTION_SET_INVULNERABLES_V10 0
typedef struct {
    pd_VecAccountId_V10_t new_;
} pd_collatorselection_set_invulnerables_V10_t;

#define PD_CALL_COLLATORSELECTION_SET_DESIRED_CANDIDATES_V10 1
typedef struct {
    pd_u32_t max;
} pd_collatorselection_set_desired_candidates_V10_t;

#define PD_CALL_COLLATORSELECTION_SET_CANDIDACY_BOND_V10 2
typedef struct {
    pd_Balance_t bond;
} pd_collatorselection_set_candidacy_bond_V10_t;

#define PD_CALL_COLLATORSELECTION_REGISTER_AS_CANDIDATE_V10 3
typedef struct {
} pd_collatorselection_register_as_candidate_V10_t;

#define PD_CALL_COLLATORSELECTION_LEAVE_INTENT_V10 4
typedef struct {
} pd_collatorselection_leave_intent_V10_t;

#define PD_CALL_XCMPQUEUE_SERVICE_OVERWEIGHT_V10 0
typedef struct {
    pd_OverweightIndex_V10_t index;
    pd_XcmWeight_V10_t weight_limit;
} pd_xcmpqueue_service_overweight_V10_t;

#define PD_CALL_XCMPQUEUE_SUSPEND_XCM_EXECUTION_V10 1
typedef struct {
} pd_xcmpqueue_suspend_xcm_execution_V10_t;

#define PD_CALL_XCMPQUEUE_RESUME_XCM_EXECUTION_V10 2
typedef struct {
} pd_xcmpqueue_resume_xcm_execution_V10_t;

#define PD_CALL_XCMPQUEUE_UPDATE_SUSPEND_THRESHOLD_V10 3
typedef struct {
    pd_u32_t new_;
} pd_xcmpqueue_update_suspend_threshold_V10_t;

#define PD_CALL_XCMPQUEUE_UPDATE_DROP_THRESHOLD_V10 4
typedef struct {
    pd_u32_t new_;
} pd_xcmpqueue_update_drop_threshold_V10_t;

#define PD_CALL_XCMPQUEUE_UPDATE_RESUME_THRESHOLD_V10 5
typedef struct {
    pd_u32_t new_;
} pd_xcmpqueue_update_resume_threshold_V10_t;

#define PD_CALL_XCMPQUEUE_UPDATE_THRESHOLD_WEIGHT_V10 6
typedef struct {
    pd_XcmWeight_V10_t new_;
} pd_xcmpqueue_update_threshold_weight_V10_t;

#define PD_CALL_XCMPQUEUE_UPDATE_WEIGHT_RESTRICT_DECAY_V10 7
typedef struct {
    pd_XcmWeight_V10_t new_;
} pd_xcmpqueue_update_weight_restrict_decay_V10_t;

#define PD_CALL_XCMPQUEUE_UPDATE_XCMP_MAX_INDIVIDUAL_WEIGHT_V10 8
typedef struct {
    pd_XcmWeight_V10_t new_;
} pd_xcmpqueue_update_xcmp_max_individual_weight_V10_t;

#define PD_CALL_DMPQUEUE_SERVICE_OVERWEIGHT_V10 0
typedef struct {
    pd_OverweightIndex_V10_t index;
    pd_XcmWeight_V10_t weight_limit;
} pd_dmpqueue_service_overweight_V10_t;

#define PD_CALL_UTILITY_FORCE_BATCH_V10 4
typedef struct {
    pd_VecCall_t calls;
} pd_utility_force_batch_V10_t;

#define PD_CALL_PROXY_ADD_PROXY_V10 1
typedef struct {
    pd_AccountIdLookupOfT_V10_t delegate;
    pd_ProxyType_V10_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_add_proxy_V10_t;

#define PD_CALL_PROXY_REMOVE_PROXY_V10 2
typedef struct {
    pd_AccountIdLookupOfT_V10_t delegate;
    pd_ProxyType_V10_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_remove_proxy_V10_t;

#define PD_CALL_PROXY_REMOVE_PROXIES_V10 3
typedef struct {
} pd_proxy_remove_proxies_V10_t;

#define PD_CALL_PROXY_CREATE_PURE_V10 4
typedef struct {
    pd_ProxyType_V10_t proxy_type;
    pd_BlockNumber_t delay;
    pd_u16_t index;
} pd_proxy_create_pure_V10_t;

#define PD_CALL_PROXY_KILL_PURE_V10 5
typedef struct {
    pd_AccountIdLookupOfT_V10_t spawner;
    pd_ProxyType_V10_t proxy_type;
    pd_u16_t index;
    pd_Compactu32_t height;
    pd_Compactu32_t ext_index;
} pd_proxy_kill_pure_V10_t;

#define PD_CALL_PROXY_ANNOUNCE_V10 6
typedef struct {
    pd_AccountIdLookupOfT_V10_t real;
    pd_CallHashOf_V10_t call_hash;
} pd_proxy_announce_V10_t;

#define PD_CALL_PROXY_REMOVE_ANNOUNCEMENT_V10 7
typedef struct {
    pd_AccountIdLookupOfT_V10_t real;
    pd_CallHashOf_V10_t call_hash;
} pd_proxy_remove_announcement_V10_t;

#define PD_CALL_PROXY_REJECT_ANNOUNCEMENT_V10 8
typedef struct {
    pd_AccountIdLookupOfT_V10_t delegate;
    pd_CallHashOf_V10_t call_hash;
} pd_proxy_reject_announcement_V10_t;

#define PD_CALL_PROXY_PROXY_ANNOUNCED_V10 9
typedef struct {
    pd_AccountIdLookupOfT_V10_t delegate;
    pd_AccountIdLookupOfT_V10_t real;
    pd_OptionProxyType_V10_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_announced_V10_t;

#define PD_CALL_ASSETS_START_DESTROY_V10 2
typedef struct {
    pd_Compactu32_t id;
} pd_assets_start_destroy_V10_t;

#define PD_CALL_ASSETS_DESTROY_ACCOUNTS_V10 3
typedef struct {
    pd_Compactu32_t id;
} pd_assets_destroy_accounts_V10_t;

#define PD_CALL_ASSETS_DESTROY_APPROVALS_V10 4
typedef struct {
    pd_Compactu32_t id;
} pd_assets_destroy_approvals_V10_t;

#define PD_CALL_ASSETS_FINISH_DESTROY_V10 5
typedef struct {
    pd_Compactu32_t id;
} pd_assets_finish_destroy_V10_t;

#define PD_CALL_ASSETS_TOUCH_V10 26
typedef struct {
    pd_Compactu32_t id;
} pd_assets_touch_V10_t;

#define PD_CALL_ASSETS_REFUND_V10 27
typedef struct {
    pd_Compactu32_t id;
    pd_bool_t allow_burn;
} pd_assets_refund_V10_t;

#define PD_CALL_UNIQUES_CREATE_V10 0
typedef struct {
    pd_CollectionId_V10_t collection;
    pd_AccountIdLookupOfT_V10_t admin;
} pd_uniques_create_V10_t;

#define PD_CALL_UNIQUES_FORCE_CREATE_V10 1
typedef struct {
    pd_CollectionId_V10_t collection;
    pd_AccountIdLookupOfT_V10_t owner;
    pd_bool_t free_holding;
} pd_uniques_force_create_V10_t;

#define PD_CALL_UNIQUES_DESTROY_V10 2
typedef struct {
    pd_CollectionId_V10_t collection;
    pd_DestroyWitness_V10_t witness;
} pd_uniques_destroy_V10_t;

#define PD_CALL_UNIQUES_MINT_V10 3
typedef struct {
    pd_CollectionId_V10_t collection;
    pd_ItemId_V10_t item;
    pd_AccountIdLookupOfT_V10_t owner;
} pd_uniques_mint_V10_t;

#define PD_CALL_UNIQUES_BURN_V10 4
typedef struct {
    pd_CollectionId_V10_t collection;
    pd_ItemId_V10_t item;
    pd_OptionAccountIdLookupOfT_V10_t check_owner;
} pd_uniques_burn_V10_t;

#define PD_CALL_UNIQUES_TRANSFER_V10 5
typedef struct {
    pd_CollectionId_V10_t collection;
    pd_ItemId_V10_t item;
    pd_AccountIdLookupOfT_V10_t dest;
} pd_uniques_transfer_V10_t;

#define PD_CALL_UNIQUES_REDEPOSIT_V10 6
typedef struct {
    pd_CollectionId_V10_t collection;
    pd_VecItemId_V10_t items;
} pd_uniques_redeposit_V10_t;

#define PD_CALL_UNIQUES_FREEZE_V10 7
typedef struct {
    pd_CollectionId_V10_t collection;
    pd_ItemId_V10_t item;
} pd_uniques_freeze_V10_t;

#define PD_CALL_UNIQUES_THAW_V10 8
typedef struct {
    pd_CollectionId_V10_t collection;
    pd_ItemId_V10_t item;
} pd_uniques_thaw_V10_t;

#define PD_CALL_UNIQUES_FREEZE_COLLECTION_V10 9
typedef struct {
    pd_CollectionId_V10_t collection;
} pd_uniques_freeze_collection_V10_t;

#define PD_CALL_UNIQUES_THAW_COLLECTION_V10 10
typedef struct {
    pd_CollectionId_V10_t collection;
} pd_uniques_thaw_collection_V10_t;

#define PD_CALL_UNIQUES_TRANSFER_OWNERSHIP_V10 11
typedef struct {
    pd_CollectionId_V10_t collection;
    pd_AccountIdLookupOfT_V10_t owner;
} pd_uniques_transfer_ownership_V10_t;

#define PD_CALL_UNIQUES_SET_TEAM_V10 12
typedef struct {
    pd_CollectionId_V10_t collection;
    pd_AccountIdLookupOfT_V10_t issuer;
    pd_AccountIdLookupOfT_V10_t admin;
    pd_AccountIdLookupOfT_V10_t freezer;
} pd_uniques_set_team_V10_t;

#define PD_CALL_UNIQUES_APPROVE_TRANSFER_V10 13
typedef struct {
    pd_CollectionId_V10_t collection;
    pd_ItemId_V10_t item;
    pd_AccountIdLookupOfT_V10_t delegate;
} pd_uniques_approve_transfer_V10_t;

#define PD_CALL_UNIQUES_CANCEL_APPROVAL_V10 14
typedef struct {
    pd_CollectionId_V10_t collection;
    pd_ItemId_V10_t item;
    pd_OptionAccountIdLookupOfT_V10_t maybe_check_delegate;
} pd_uniques_cancel_approval_V10_t;

#define PD_CALL_UNIQUES_FORCE_ITEM_STATUS_V10 15
typedef struct {
    pd_CollectionId_V10_t collection;
    pd_AccountIdLookupOfT_V10_t owner;
    pd_AccountIdLookupOfT_V10_t issuer;
    pd_AccountIdLookupOfT_V10_t admin;
    pd_AccountIdLookupOfT_V10_t freezer;
    pd_bool_t free_holding;
    pd_bool_t is_frozen;
} pd_uniques_force_item_status_V10_t;

#define PD_CALL_UNIQUES_SET_ATTRIBUTE_V10 16
typedef struct {
    pd_CollectionId_V10_t collection;
    pd_OptionItemId_V10_t maybe_item;
    pd_BoundedVecu8_V10_t key;
    pd_BoundedVecu8_V10_t value;
} pd_uniques_set_attribute_V10_t;

#define PD_CALL_UNIQUES_CLEAR_ATTRIBUTE_V10 17
typedef struct {
    pd_CollectionId_V10_t collection;
    pd_OptionItemId_V10_t maybe_item;
    pd_BoundedVecu8_V10_t key;
} pd_uniques_clear_attribute_V10_t;

#define PD_CALL_UNIQUES_SET_METADATA_V10 18
typedef struct {
    pd_CollectionId_V10_t collection;
    pd_ItemId_V10_t item;
    pd_BoundedVecu8_V10_t data;
    pd_bool_t is_frozen;
} pd_uniques_set_metadata_V10_t;

#define PD_CALL_UNIQUES_CLEAR_METADATA_V10 19
typedef struct {
    pd_CollectionId_V10_t collection;
    pd_ItemId_V10_t item;
} pd_uniques_clear_metadata_V10_t;

#define PD_CALL_UNIQUES_SET_COLLECTION_METADATA_V10 20
typedef struct {
    pd_CollectionId_V10_t collection;
    pd_BoundedVecu8_V10_t data;
    pd_bool_t is_frozen;
} pd_uniques_set_collection_metadata_V10_t;

#define PD_CALL_UNIQUES_CLEAR_COLLECTION_METADATA_V10 21
typedef struct {
    pd_CollectionId_V10_t collection;
} pd_uniques_clear_collection_metadata_V10_t;

#define PD_CALL_UNIQUES_SET_ACCEPT_OWNERSHIP_V10 22
typedef struct {
    pd_OptionCollectionId_V10_t maybe_collection;
} pd_uniques_set_accept_ownership_V10_t;

#define PD_CALL_UNIQUES_SET_COLLECTION_MAX_SUPPLY_V10 23
typedef struct {
    pd_CollectionId_V10_t collection;
    pd_u32_t max_supply;
} pd_uniques_set_collection_max_supply_V10_t;

#define PD_CALL_UNIQUES_SET_PRICE_V10 24
typedef struct {
    pd_CollectionId_V10_t collection;
    pd_ItemId_V10_t item;
    pd_OptionItemPrice_V10_t price;
    pd_OptionAccountIdLookupOfT_V10_t whitelisted_buyer;
} pd_uniques_set_price_V10_t;

#define PD_CALL_UNIQUES_BUY_ITEM_V10 25
typedef struct {
    pd_CollectionId_V10_t collection;
    pd_ItemId_V10_t item;
    pd_ItemPrice_V10_t bid_price;
} pd_uniques_buy_item_V10_t;

#endif

typedef union {
    pd_balances_transfer_all_V10_t balances_transfer_all_V10;
    pd_session_set_keys_V10_t session_set_keys_V10;
    pd_session_purge_keys_V10_t session_purge_keys_V10;
    pd_utility_batch_V10_t utility_batch_V10;
    pd_utility_batch_all_V10_t utility_batch_all_V10;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    pd_polkadotxcm_reserve_transfer_assets_V10_t polkadotxcm_reserve_transfer_assets_V10;
    pd_polkadotxcm_limited_reserve_transfer_assets_V10_t polkadotxcm_limited_reserve_transfer_assets_V10;
#endif
    pd_timestamp_set_V10_t timestamp_set_V10;
    pd_balances_force_unreserve_V10_t balances_force_unreserve_V10;
    pd_collatorselection_set_invulnerables_V10_t collatorselection_set_invulnerables_V10;
    pd_collatorselection_set_desired_candidates_V10_t collatorselection_set_desired_candidates_V10;
    pd_collatorselection_set_candidacy_bond_V10_t collatorselection_set_candidacy_bond_V10;
    pd_collatorselection_register_as_candidate_V10_t collatorselection_register_as_candidate_V10;
    pd_collatorselection_leave_intent_V10_t collatorselection_leave_intent_V10;
    pd_xcmpqueue_service_overweight_V10_t xcmpqueue_service_overweight_V10;
    pd_xcmpqueue_suspend_xcm_execution_V10_t xcmpqueue_suspend_xcm_execution_V10;
    pd_xcmpqueue_resume_xcm_execution_V10_t xcmpqueue_resume_xcm_execution_V10;
    pd_xcmpqueue_update_suspend_threshold_V10_t xcmpqueue_update_suspend_threshold_V10;
    pd_xcmpqueue_update_drop_threshold_V10_t xcmpqueue_update_drop_threshold_V10;
    pd_xcmpqueue_update_resume_threshold_V10_t xcmpqueue_update_resume_threshold_V10;
    pd_xcmpqueue_update_threshold_weight_V10_t xcmpqueue_update_threshold_weight_V10;
    pd_xcmpqueue_update_weight_restrict_decay_V10_t xcmpqueue_update_weight_restrict_decay_V10;
    pd_xcmpqueue_update_xcmp_max_individual_weight_V10_t xcmpqueue_update_xcmp_max_individual_weight_V10;
    pd_dmpqueue_service_overweight_V10_t dmpqueue_service_overweight_V10;
    pd_utility_force_batch_V10_t utility_force_batch_V10;
    pd_proxy_add_proxy_V10_t proxy_add_proxy_V10;
    pd_proxy_remove_proxy_V10_t proxy_remove_proxy_V10;
    pd_proxy_remove_proxies_V10_t proxy_remove_proxies_V10;
    pd_proxy_create_pure_V10_t proxy_create_pure_V10;
    pd_proxy_kill_pure_V10_t proxy_kill_pure_V10;
    pd_proxy_announce_V10_t proxy_announce_V10;
    pd_proxy_remove_announcement_V10_t proxy_remove_announcement_V10;
    pd_proxy_reject_announcement_V10_t proxy_reject_announcement_V10;
    pd_proxy_proxy_announced_V10_t proxy_proxy_announced_V10;
    pd_assets_start_destroy_V10_t assets_start_destroy_V10;
    pd_assets_destroy_accounts_V10_t assets_destroy_accounts_V10;
    pd_assets_destroy_approvals_V10_t assets_destroy_approvals_V10;
    pd_assets_finish_destroy_V10_t assets_finish_destroy_V10;
    pd_assets_touch_V10_t assets_touch_V10;
    pd_assets_refund_V10_t assets_refund_V10;
    pd_uniques_create_V10_t uniques_create_V10;
    pd_uniques_force_create_V10_t uniques_force_create_V10;
    pd_uniques_destroy_V10_t uniques_destroy_V10;
    pd_uniques_mint_V10_t uniques_mint_V10;
    pd_uniques_burn_V10_t uniques_burn_V10;
    pd_uniques_transfer_V10_t uniques_transfer_V10;
    pd_uniques_redeposit_V10_t uniques_redeposit_V10;
    pd_uniques_freeze_V10_t uniques_freeze_V10;
    pd_uniques_thaw_V10_t uniques_thaw_V10;
    pd_uniques_freeze_collection_V10_t uniques_freeze_collection_V10;
    pd_uniques_thaw_collection_V10_t uniques_thaw_collection_V10;
    pd_uniques_transfer_ownership_V10_t uniques_transfer_ownership_V10;
    pd_uniques_set_team_V10_t uniques_set_team_V10;
    pd_uniques_approve_transfer_V10_t uniques_approve_transfer_V10;
    pd_uniques_cancel_approval_V10_t uniques_cancel_approval_V10;
    pd_uniques_force_item_status_V10_t uniques_force_item_status_V10;
    pd_uniques_set_attribute_V10_t uniques_set_attribute_V10;
    pd_uniques_clear_attribute_V10_t uniques_clear_attribute_V10;
    pd_uniques_set_metadata_V10_t uniques_set_metadata_V10;
    pd_uniques_clear_metadata_V10_t uniques_clear_metadata_V10;
    pd_uniques_set_collection_metadata_V10_t uniques_set_collection_metadata_V10;
    pd_uniques_clear_collection_metadata_V10_t uniques_clear_collection_metadata_V10;
    pd_uniques_set_accept_ownership_V10_t uniques_set_accept_ownership_V10;
    pd_uniques_set_collection_max_supply_V10_t uniques_set_collection_max_supply_V10;
    pd_uniques_set_price_V10_t uniques_set_price_V10;
    pd_uniques_buy_item_V10_t uniques_buy_item_V10;
#endif
} pd_MethodBasic_V10_t;

#define PD_CALL_BALANCES_TRANSFER_V10 0
typedef struct {
    pd_AccountIdLookupOfT_V10_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_V10_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V10 2
typedef struct {
    pd_AccountIdLookupOfT_V10_t source;
    pd_AccountIdLookupOfT_V10_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V10_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V10 3
typedef struct {
    pd_AccountIdLookupOfT_V10_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_V10_t;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
#define PD_CALL_SYSTEM_FILL_BLOCK_V10 0
typedef struct {
    pd_Perbill_V10_t ratio;
} pd_system_fill_block_V10_t;

#define PD_CALL_SYSTEM_REMARK_V10 1
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_V10_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V10 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V10_t;

#define PD_CALL_SYSTEM_SET_CODE_V10 3
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_V10_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V10 4
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_without_checks_V10_t;

#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V10 8
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_with_event_V10_t;

#define PD_CALL_BALANCES_SET_BALANCE_V10 1
typedef struct {
    pd_AccountIdLookupOfT_V10_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V10_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V10 0
typedef struct {
    pd_VecAccountId_V10_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V10_t;

#define PD_CALL_MULTISIG_AS_MULTI_V10 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V10_t other_signatories;
    pd_OptionTimepoint_V10_t maybe_timepoint;
    pd_Call_t call;
    pd_Weight_V10_t max_weight;
} pd_multisig_as_multi_V10_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V10 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V10_t other_signatories;
    pd_OptionTimepoint_V10_t maybe_timepoint;
    pd_H256_t call_hash;
    pd_Weight_V10_t max_weight;
} pd_multisig_approve_as_multi_V10_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V10 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V10_t other_signatories;
    pd_Timepoint_V10_t timepoint;
    pd_H256_t call_hash;
} pd_multisig_cancel_as_multi_V10_t;

#define PD_CALL_PROXY_PROXY_V10 0
typedef struct {
    pd_AccountIdLookupOfT_V10_t real;
    pd_OptionProxyType_V10_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_V10_t;

#define PD_CALL_ASSETS_CREATE_V10 0
typedef struct {
    pd_Compactu32_t id;
    pd_AccountIdLookupOfT_V10_t admin;
    pd_Balance_t min_balance;
} pd_assets_create_V10_t;

#define PD_CALL_ASSETS_FORCE_CREATE_V10 1
typedef struct {
    pd_Compactu32_t id;
    pd_AccountIdLookupOfT_V10_t owner;
    pd_bool_t is_sufficient;
    pd_CompactBalance_t min_balance;
} pd_assets_force_create_V10_t;

#define PD_CALL_ASSETS_MINT_V10 6
typedef struct {
    pd_Compactu32_t id;
    pd_AccountIdLookupOfT_V10_t beneficiary;
    pd_CompactBalance_t amount;
} pd_assets_mint_V10_t;

#define PD_CALL_ASSETS_BURN_V10 7
typedef struct {
    pd_Compactu32_t id;
    pd_AccountIdLookupOfT_V10_t who;
    pd_CompactBalance_t amount;
} pd_assets_burn_V10_t;

#define PD_CALL_ASSETS_TRANSFER_V10 8
typedef struct {
    pd_Compactu32_t id;
    pd_AccountIdLookupOfT_V10_t target;
    pd_CompactBalance_t amount;
} pd_assets_transfer_V10_t;

#define PD_CALL_ASSETS_TRANSFER_KEEP_ALIVE_V10 9
typedef struct {
    pd_Compactu32_t id;
    pd_AccountIdLookupOfT_V10_t target;
    pd_CompactBalance_t amount;
} pd_assets_transfer_keep_alive_V10_t;

#define PD_CALL_ASSETS_FORCE_TRANSFER_V10 10
typedef struct {
    pd_Compactu32_t id;
    pd_AccountIdLookupOfT_V10_t source;
    pd_AccountIdLookupOfT_V10_t dest;
    pd_CompactBalance_t amount;
} pd_assets_force_transfer_V10_t;

#define PD_CALL_ASSETS_FREEZE_V10 11
typedef struct {
    pd_Compactu32_t id;
    pd_AccountIdLookupOfT_V10_t who;
} pd_assets_freeze_V10_t;

#define PD_CALL_ASSETS_THAW_V10 12
typedef struct {
    pd_Compactu32_t id;
    pd_AccountIdLookupOfT_V10_t who;
} pd_assets_thaw_V10_t;

#define PD_CALL_ASSETS_FREEZE_ASSET_V10 13
typedef struct {
    pd_Compactu32_t id;
} pd_assets_freeze_asset_V10_t;

#define PD_CALL_ASSETS_THAW_ASSET_V10 14
typedef struct {
    pd_Compactu32_t id;
} pd_assets_thaw_asset_V10_t;

#define PD_CALL_ASSETS_TRANSFER_OWNERSHIP_V10 15
typedef struct {
    pd_Compactu32_t id;
    pd_AccountIdLookupOfT_V10_t owner;
} pd_assets_transfer_ownership_V10_t;

#define PD_CALL_ASSETS_SET_TEAM_V10 16
typedef struct {
    pd_Compactu32_t id;
    pd_AccountIdLookupOfT_V10_t issuer;
    pd_AccountIdLookupOfT_V10_t admin;
    pd_AccountIdLookupOfT_V10_t freezer;
} pd_assets_set_team_V10_t;

#define PD_CALL_ASSETS_SET_METADATA_V10 17
typedef struct {
    pd_Compactu32_t id;
    pd_Vecu8_t name;
    pd_Vecu8_t symbol;
    pd_u8_t decimals;
} pd_assets_set_metadata_V10_t;

#define PD_CALL_ASSETS_CLEAR_METADATA_V10 18
typedef struct {
    pd_Compactu32_t id;
} pd_assets_clear_metadata_V10_t;

#define PD_CALL_ASSETS_FORCE_SET_METADATA_V10 19
typedef struct {
    pd_Compactu32_t id;
    pd_Vecu8_t name;
    pd_Vecu8_t symbol;
    pd_u8_t decimals;
    pd_bool_t is_frozen;
} pd_assets_force_set_metadata_V10_t;

#define PD_CALL_ASSETS_FORCE_CLEAR_METADATA_V10 20
typedef struct {
    pd_Compactu32_t id;
} pd_assets_force_clear_metadata_V10_t;

#define PD_CALL_ASSETS_FORCE_ASSET_STATUS_V10 21
typedef struct {
    pd_Compactu32_t id;
    pd_AccountIdLookupOfT_V10_t owner;
    pd_AccountIdLookupOfT_V10_t issuer;
    pd_AccountIdLookupOfT_V10_t admin;
    pd_AccountIdLookupOfT_V10_t freezer;
    pd_CompactBalance_t min_balance;
    pd_bool_t is_sufficient;
    pd_bool_t is_frozen;
} pd_assets_force_asset_status_V10_t;

#define PD_CALL_ASSETS_APPROVE_TRANSFER_V10 22
typedef struct {
    pd_Compactu32_t id;
    pd_AccountIdLookupOfT_V10_t delegate;
    pd_CompactBalance_t amount;
} pd_assets_approve_transfer_V10_t;

#define PD_CALL_ASSETS_CANCEL_APPROVAL_V10 23
typedef struct {
    pd_Compactu32_t id;
    pd_AccountIdLookupOfT_V10_t delegate;
} pd_assets_cancel_approval_V10_t;

#define PD_CALL_ASSETS_FORCE_CANCEL_APPROVAL_V10 24
typedef struct {
    pd_Compactu32_t id;
    pd_AccountIdLookupOfT_V10_t owner;
    pd_AccountIdLookupOfT_V10_t delegate;
} pd_assets_force_cancel_approval_V10_t;

#define PD_CALL_ASSETS_TRANSFER_APPROVED_V10 25
typedef struct {
    pd_Compactu32_t id;
    pd_AccountIdLookupOfT_V10_t owner;
    pd_AccountIdLookupOfT_V10_t destination;
    pd_CompactBalance_t amount;
} pd_assets_transfer_approved_V10_t;

#endif

typedef union {
    pd_balances_transfer_V10_t balances_transfer_V10;
    pd_balances_force_transfer_V10_t balances_force_transfer_V10;
    pd_balances_transfer_keep_alive_V10_t balances_transfer_keep_alive_V10;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    pd_system_fill_block_V10_t system_fill_block_V10;
    pd_system_remark_V10_t system_remark_V10;
    pd_system_set_heap_pages_V10_t system_set_heap_pages_V10;
    pd_system_set_code_V10_t system_set_code_V10;
    pd_system_set_code_without_checks_V10_t system_set_code_without_checks_V10;
    pd_system_remark_with_event_V10_t system_remark_with_event_V10;
    pd_balances_set_balance_V10_t balances_set_balance_V10;
    pd_multisig_as_multi_threshold_1_V10_t multisig_as_multi_threshold_1_V10;
    pd_multisig_as_multi_V10_t multisig_as_multi_V10;
    pd_multisig_approve_as_multi_V10_t multisig_approve_as_multi_V10;
    pd_multisig_cancel_as_multi_V10_t multisig_cancel_as_multi_V10;
    pd_proxy_proxy_V10_t proxy_proxy_V10;
    pd_assets_create_V10_t assets_create_V10;
    pd_assets_force_create_V10_t assets_force_create_V10;
    pd_assets_mint_V10_t assets_mint_V10;
    pd_assets_burn_V10_t assets_burn_V10;
    pd_assets_transfer_V10_t assets_transfer_V10;
    pd_assets_transfer_keep_alive_V10_t assets_transfer_keep_alive_V10;
    pd_assets_force_transfer_V10_t assets_force_transfer_V10;
    pd_assets_freeze_V10_t assets_freeze_V10;
    pd_assets_thaw_V10_t assets_thaw_V10;
    pd_assets_freeze_asset_V10_t assets_freeze_asset_V10;
    pd_assets_thaw_asset_V10_t assets_thaw_asset_V10;
    pd_assets_transfer_ownership_V10_t assets_transfer_ownership_V10;
    pd_assets_set_team_V10_t assets_set_team_V10;
    pd_assets_set_metadata_V10_t assets_set_metadata_V10;
    pd_assets_clear_metadata_V10_t assets_clear_metadata_V10;
    pd_assets_force_set_metadata_V10_t assets_force_set_metadata_V10;
    pd_assets_force_clear_metadata_V10_t assets_force_clear_metadata_V10;
    pd_assets_force_asset_status_V10_t assets_force_asset_status_V10;
    pd_assets_approve_transfer_V10_t assets_approve_transfer_V10;
    pd_assets_cancel_approval_V10_t assets_cancel_approval_V10;
    pd_assets_force_cancel_approval_V10_t assets_force_cancel_approval_V10;
    pd_assets_transfer_approved_V10_t assets_transfer_approved_V10;
#endif
} pd_MethodNested_V10_t;

typedef union {
    pd_MethodBasic_V10_t basic;
    pd_MethodNested_V10_t nested;
} pd_Method_V10_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
