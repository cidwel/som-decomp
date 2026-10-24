#include "som_c.h"

/* C071A2 dispatch_native_seven_category_ring_action_and_mark_equipment_pair   [class C, 98 bytes, 41 instructions]
 * Source: src/rom/dispatch_native_seven_category_ring_action_and_mark_equipment_pair.s
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void dispatch_native_seven_category_ring_action_and_mark_equipment_pair(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    RAM8(0x1803) &= 0xFD;
    RAM8(0x1804) &= 0x0F;
    uint8_t value3 = RAM8(0x1847);
    if (value3 == 0) {
        uint8_t ring_cursor = RAM8(RING_CURSOR);
        uint16_t value4 = RAM16(0x18A0 + (uint8_t)((a_hi << 8) | (uint8_t)(ring_cursor << 1)));
        if ((value4 & 0x4000) != 0) {
            r->a = value4 & 0x4000;
            r->x = (uint8_t)((a_hi << 8) | (uint8_t)(ring_cursor << 1));
            r->y = (uint8_t)y;
            r->c = ring_cursor & 0x80;
            r->z = (value4 & 0x4000) == 0;
            r->n = value4 & 0x4000 & 0x8000;
            r->mf = 0;
            TAIL_CALL(c, 0xC07594, SOM_RTS); /* reject_native_menu_row_and_clear_original_blink_records */
        }
        uint8_t ring_category = RAM8(RING_CATEGORY);
        if (ring_category < 3) {
            RAM8(0x1826) = 0;
            if (ring_category < 4) {
                RAM8(0x19F0) = ring_category;
            }
            r->a = ((value4 & 0x4000) >> 8 << 8) | (uint8_t)(ring_category << 1);
            r->x = (uint8_t)(((value4 & 0x4000) >> 8 << 8) | (uint8_t)(ring_category << 1));
            r->y = (uint8_t)y;
            r->c = ring_category & 0x80;
            r->z = (uint8_t)(((value4 & 0x4000) >> 8 << 8) | (uint8_t)(ring_category << 1)) == 0;
            r->n = (uint8_t)(((value4 & 0x4000) >> 8 << 8) | (uint8_t)(ring_category << 1)) & 0x80;
            r->mf = 0;
            switch ((uint8_t)(((value4 & 0x4000) >> 8 << 8) | (uint8_t)(ring_category << 1))) {
            case 0x0000: TAIL_CALL_DYN(c, 0xC07212, SOM_RTS); /* apply_selected_native_menu_consumable_with_real_target_selection */
            case 0x0002: TAIL_CALL_DYN(c, 0xC072B3, SOM_RTS); /* select_native_menu_spell_targets_and_validate_original_cast_request */
            case 0x0004: TAIL_CALL_DYN(c, 0xC073DB, SOM_RTS); /* dispatch_native_misc_ring_inventory_targets_and_five_modal_pages */
            case 0x0006: TAIL_CALL_DYN(c, 0xC0747F, SOM_RTS); /* prepare_native_equipment_mode_two_and_dispatch_transaction */
            case 0x0008: TAIL_CALL_DYN(c, 0xC0748A, SOM_RTS); /* dispatch_native_equipment_transaction_by_previous_and_current_owner */
            case 0x000A: TAIL_CALL_DYN(c, 0xC0748A, SOM_RTS); /* dispatch_native_equipment_transaction_by_previous_and_current_owner */
            case 0x000C: TAIL_CALL_DYN(c, 0xC0748A, SOM_RTS); /* dispatch_native_equipment_transaction_by_previous_and_current_owner */
            default: TAIL_CALL_DYN(c, 0xC00000 | BUS16(c, 0xC00000 + (uint16_t)(0x7204 + ((uint8_t)(((value4 & 0x4000) >> 8 << 8) | (uint8_t)(ring_category << 1))))), SOM_RTS);
            }
        }
        r->a = ((value4 & 0x4000) >> 8 << 8) | ring_category;
        r->x = (uint8_t)((a_hi << 8) | (uint8_t)(ring_cursor << 1));
        r->y = (uint8_t)y;
        r->c = ring_category >= 3;
        r->z = ring_category == 3;
        r->n = (uint8_t)(ring_category - 3) & 0x80;
        { const uint16_t sp_call = r->sp; JSL(c, 0x71D3, 0xD0CF08); GUARD_JSL(c, sp_call, 0x71D3); } /* request_native_menu_audio_0e */
        uint8_t db_ret = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        uint16_t a_all = r->a;
        uint16_t y_ret = r->y;
        uint8_t value5 = BUS8_RDP(c, (db_ret << 0x10) + 0x1803);
        if ((value5 & 0x40) != 0) {
            BUS8_SET(c, (db_ret << 0x10) + 0x1826, 0);
            uint8_t value6 = BUS8_RDP(c, (db_ret << 0x10) + 0x1809);
            if (value6 < 4) {
                BUS8_SET(c, (db_ret << 0x10) + 0x19F0, value6);
            }
            r->a = (a_all >> 8 << 8) | (uint8_t)(value6 << 1);
            r->x = (uint8_t)((a_all >> 8 << 8) | (uint8_t)(value6 << 1));
            r->y = (uint8_t)y_ret;
            r->c = value6 & 0x80;
            r->z = (uint8_t)((a_all >> 8 << 8) | (uint8_t)(value6 << 1)) == 0;
            r->n = (uint8_t)((a_all >> 8 << 8) | (uint8_t)(value6 << 1)) & 0x80;
            r->v = value5 & 0x40;
            r->mf = 0;
            r->xf = 0;
            switch ((uint8_t)((a_all >> 8 << 8) | (uint8_t)(value6 << 1))) {
            case 0x0000: TAIL_CALL_DYN(c, 0xC07212, SOM_RTS); /* apply_selected_native_menu_consumable_with_real_target_selection */
            case 0x0002: TAIL_CALL_DYN(c, 0xC072B3, SOM_RTS); /* select_native_menu_spell_targets_and_validate_original_cast_request */
            case 0x0004: TAIL_CALL_DYN(c, 0xC073DB, SOM_RTS); /* dispatch_native_misc_ring_inventory_targets_and_five_modal_pages */
            case 0x0006: TAIL_CALL_DYN(c, 0xC0747F, SOM_RTS); /* prepare_native_equipment_mode_two_and_dispatch_transaction */
            case 0x0008: TAIL_CALL_DYN(c, 0xC0748A, SOM_RTS); /* dispatch_native_equipment_transaction_by_previous_and_current_owner */
            case 0x000A: TAIL_CALL_DYN(c, 0xC0748A, SOM_RTS); /* dispatch_native_equipment_transaction_by_previous_and_current_owner */
            case 0x000C: TAIL_CALL_DYN(c, 0xC0748A, SOM_RTS); /* dispatch_native_equipment_transaction_by_previous_and_current_owner */
            default: TAIL_CALL_DYN(c, 0xC00000 | BUS16(c, 0xC00000 + (uint16_t)(0x7204 + ((uint8_t)((a_all >> 8 << 8) | (uint8_t)(value6 << 1))))), SOM_RTS);
            }
        }
        uint8_t value7 = BUS8_RDP(c, (db_ret << 0x10) + 0x1803);
        BUS8_SET(c, (db_ret << 0x10) + 0x1803, value7 | 0x40);
        uint8_t value8 = BUS8_RDP(c, (db_ret << 0x10) + 0x180A);
        BUS8_SET(c, (db_ret << 0x10) + 0x185C, value8);
        r->a = (a_all >> 8 << 8) | value8;
        r->z = value8 == 0;
        r->n = value8 & 0x80;
        r->v = value5 & 0x40;
        { const uint16_t sp_call = r->sp; JSR(c, 0x71E6, 0xC0794A); GUARD_JSR(c, sp_call, 0x71E6); } /* mark_selected_native_ring_row_and_return_owner_or_special_descriptor */
        uint16_t a_all2 = r->a;
        BUS8_SET(c, (db_ret << 0x10) + 0x185D, (uint8_t)a_all2);
        r->mf = 1;
        r->xf = 1;
        RETURN_RTS(c);
    }
    r->a = (a_hi << 8) | value3;
    r->x = (uint8_t)x;
    r->y = (uint8_t)y;
    r->z = value3 == 0;
    r->n = value3 & 0x80;
    r->xf = 1;
    TAIL_CALL(c, 0xC07AB5, SOM_RTS); /* dispatch_native_shop_action_to_buy_sell_or_weapon_upgrade */
}
SOM_REGISTER(0xC071A2, SOM_RTS, "gen", dispatch_native_seven_category_ring_action_and_mark_equipment_pair, SOM_UNWINDS, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 98, 41)
