#include "som_c.h"

/* C8E52F select_actor_status_appearance   [class C, 409 bytes, 185 instructions]
 * Source: src/rom/select_actor_status_appearance.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCZNV.
 */
static void select_actor_status_appearance(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const bool overflow = r->v;
    RAM8(BATTLE_TEMP_A4) = 0;
    if ((RAM8(ACTOR_STATUS_HIGH + x) & 2) != 0) {
        RAM8(BATTLE_TEMP_A4)++;
    }
    if (RAM8(ACTOR_KIND_FLAGS + x) & 0x80) {
        uint8_t value3 = RAM8(ACTOR_STATUS + x);
        uint8_t a5;
        bool overflow6;
        if ((value3 & 0x40) == 0) {
            uint8_t a4;
            bool overflow5;
            if ((value3 & 0x20) == 0) {
                uint8_t value4 = RAM8(ACTOR_STATUS_HIGH + x);
                uint8_t a3;
                bool overflow4;
                if (!(value4 & 0x80)) {
                    uint8_t a2;
                    bool overflow3;
                    if ((value4 & 0x10) == 0) {
                        uint8_t battle_temp_a4 = RAM8(BATTLE_TEMP_A4);
                        uint8_t a1;
                        bool overflow1;
                        if (battle_temp_a4 == 0) {
                            a1 = RAM8(0xE1E7 + x);
                            overflow1 = overflow;
                        } else {
                            uint8_t value6 = RAM8(0xE1E7 + x);
                            a1 = (uint8_t)(value6 + 0x76);
                            overflow1 = ((value6 ^ (uint8_t)(value6 + 0x76)) & ((uint8_t)(value6 + 0x76) ^ 0x76) & 0x80) != 0;
                        }
                        a2 = a1;
                        overflow3 = overflow1;
                    } else {
                        uint8_t value7 = RAM8(0xE1E7 + x);
                        RAM8(BATTLE_TEMP_A6) = (uint8_t)(value7 + 0x70);
                        uint8_t battle_temp_a42 = RAM8(BATTLE_TEMP_A4);
                        bool overflow2;
                        if (battle_temp_a42 == 0) {
                            overflow2 = ((value7 ^ (uint8_t)(value7 + 0x70)) & ((uint8_t)(value7 + 0x70) ^ 0x70) & 0x80) != 0;
                        } else {
                            uint8_t battle_temp_a6 = RAM8(BATTLE_TEMP_A6);
                            RAM8(BATTLE_TEMP_A6) = (uint8_t)(battle_temp_a6 + 3);
                            overflow2 = ((battle_temp_a6 ^ (uint8_t)(battle_temp_a6 + 3)) & ((uint8_t)(battle_temp_a6 + 3) ^ 3) & 0x80) != 0;
                        }
                        a2 = RAM8(BATTLE_TEMP_A6);
                        overflow3 = overflow2;
                    }
                    a3 = a2;
                    overflow4 = overflow3;
                } else {
                    uint8_t value8 = RAM8(0x0381);
                    a3 = (uint8_t)(value8 + 0xE4);
                    overflow4 = ((value8 ^ (uint8_t)(value8 + 0xE4)) & ((uint8_t)(value8 + 0xE4) ^ 0xE4) & 0x80) != 0;
                }
                a4 = a3;
                overflow5 = overflow4;
            } else {
                uint8_t battle_temp_a43 = RAM8(BATTLE_TEMP_A4);
                a4 = (uint8_t)(battle_temp_a43 + 0xEE);
                overflow5 = (((uint8_t)(battle_temp_a43 + 0xEE) ^ 0xEE) & (battle_temp_a43 ^ (uint8_t)(battle_temp_a43 + 0xEE)) & 0x80) != 0;
            }
            a5 = a4;
            overflow6 = overflow5;
        } else {
            uint8_t battle_temp_a44 = RAM8(BATTLE_TEMP_A4);
            a5 = (uint8_t)(battle_temp_a44 + 0xEC);
            overflow6 = (((uint8_t)(battle_temp_a44 + 0xEC) ^ 0xEC) & (battle_temp_a44 ^ (uint8_t)(battle_temp_a44 + 0xEC)) & 0x80) != 0;
        }
        uint8_t value9 = RAM8(0xE180 + x);
        bool zero1;
        bool negative1;
        if (a5 == value9) {
            zero1 = a5 == value9;
            negative1 = (uint8_t)(a5 - value9) & 0x80;
        } else {
            RAM8(0xE180 + x) = a5;
            uint8_t value10 = RAM8(0xE1FA + x);
            RAM8(0xE1FA + x) = value10 | 1;
            zero1 = (value10 | 1) == 0;
            negative1 = (value10 | 1) & 0x80;
        }
        r->c = a5 >= value9;
        r->z = zero1;
        r->n = negative1;
        r->v = overflow6;
        RETURN_RTS(c);
    }
    uint8_t value11 = RAM8(ACTOR_STATUS_HIGH + x);
    if (!(value11 & 0x80)) {
        if ((RAM8(ACTOR_STATUS + x) & 0x20) == 0) {
            if ((value11 & 8) == 0) {
                uint8_t value13 = RAM8(0xE1E7 + x);
                uint8_t value14 = RAM8(0xE180 + x);
                bool zero2;
                bool negative2;
                if (value13 == value14) {
                    zero2 = value13 == value14;
                    negative2 = (uint8_t)(value13 - value14) & 0x80;
                } else {
                    RAM8(0xE180 + x) = value13;
                    uint8_t value15 = RAM8(0xE1FA + x);
                    RAM8(0xE1FA + x) = value15 | 1;
                    zero2 = (value15 | 1) == 0;
                    negative2 = (value15 | 1) & 0x80;
                }
                r->c = value13 >= value14;
                r->z = zero2;
                r->n = negative2;
                RETURN_RTS(c);
            }
            r->a = (a_hi << 8) | value11;
            r->z = (value11 & 8) == 0;
            r->n = value11 & 0x80;
            { const uint16_t sp_call = r->sp; JSL(c, 0xE5C0, 0xC0389C); GUARD_JSL(c, sp_call, 0xE5C0); } /* random_byte_long_wrapper */
            bool x_ret = r->xf;
            uint16_t a_all = r->a;
            uint16_t y_ret = r->y;
            if (x_ret) {
                uint8_t value16 = BUS8(c, 0xC8E5F3 + (a_all & 7));
                uint8_t battle_defender_ptr = RAM8(BATTLE_DEFENDER_PTR);
                RAM8(0xE180 + battle_defender_ptr) = value16;
                uint8_t value17 = RAM8(0xE1FA + battle_defender_ptr);
                RAM8(0xE1FA + battle_defender_ptr) = value17 | 7;
                r->a = value17 | 7;
                r->x = battle_defender_ptr;
                r->y = (uint8_t)y_ret;
                r->z = (value17 | 7) == 0;
                r->n = (value17 | 7) & 0x80;
                r->mf = 1;
                r->xf = 1;
                { const uint16_t sp_call = r->sp; JSL(c, 0xE5DD, 0xC04530); GUARD_JSL(c, sp_call, 0xE5DD); } /* rebuild_actor_attributes_native */
                uint16_t dp_ret = r->dp;
                uint8_t db_ret = r->db;
                bool m_ret2 = r->mf;
                uint16_t x_ret4 = r->x;
                if (m_ret2) {
                    uint8_t value18 = BUS8_RDP(c, (db_ret << 0x10) + 0xE1E8 + x_ret4);
                    BUS8_SET(c, (uint16_t)(dp_ret + 0xA4), value18);
                    uint8_t value19 = BUS8_RDP(c, (db_ret << 0x10) + 0xE1E4 + x_ret4);
                    if (value19 & 0x80) {
                        uint8_t value20 = BUS8_RDP(c, (db_ret << 0x10) + 0xE1E9 + x_ret4);
                        BUS8_SET(c, (uint16_t)(dp_ret + 0xA4), value20);
                    }
                    uint8_t value21 = BUS8_RDP(c, (uint16_t)(dp_ret + 0xA4));
                    BUS8_SET(c, (db_ret << 0x10) + 0xE1E3 + x_ret4, value21);
                    r->z = value21 == 0;
                    r->n = value21 & 0x80;
                    r->mf = 1;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    uint16_t value22 = BUS16_RDP(c, (db_ret << 0x10) + 0xE1E8 + x_ret4);
                    BUS16_SET(c, (uint16_t)(dp_ret + 0xA4), value22);
                    uint16_t value23 = BUS16_RDP(c, (db_ret << 0x10) + 0xE1E4 + x_ret4);
                    uint8_t a_hi1;
                    if (!(value23 & 0x8000)) {
                        a_hi1 = value23 >> 8;
                    } else {
                        uint16_t value24 = BUS16_RDP(c, (db_ret << 0x10) + 0xE1E9 + x_ret4);
                        BUS16_SET(c, (uint16_t)(dp_ret + 0xA4), value24);
                        a_hi1 = value24 >> 8;
                    }
                    uint16_t value25 = BUS16_RDP(c, (uint16_t)(dp_ret + 0xA4));
                    BUS16_SET(c, (db_ret << 0x10) + 0xE1E3 + x_ret4, value25);
                    r->a = value25;
                    r->z = value25 == 0;
                    r->n = value25 & 0x8000;
                    r->mf = 0;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            } else {
                uint8_t value26 = BUS8(c, 0xC8E5F3 + (a_all & 7));
                uint16_t battle_defender_ptr2 = RAM16(BATTLE_DEFENDER_PTR);
                RAM8(0xE180 + battle_defender_ptr2) = value26;
                uint8_t value27 = RAM8(0xE1FA + battle_defender_ptr2);
                RAM8(0xE1FA + battle_defender_ptr2) = value27 | 7;
                r->a = value27 | 7;
                r->x = battle_defender_ptr2;
                r->z = (value27 | 7) == 0;
                r->n = (value27 | 7) & 0x80;
                r->mf = 1;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSL(c, 0xE5DD, 0xC04530); GUARD_JSL(c, sp_call, 0xE5DD); } /* rebuild_actor_attributes_native */
                uint16_t dp_ret2 = r->dp;
                uint8_t db_ret2 = r->db;
                bool m_ret3 = r->mf;
                uint16_t x_ret6 = r->x;
                if (m_ret3) {
                    uint8_t value28 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xE1E8 + x_ret6);
                    BUS8_SET(c, (uint16_t)(dp_ret2 + 0xA4), value28);
                    uint8_t value29 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xE1E4 + x_ret6);
                    if (value29 & 0x80) {
                        uint8_t value30 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xE1E9 + x_ret6);
                        BUS8_SET(c, (uint16_t)(dp_ret2 + 0xA4), value30);
                    }
                    uint8_t value31 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 0xA4));
                    BUS8_SET(c, (db_ret2 << 0x10) + 0xE1E3 + x_ret6, value31);
                    r->z = value31 == 0;
                    r->n = value31 & 0x80;
                    r->mf = 1;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    uint16_t value32 = BUS16_RDP(c, (db_ret2 << 0x10) + 0xE1E8 + x_ret6);
                    BUS16_SET(c, (uint16_t)(dp_ret2 + 0xA4), value32);
                    uint16_t value33 = BUS16_RDP(c, (db_ret2 << 0x10) + 0xE1E4 + x_ret6);
                    uint8_t a_hi2;
                    if (!(value33 & 0x8000)) {
                        a_hi2 = value33 >> 8;
                    } else {
                        uint16_t value34 = BUS16_RDP(c, (db_ret2 << 0x10) + 0xE1E9 + x_ret6);
                        BUS16_SET(c, (uint16_t)(dp_ret2 + 0xA4), value34);
                        a_hi2 = value34 >> 8;
                    }
                    uint16_t value35 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 0xA4));
                    BUS16_SET(c, (db_ret2 << 0x10) + 0xE1E3 + x_ret6, value35);
                    r->a = value35;
                    r->z = value35 == 0;
                    r->n = value35 & 0x8000;
                    r->mf = 0;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            }
        }
        uint8_t value36 = RAM8(0xE180 + x);
        bool zero3;
        bool negative3;
        if (value36 == 0x83) {
            zero3 = value36 == 0x83;
            negative3 = (uint8_t)(0x83 - value36) & 0x80;
        } else {
            RAM8(0xE180 + x) = 0x83;
            uint8_t value37 = RAM8(0xE1FA + x);
            RAM8(0xE1FA + x) = value37 | 1;
            zero3 = (value37 | 1) == 0;
            negative3 = (value37 | 1) & 0x80;
        }
        r->c = value36 <= 0x83;
        r->z = zero3;
        r->n = negative3;
        RETURN_RTS(c);
    }
    r->z = value11 == 0;
    r->n = value11 & 0x80;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8E52F, SOM_RTS, "gen", select_actor_status_appearance, 0, L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 421, 185)
