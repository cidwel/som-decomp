#include "som_c.h"

/* D0D3F0 select_complete_native_menu_description_script   [class B, 320 bytes, 139 instructions]
 * Source: src/rom/select_complete_native_menu_description_script.s
 * Documented in docs/event-menu-text-tick.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: BYCV.
 */
static void select_complete_native_menu_description_script(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t y = r->y;
    const uint8_t db = r->db;
    uint8_t value = BUS8_RDP(c, (db << 0x10) + 0x1803);
    if ((value & 0x20) == 0) {
        uint8_t value2 = BUS8_RDP(c, (db << 0x10) + 0x1847);
        if ((uint8_t)(value2 - 1) != 0) {
            uint16_t value3 = BUS16_RDP(c, (db << 0x10) + 0x1809);
            BUS16_SET(c, (db << 0x10) + 0x1859, (uint16_t)(((value3 & 0xFF) << 1) + 0xD564));
            uint8_t value4 = BUS8_RDP(c, (db << 0x10) + 0x1809);
            if ((uint8_t)(value4 - 1) == 0) {
                BUS16_SET(c, (db << 0x10) + 0x19D2, 0x56);
                uint16_t value5 = BUS16_RDP(c, (db << 0x10) + 0x1803);
                uint8_t a1;
                uint8_t a_hi2;
                bool carry1;
                bool overflow1;
                if ((value5 & 0x80) != 0) {
                    r->a = value5 & 0x80;
                    r->x = (uint16_t)(((value3 & 0xFF) << 1) + 0xD564);
                    r->c = ((value3 & 0xFF) << 1) + 0xD564 > 0xFFFF;
                    r->z = (value5 & 0x80) == 0;
                    r->n = value5 & 0x80 & 0x8000;
                    r->v = ((((value3 & 0xFF) << 1) ^ (uint16_t)(((value3 & 0xFF) << 1) + 0xD564)) & ((uint16_t)(((value3 & 0xFF) << 1) + 0xD564) ^ 0xD564) & 0x8000) != 0;
                    r->mf = 0;
                    { const uint16_t sp_call = r->sp; JSL(c, 0xD50E, 0xD0CE5D); GUARD_JSL(c, sp_call, 0xD50E); } /* publish_selected_equipment_description_row */
                    uint16_t a_all = r->a;
                    bool carry_ret = r->c;
                    bool overflow_ret = r->v;
                    a1 = (uint8_t)a_all;
                    a_hi2 = a_all >> 8;
                    carry1 = carry_ret;
                    overflow1 = overflow_ret;
                } else {
                    uint16_t value6 = BUS16_RDP(c, (db << 0x10) + 0x1808);
                    uint8_t a_hi1;
                    uint16_t x1;
                    if ((value6 & 1) == 0) {
                        r->a = value6 & 1;
                        r->x = (uint16_t)(((value3 & 0xFF) << 1) + 0xD564);
                        r->c = ((value3 & 0xFF) << 1) + 0xD564 > 0xFFFF;
                        r->z = (value6 & 1) == 0;
                        r->n = value6 & 1 & 0x8000;
                        r->v = ((((value3 & 0xFF) << 1) ^ (uint16_t)(((value3 & 0xFF) << 1) + 0xD564)) & ((uint16_t)(((value3 & 0xFF) << 1) + 0xD564) ^ 0xD564) & 0x8000) != 0;
                        r->mf = 0;
                        { const uint16_t sp_call = r->sp; JSL(c, 0xD500, 0xD0D0DA); GUARD_JSL(c, sp_call, 0xD500); } /* locate_selected_armor_with_nonzero_level */
                        uint16_t a_all2 = r->a;
                        uint16_t x_ret2 = r->x;
                        a_hi1 = a_all2 >> 8;
                        x1 = x_ret2;
                    } else {
                        r->a = value6 & 1;
                        r->x = (uint16_t)(((value3 & 0xFF) << 1) + 0xD564);
                        r->c = ((value3 & 0xFF) << 1) + 0xD564 > 0xFFFF;
                        r->z = (value6 & 1) == 0;
                        r->n = value6 & 1 & 0x8000;
                        r->v = ((((value3 & 0xFF) << 1) ^ (uint16_t)(((value3 & 0xFF) << 1) + 0xD564)) & ((uint16_t)(((value3 & 0xFF) << 1) + 0xD564) ^ 0xD564) & 0x8000) != 0;
                        r->mf = 0;
                        { const uint16_t sp_call = r->sp; JSL(c, 0xD4FA, 0xD0D0B0); GUARD_JSL(c, sp_call, 0xD4FA); } /* locate_selected_weapon_with_nonzero_level */
                        uint16_t a_all3 = r->a;
                        uint16_t x_ret3 = r->x;
                        a_hi1 = a_all3 >> 8;
                        x1 = x_ret3;
                    }
                    a1 = (uint8_t)((uint8_t)x1 + 0x2A);
                    a_hi2 = x1 >> 8;
                    carry1 = (uint8_t)x1 + 0x2A > 0xFF;
                    overflow1 = (((uint8_t)x1 ^ (uint8_t)((uint8_t)x1 + 0x2A)) & ((uint8_t)((uint8_t)x1 + 0x2A) ^ 0x2A) & 0x80) != 0;
                }
                BUS8_SET(c, (db << 0x10) + 0x19D3, a1);
                r->a = (a_hi2 << 8) | a1;
                r->c = carry1;
                r->v = overflow1;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            if ((uint8_t)(value4 - 2) == 0) {
                uint16_t value7 = BUS16_RDP(c, (db << 0x10) + 0x1859);
                uint8_t value8 = BUS8(c, 0xD00001 + value7);
                uint8_t value9 = BUS8_RDP(c, (db << 0x10) + 0x19D3);
                BUS8_SET(c, (db << 0x10) + 0x19D3, (uint8_t)(value8 + value9));
                r->a = ((uint16_t)(((value3 & 0xFF) << 1) + 0xD564) >> 8 << 8) | (uint8_t)(value8 + value9);
                r->c = value8 + value9 > 0xFF;
                r->v = ((value8 ^ (uint8_t)(value8 + value9)) & (value9 ^ (uint8_t)(value8 + value9)) & 0x80) != 0;
                r->mf = 0;
                RETURN_RTS(c);
            }
            if ((uint8_t)(value4 - 3) != 0) {
                uint8_t value10 = BUS8(c, 0xD00000 + (uint16_t)(((value3 & 0xFF) << 1) + 0xD564));
                uint8_t value11 = BUS8_RDP(c, (db << 0x10) + 0x19D3);
                uint8_t value12 = BUS8_RDP(c, (db << 0x10) + 0x1809);
                uint8_t a2;
                uint8_t a_hi3;
                uint8_t y1;
                bool overflow2;
                if (value12 == 0) {
                    a2 = (uint8_t)(value10 + value11);
                    a_hi3 = (uint16_t)(((value3 & 0xFF) << 1) + 0xD564) >> 8;
                    y1 = (uint8_t)y;
                    overflow2 = ((value10 ^ (uint8_t)(value10 + value11)) & (value11 ^ (uint8_t)(value10 + value11)) & 0x80) != 0;
                } else {
                    uint8_t value13 = BUS8_RDP(c, (db << 0x10) + 0x19D3);
                    r->a = ((uint16_t)(((value3 & 0xFF) << 1) + 0xD564) >> 8 << 8) | (uint8_t)((uint8_t)(value10 + value11) - value13);
                    r->x = value12;
                    r->y = (uint8_t)y;
                    r->c = (uint8_t)(value10 + value11) >= value13;
                    r->z = (uint8_t)((uint8_t)(value10 + value11) - value13) == 0;
                    r->n = (uint8_t)((uint8_t)(value10 + value11) - value13) & 0x80;
                    r->v = (((uint8_t)(value10 + value11) ^ value13) & ((uint8_t)(value10 + value11) ^ (uint8_t)((uint8_t)(value10 + value11) - value13)) & 0x80) != 0;
                    r->xf = 1;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xD4A3, 0xD0D530); GUARD_JSR(c, sp_call, 0xD4A3); } /* add_wrapped_menu_row_to_inventory_label_offset */
                    uint16_t a_all4 = r->a;
                    uint8_t y_ret = r->y;
                    bool overflow_ret2 = r->v;
                    a2 = (uint8_t)a_all4;
                    a_hi3 = a_all4 >> 8;
                    y1 = y_ret;
                    overflow2 = overflow_ret2;
                }
                uint8_t value14 = RAM8(0xCC00 + (uint8_t)((a_hi3 << 8) | a2));
                if (value14 < 0xFE) {
                    uint8_t value15 = BUS8_RDP(c, (db << 0x10) + 0x1809);
                    uint8_t a3;
                    if (value15 != 0) {
                        a3 = value14 & 0x3F;
                    } else {
                        a3 = value14 & 0x1F;
                    }
                    BUS8_SET(c, (db << 0x10) + 0x19D3, a3);
                    uint16_t value16 = BUS16_RDP(c, (db << 0x10) + 0x1859);
                    uint8_t value17 = BUS8(c, 0xD00001 + value16);
                    uint8_t value18 = BUS8_RDP(c, (db << 0x10) + 0x19D3);
                    BUS8_SET(c, (db << 0x10) + 0x19D3, (uint8_t)(value17 + value18));
                    r->a = (a_hi3 << 8) | (uint8_t)(value17 + value18);
                    r->y = value15;
                    r->c = value17 + value18 > 0xFF;
                    r->v = ((value17 ^ (uint8_t)(value17 + value18)) & (value18 ^ (uint8_t)(value17 + value18)) & 0x80) != 0;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                if (value14 != 0xFF) {
                    BUS8_SET(c, (db << 0x10) + 0x19D3, 0x9B);
                    r->a = (a_hi3 << 8) | 0x9B;
                    r->y = y1;
                    r->c = value14 >= 0xFF;
                    r->v = overflow2;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                uint8_t value19 = BUS8_RDP(c, (db << 0x10) + 0x1847);
                if (value19 == 0) {
                    BUS8_SET(c, (db << 0x10) + 0x19D3, 0x9B);
                    r->a = (a_hi3 << 8) | 0x9B;
                    r->y = y1;
                    r->c = value14 >= 0xFF;
                    r->v = overflow2;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                BUS8_SET(c, (db << 0x10) + 0x19D2, 0);
                r->a = (a_hi3 << 8) | value19;
                r->y = y1;
                r->c = value14 >= 0xFF;
                r->v = overflow2;
                r->mf = 1;
                r->xf = 1;
                RETURN_RTS(c);
            }
            uint8_t value20 = BUS8(c, 0xD00000 + (uint16_t)(((value3 & 0xFF) << 1) + 0xD564));
            uint8_t value21 = BUS8_RDP(c, (db << 0x10) + 0x19D3);
            uint8_t a4 = value20;
            uint8_t a_hi4 = (uint16_t)(((value3 & 0xFF) << 1) + 0xD564) >> 8;
            uint8_t x2 = (uint8_t)(((uint16_t)(((value3 & 0xFF) << 1) + 0xD564) >> 8 << 8) | value20);
            uint8_t y2 = value21;
            bool carry2 = ((value3 & 0xFF) << 1) + 0xD564 > 0xFFFF;
            for (;;) {
                uint8_t value22 = RAM8(0xCC00 + x2);
                if (value22 == 0xFF) {
                    a4 = value22;
                    x2 = (uint8_t)(x2 + 1);
                    carry2 = value22 >= 0xFF;
                    continue;
                }
                a4 = value22;
                x2 = (uint8_t)(x2 + 1);
                y2 = (uint8_t)(y2 - 1);
                carry2 = value22 >= 0xFF;
                if (!(!(y2 & 0x80))) break;
            }
            r->a = a_hi4 << 8 | (a4 & 0x3F);
            r->x = (uint8_t)(x2 - 1);
            r->y = y2;
            r->c = carry2;
            r->z = (uint8_t)(x2 - 1) == 0;
            r->n = (uint8_t)(x2 - 1) & 0x80;
            r->v = ((((value3 & 0xFF) << 1) ^ (uint16_t)(((value3 & 0xFF) << 1) + 0xD564)) & ((uint16_t)(((value3 & 0xFF) << 1) + 0xD564) ^ 0xD564) & 0x8000) != 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSL(c, 0xD52D, 0xD0D1FB); GUARD_JSL(c, sp_call, 0xD52D); } /* offset_armor_inventory_description_by_position */
            uint16_t a_all5 = r->a;
            BUS8_SET(c, (db << 0x10) + 0x19D3, (uint8_t)a_all5);
            uint16_t value23 = BUS16_RDP(c, (db << 0x10) + 0x1859);
            uint8_t value24 = BUS8(c, 0xD00001 + value23);
            uint8_t value25 = BUS8_RDP(c, (db << 0x10) + 0x19D3);
            BUS8_SET(c, (db << 0x10) + 0x19D3, (uint8_t)(value24 + value25));
            r->c = value24 + value25 > 0xFF;
            r->v = ((value24 ^ (uint8_t)(value24 + value25)) & (value25 ^ (uint8_t)(value24 + value25)) & 0x80) != 0;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        uint16_t value26 = BUS16_RDP(c, (db << 0x10) + 0x19D3);
        uint16_t value27 = BUS16_RDP(c, (db << 0x10) + 0x183C);
        uint16_t value28 = BUS16(c, 0xD80000 + (uint16_t)((value26 & 0xFF) + value27));
        uint8_t a5;
        bool carry3;
        bool overflow3;
        if ((uint8_t)value28 >= 0xBA) {
            a5 = (uint8_t)((uint8_t)value28 - 0x32);
            carry3 = (uint8_t)value28 >= 0x32;
            overflow3 = (((uint8_t)value28 ^ 0x32) & ((uint8_t)value28 ^ (uint8_t)((uint8_t)value28 - 0x32)) & 0x80) != 0;
        } else {
            a5 = (uint8_t)((uint8_t)value28 + 0xCD);
            carry3 = (uint8_t)value28 + 0xCD > 0xFF;
            overflow3 = (((uint8_t)value28 ^ (uint8_t)((uint8_t)value28 + 0xCD)) & ((uint8_t)((uint8_t)value28 + 0xCD) ^ 0xCD) & 0x80) != 0;
        }
        BUS8_SET(c, (db << 0x10) + 0x19D3, a5);
        r->a = (value28 >> 8 << 8) | a5;
        r->c = carry3;
        r->v = overflow3;
        r->mf = 0;
        RETURN_RTS(c);
    }
    uint16_t value29 = BUS16_RDP(c, (db << 0x10) + 0x1822);
    uint16_t value30 = BUS16_RDP(c, (uint16_t)(dp + value29));
    if (value30 != 0xFFFF) {
        if (value30 >= 0xE600) {
            BUS16_SET(c, (db << 0x10) + 0x19D2, 0x54);
            uint16_t value31 = RAM16(0x0180 + value30);
            if ((value31 & 0xFF) != 0xEA) {
                BUS16_SET(c, (db << 0x10) + 0x19D3, value31);
                r->a = value31;
                r->c = (value31 & 0xFF) >= 0xEA;
                r->mf = 0;
                RETURN_RTS(c);
            }
            BUS16_SET(c, (db << 0x10) + 0x19D2, 0x5654);
            BUS16_SET(c, (db << 0x10) + 0x19D4, 0);
            r->a = 0x5654;
            r->c = (value31 & 0xFF) >= 0xEA;
            r->mf = 0;
            RETURN_RTS(c);
        }
        BUS16_SET(c, (db << 0x10) + 0x19D2, 0x57);
        BUS16_SET(c, (db << 0x10) + 0x19D3, ((((uint8_t)value30 << 8) | (value30 >> 8)) >> 1) & 3);
        r->a = ((((uint8_t)value30 << 8) | (value30 >> 8)) >> 1) & 3;
        r->c = (((uint8_t)value30 << 8) | (value30 >> 8)) & 0x01;
        r->mf = 0;
        RETURN_RTS(c);
    }
    BUS16_SET(c, (db << 0x10) + 0x19D2, 0x9C55);
    r->a = 0x9C55;
    r->c = value30 >= 0xFFFF;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0D3F0, SOM_RTS, "gen", select_complete_native_menu_description_script, 0, L_B | L_Y | L_C | L_V, 1, 1, 0, 320, 139)
