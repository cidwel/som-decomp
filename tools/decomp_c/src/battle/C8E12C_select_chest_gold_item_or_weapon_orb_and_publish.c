#include "som_c.h"

/* C8E12C select_chest_gold_item_or_weapon_orb_and_publish   [class B, 193 bytes, 88 instructions]
 * Source: src/rom/select_chest_gold_item_or_weapon_orb_and_publish.s
 * Documented in docs/event-vm-chest-reward.md
 * Entry: M=8 bit X=16 bit DB=any D=$0300.  Callers read: nothing.
 */
static void select_chest_gold_item_or_weapon_orb_and_publish(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint8_t db = r->db;
    uint8_t value = BUS8(c, 0xD03A52 + x);
    RAM8(BATTLE_TEMP_AC) = value;
    RAM8(BATTLE_TEMP_A4) = (value & 0x38) >> 3;
    r->a = (a_hi << 8) | ((value & 0x38) >> 3);
    r->c = (value & 0x38) >> 2 & 0x01;
    r->z = (value & 0x38) >> 3 == 0;
    r->n = (value & 0x38) >> 3 & 0x80;
    JSL(c, 0xE13C, 0xC0389C); /* random_byte_long_wrapper */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    uint16_t y_ret = r->y;
    bool overflow_ret = r->v;
    uint8_t battle_temp_a4 = RAM8(BATTLE_TEMP_A4);
    uint8_t battle_temp_ac = RAM8(BATTLE_TEMP_AC);
    if ((battle_temp_ac & 0xC0) != 0) {
        if ((battle_temp_ac & 0xC0) == 0x40) {
            uint8_t a1;
            if (((uint8_t)a_all & 0x3F) < battle_temp_a4) {
                uint8_t value2 = BUS8(c, 0xD03A54 + x_ret);
                a1 = value2;
            } else {
                uint8_t value3 = BUS8(c, 0xD03A53 + x_ret);
                a1 = value3;
            }
            uint8_t a2 = a1;
            uint8_t a_hi1 = a_all >> 8;
            uint16_t x1 = x_ret;
            uint16_t y1 = y_ret;
            bool overflow1 = overflow_ret;
            for (;;) {
                RAM8(BATTLE_TEMP_A4) = a2;
                if (a2 & 0x80) {
                    uint16_t battle_defender_ptr = RAM16(BATTLE_DEFENDER_PTR);
                    BUS8_SET(c, (db << 0x10) + 0xE1C9 + battle_defender_ptr, (uint8_t)(a2 - 0x80));
                    uint8_t value4 = BUS8(c, (db << 0x10) + 0xCFC0 + (((a_hi1 << 8) | (uint8_t)(a2 - 0x80)) & 0xFF));
                    RAM8(BATTLE_TEMP_A6) = value4;
                    uint8_t value5 = BUS8(c, (db << 0x10) + 0xCFB8 + (((a_hi1 << 8) | (uint8_t)(a2 - 0x80)) & 0xFF));
                    if ((uint8_t)(value5 + 1) < RAM8(BATTLE_TEMP_A6)) {
                        BUS8_SET(c, (db << 0x10) + 0xE1C8 + battle_defender_ptr, 8);
                        r->mf = true;
                        r->xf = false;
                        r->db = db;
                        r->dp = 0x0300;
                        RETURN_RTS(c);
                    }
                    uint8_t a2_next = 0x40;
                    uint8_t a_hi1_next = 0;
                    uint16_t x1_next = battle_defender_ptr;
                    uint16_t y1_next = ((a_hi1 << 8) | (uint8_t)(a2 - 0x80)) & 0xFF;
                    bool overflow1_next = ((a2 ^ 0x80) & (a2 ^ (uint8_t)(a2 - 0x80)) & 0x80) != 0;
                    a2 = a2_next;
                    a_hi1 = a_hi1_next;
                    x1 = x1_next;
                    y1 = y1_next;
                    overflow1 = overflow1_next;
                    continue;
                }
                r->a = (a_hi1 << 8) | a2;
                r->x = x1;
                r->y = y1;
                r->c = a2 >= 0;
                r->z = a2 == 0;
                r->n = a2 & 0x80;
                r->v = overflow1;
                r->mf = true;
                r->xf = false;
                r->db = db;
                r->dp = 0x0300;
                JSL(c, 0xE187, 0xC06420); /* jump_native_inventory_insert_command */
                uint16_t a_all2 = r->a;
                uint8_t value6 = BUS8(c, (db << 0x10) + 0xCF0F);
                if (value6 != 0) {
                    uint8_t battle_temp_a42 = RAM8(BATTLE_TEMP_A4);
                    RAM8(BATTLE_TEMP_A6) = (uint8_t)(battle_temp_a42 + 0x48);
                    r->a = (a_all2 >> 8 << 8) | (uint8_t)(battle_temp_a42 + 0x48);
                    r->c = battle_temp_a42 + 0x48 > 0xFF;
                    r->v = ((battle_temp_a42 ^ (uint8_t)(battle_temp_a42 + 0x48)) & ((uint8_t)(battle_temp_a42 + 0x48) ^ 0x48) & 0x80) != 0;
                    r->mf = true;
                    r->xf = false;
                    JSL(c, 0xE1CA, 0xC058F1); /* publish_full_chest_inventory_notice */
                    r->mf = true;
                    r->xf = false;
                    RETURN_RTS(c);
                }
                uint8_t battle_temp_a43 = RAM8(BATTLE_TEMP_A4);
                RAM8(BATTLE_TEMP_A6) = (uint8_t)(battle_temp_a43 + 0x48);
                r->a = (a_all2 >> 8 << 8) | (uint8_t)(battle_temp_a43 + 0x48);
                r->c = battle_temp_a43 + 0x48 > 0xFF;
                r->v = ((battle_temp_a43 ^ (uint8_t)(battle_temp_a43 + 0x48)) & ((uint8_t)(battle_temp_a43 + 0x48) ^ 0x48) & 0x80) != 0;
                r->mf = true;
                r->xf = false;
                JSL(c, 0xE197, 0xC058DB); /* publish_successful_chest_inventory_notice */
                r->mf = true;
                r->xf = false;
                RETURN_RTS(c);
            }
        }
        if ((battle_temp_ac & 0xC0) == 0x80) {
            if (((uint8_t)a_all & 0x3F) < battle_temp_a4) {
                uint8_t value7 = BUS8(c, 0xD03A54 + x_ret);
                uint8_t a3 = value7;
                uint8_t a_hi2 = a_all >> 8;
                uint16_t x2 = x_ret;
                uint16_t y2 = y_ret;
                bool overflow2 = overflow_ret;
                for (;;) {
                    RAM8(BATTLE_TEMP_A4) = a3;
                    if (a3 & 0x80) {
                        uint16_t battle_defender_ptr2 = RAM16(BATTLE_DEFENDER_PTR);
                        BUS8_SET(c, (db << 0x10) + 0xE1C9 + battle_defender_ptr2, (uint8_t)(a3 - 0x80));
                        uint8_t value8 = BUS8(c, (db << 0x10) + 0xCFC0 + (((a_hi2 << 8) | (uint8_t)(a3 - 0x80)) & 0xFF));
                        RAM8(BATTLE_TEMP_A6) = value8;
                        uint8_t value9 = BUS8(c, (db << 0x10) + 0xCFB8 + (((a_hi2 << 8) | (uint8_t)(a3 - 0x80)) & 0xFF));
                        if ((uint8_t)(value9 + 1) < RAM8(BATTLE_TEMP_A6)) {
                            BUS8_SET(c, (db << 0x10) + 0xE1C8 + battle_defender_ptr2, 8);
                            r->mf = true;
                            r->xf = false;
                            r->db = db;
                            r->dp = 0x0300;
                            RETURN_RTS(c);
                        }
                        uint8_t a3_next = 0x40;
                        uint8_t a_hi2_next = 0;
                        uint16_t x2_next = battle_defender_ptr2;
                        uint16_t y2_next = ((a_hi2 << 8) | (uint8_t)(a3 - 0x80)) & 0xFF;
                        bool overflow2_next = ((a3 ^ 0x80) & (a3 ^ (uint8_t)(a3 - 0x80)) & 0x80) != 0;
                        a3 = a3_next;
                        a_hi2 = a_hi2_next;
                        x2 = x2_next;
                        y2 = y2_next;
                        overflow2 = overflow2_next;
                        continue;
                    }
                    r->a = (a_hi2 << 8) | a3;
                    r->x = x2;
                    r->y = y2;
                    r->c = a3 >= 0;
                    r->z = a3 == 0;
                    r->n = a3 & 0x80;
                    r->v = overflow2;
                    r->mf = true;
                    r->xf = false;
                    r->db = db;
                    r->dp = 0x0300;
                    JSL(c, 0xE187, 0xC06420); /* jump_native_inventory_insert_command */
                    uint16_t a_all5 = r->a;
                    uint8_t value10 = BUS8(c, (db << 0x10) + 0xCF0F);
                    if (value10 != 0) {
                        uint8_t battle_temp_a44 = RAM8(BATTLE_TEMP_A4);
                        RAM8(BATTLE_TEMP_A6) = (uint8_t)(battle_temp_a44 + 0x48);
                        r->a = (a_all5 >> 8 << 8) | (uint8_t)(battle_temp_a44 + 0x48);
                        r->c = battle_temp_a44 + 0x48 > 0xFF;
                        r->v = ((battle_temp_a44 ^ (uint8_t)(battle_temp_a44 + 0x48)) & ((uint8_t)(battle_temp_a44 + 0x48) ^ 0x48) & 0x80) != 0;
                        r->mf = true;
                        r->xf = false;
                        JSL(c, 0xE1CA, 0xC058F1); /* publish_full_chest_inventory_notice */
                        r->mf = true;
                        r->xf = false;
                        RETURN_RTS(c);
                    }
                    uint8_t battle_temp_a45 = RAM8(BATTLE_TEMP_A4);
                    RAM8(BATTLE_TEMP_A6) = (uint8_t)(battle_temp_a45 + 0x48);
                    r->a = (a_all5 >> 8 << 8) | (uint8_t)(battle_temp_a45 + 0x48);
                    r->c = battle_temp_a45 + 0x48 > 0xFF;
                    r->v = ((battle_temp_a45 ^ (uint8_t)(battle_temp_a45 + 0x48)) & ((uint8_t)(battle_temp_a45 + 0x48) ^ 0x48) & 0x80) != 0;
                    r->mf = true;
                    r->xf = false;
                    JSL(c, 0xE197, 0xC058DB); /* publish_successful_chest_inventory_notice */
                    r->mf = true;
                    r->xf = false;
                    RETURN_RTS(c);
                }
            }
            uint8_t value11 = BUS8(c, 0xD03A53 + x_ret);
            r->a = ((a_all >> 8 << 8) | value11) & 0xFF;
            r->c = ((uint8_t)a_all & 0x3F) >= battle_temp_a4;
            r->z = (((a_all >> 8 << 8) | value11) & 0xFF) == 0;
            r->n = ((a_all >> 8 << 8) | value11) & 0xFF & 0x8000;
            r->mf = false;
            r->xf = false;
            r->sp -= 4;
            JSL(c, 0xE1E3, 0xC039CF); /* add_or_spend_party_gold_with_saved_context */
            r->sp += 4;
            r->a = ((a_all >> 8 << 8) | value11) & 0xFF;
            r->mf = true;
            r->xf = false;
            JSL(c, 0xE1EB, 0xC058C8); /* publish_chest_gold_amount_notice */
            r->mf = true;
            r->xf = false;
            RETURN_RTS(c);
        }
        if (((uint8_t)a_all & 0x3F) < battle_temp_a4) {
            uint8_t value12 = BUS8(c, 0xD03A54 + x_ret);
            r->a = ((a_all >> 8 << 8) | value12) & 0xFF;
            r->c = ((uint8_t)a_all & 0x3F) >= battle_temp_a4;
            r->z = (((a_all >> 8 << 8) | value12) & 0xFF) == 0;
            r->n = ((a_all >> 8 << 8) | value12) & 0xFF & 0x8000;
            r->mf = false;
            r->xf = false;
            r->sp -= 4;
            JSL(c, 0xE1E3, 0xC039CF); /* add_or_spend_party_gold_with_saved_context */
            r->sp += 4;
            r->a = ((a_all >> 8 << 8) | value12) & 0xFF;
            r->mf = true;
            r->xf = false;
            JSL(c, 0xE1EB, 0xC058C8); /* publish_chest_gold_amount_notice */
            r->mf = true;
            r->xf = false;
            RETURN_RTS(c);
        }
        uint8_t value13 = BUS8(c, 0xD03A53 + x_ret);
        uint8_t a4 = value13;
        uint8_t a_hi3 = a_all >> 8;
        uint16_t x3 = x_ret;
        uint16_t y3 = y_ret;
        bool overflow3 = overflow_ret;
        for (;;) {
            RAM8(BATTLE_TEMP_A4) = a4;
            if (a4 & 0x80) {
                uint16_t battle_defender_ptr3 = RAM16(BATTLE_DEFENDER_PTR);
                BUS8_SET(c, (db << 0x10) + 0xE1C9 + battle_defender_ptr3, (uint8_t)(a4 - 0x80));
                uint8_t value14 = BUS8(c, (db << 0x10) + 0xCFC0 + (((a_hi3 << 8) | (uint8_t)(a4 - 0x80)) & 0xFF));
                RAM8(BATTLE_TEMP_A6) = value14;
                uint8_t value15 = BUS8(c, (db << 0x10) + 0xCFB8 + (((a_hi3 << 8) | (uint8_t)(a4 - 0x80)) & 0xFF));
                if ((uint8_t)(value15 + 1) < RAM8(BATTLE_TEMP_A6)) {
                    BUS8_SET(c, (db << 0x10) + 0xE1C8 + battle_defender_ptr3, 8);
                    r->mf = true;
                    r->xf = false;
                    r->db = db;
                    r->dp = 0x0300;
                    RETURN_RTS(c);
                }
                uint8_t a4_next = 0x40;
                uint8_t a_hi3_next = 0;
                uint16_t x3_next = battle_defender_ptr3;
                uint16_t y3_next = ((a_hi3 << 8) | (uint8_t)(a4 - 0x80)) & 0xFF;
                bool overflow3_next = ((a4 ^ 0x80) & (a4 ^ (uint8_t)(a4 - 0x80)) & 0x80) != 0;
                a4 = a4_next;
                a_hi3 = a_hi3_next;
                x3 = x3_next;
                y3 = y3_next;
                overflow3 = overflow3_next;
                continue;
            }
            r->a = (a_hi3 << 8) | a4;
            r->x = x3;
            r->y = y3;
            r->c = a4 >= 0;
            r->z = a4 == 0;
            r->n = a4 & 0x80;
            r->v = overflow3;
            r->mf = true;
            r->xf = false;
            r->db = db;
            r->dp = 0x0300;
            JSL(c, 0xE187, 0xC06420); /* jump_native_inventory_insert_command */
            uint16_t a_all12 = r->a;
            uint8_t value16 = BUS8(c, (db << 0x10) + 0xCF0F);
            if (value16 != 0) {
                uint8_t battle_temp_a46 = RAM8(BATTLE_TEMP_A4);
                RAM8(BATTLE_TEMP_A6) = (uint8_t)(battle_temp_a46 + 0x48);
                r->a = (a_all12 >> 8 << 8) | (uint8_t)(battle_temp_a46 + 0x48);
                r->c = battle_temp_a46 + 0x48 > 0xFF;
                r->v = ((battle_temp_a46 ^ (uint8_t)(battle_temp_a46 + 0x48)) & ((uint8_t)(battle_temp_a46 + 0x48) ^ 0x48) & 0x80) != 0;
                r->mf = true;
                r->xf = false;
                JSL(c, 0xE1CA, 0xC058F1); /* publish_full_chest_inventory_notice */
                r->mf = true;
                r->xf = false;
                RETURN_RTS(c);
            }
            uint8_t battle_temp_a47 = RAM8(BATTLE_TEMP_A4);
            RAM8(BATTLE_TEMP_A6) = (uint8_t)(battle_temp_a47 + 0x48);
            r->a = (a_all12 >> 8 << 8) | (uint8_t)(battle_temp_a47 + 0x48);
            r->c = battle_temp_a47 + 0x48 > 0xFF;
            r->v = ((battle_temp_a47 ^ (uint8_t)(battle_temp_a47 + 0x48)) & ((uint8_t)(battle_temp_a47 + 0x48) ^ 0x48) & 0x80) != 0;
            r->mf = true;
            r->xf = false;
            JSL(c, 0xE197, 0xC058DB); /* publish_successful_chest_inventory_notice */
            r->mf = true;
            r->xf = false;
            RETURN_RTS(c);
        }
    }
    uint8_t a5;
    if (((uint8_t)a_all & 0x3F) < battle_temp_a4) {
        uint8_t value17 = BUS8(c, 0xD03A54 + x_ret);
        a5 = value17;
    } else {
        uint8_t value18 = BUS8(c, 0xD03A53 + x_ret);
        a5 = value18;
    }
    r->a = ((a_all >> 8 << 8) | a5) & 0xFF;
    r->c = ((uint8_t)a_all & 0x3F) >= battle_temp_a4;
    r->z = (((a_all >> 8 << 8) | a5) & 0xFF) == 0;
    r->n = ((a_all >> 8 << 8) | a5) & 0xFF & 0x8000;
    r->mf = false;
    r->xf = false;
    r->sp -= 4;
    JSL(c, 0xE1E3, 0xC039CF); /* add_or_spend_party_gold_with_saved_context */
    r->sp += 4;
    r->a = ((a_all >> 8 << 8) | a5) & 0xFF;
    r->mf = true;
    r->xf = false;
    JSL(c, 0xE1EB, 0xC058C8); /* publish_chest_gold_amount_notice */
    r->mf = true;
    r->xf = false;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8E12C, SOM_RTS, "hand", select_chest_gold_item_or_weapon_orb_and_publish, 0, 0, 4, 1, 0, 193, 88)
