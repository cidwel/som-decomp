#include "som_c.h"

/* C2B287 project_wrapped_ui_target_with_native_perspective   [class C, 430 bytes, 232 instructions]
 * Source: src/rom/project_wrapped_ui_target_with_native_perspective.s
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABC.
 */
static void project_wrapped_ui_target_with_native_perspective(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t dp = r->dp;
    const uint8_t db = r->db;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0xFA));
    BUS16_SET(c, dp, value & 0x0FFF);
    uint16_t value2 = BUS16_RDP(c, (uint16_t)(dp + 0xFC));
    BUS16_SET(c, (uint16_t)(dp + 2), value2 & 0x0FFF);
    uint16_t value3 = BUS16_RDP(c, (uint16_t)(dp + 0x0C));
    uint16_t value4 = BUS16_RDP(c, dp);
    uint8_t a3;
    uint8_t a_hi3;
    if (!((uint16_t)(value3 - value4) & 0x8000)) {
        uint8_t a1;
        uint8_t a_hi1;
        if ((uint16_t)(value3 - value4) < 0x0800) {
            a1 = (uint8_t)(value3 - value4);
            a_hi1 = (uint16_t)(value3 - value4) >> 8;
        } else {
            a1 = (uint8_t)((uint16_t)(value3 - value4) - 0x1000 - ((uint16_t)(value3 - value4) >= 0x0800 ^ 1));
            a_hi1 = (uint16_t)((uint16_t)(value3 - value4) - 0x1000 - ((uint16_t)(value3 - value4) >= 0x0800 ^ 1)) >> 8;
        }
        a3 = a1;
        a_hi3 = a_hi1;
    } else {
        uint8_t a2;
        uint8_t a_hi2;
        if ((uint16_t)(value3 - value4) >= 0xF801) {
            a2 = (uint8_t)(value3 - value4);
            a_hi2 = (uint16_t)(value3 - value4) >> 8;
        } else {
            a2 = (uint8_t)((uint16_t)(value3 - value4) + 0x1000 + ((uint16_t)(value3 - value4) >= 0xF801));
            a_hi2 = (uint16_t)((uint16_t)(value3 - value4) + 0x1000 + ((uint16_t)(value3 - value4) >= 0xF801)) >> 8;
        }
        a3 = a2;
        a_hi3 = a_hi2;
    }
    BUS16_SET(c, (uint16_t)(dp + 0x0C), (a_hi3 << 8) | a3);
    uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp + 0x0E));
    uint16_t value6 = BUS16_RDP(c, (uint16_t)(dp + 2));
    uint8_t a6;
    uint8_t a_hi6;
    if (!((uint16_t)(value5 - value6) & 0x8000)) {
        uint8_t a4;
        uint8_t a_hi4;
        if ((uint16_t)(value5 - value6) < 0x0800) {
            a4 = (uint8_t)(value5 - value6);
            a_hi4 = (uint16_t)(value5 - value6) >> 8;
        } else {
            a4 = (uint8_t)((uint16_t)(value5 - value6) - 0x1000 - ((uint16_t)(value5 - value6) >= 0x0800 ^ 1));
            a_hi4 = (uint16_t)((uint16_t)(value5 - value6) - 0x1000 - ((uint16_t)(value5 - value6) >= 0x0800 ^ 1)) >> 8;
        }
        a6 = a4;
        a_hi6 = a_hi4;
    } else {
        uint8_t a5;
        uint8_t a_hi5;
        if ((uint16_t)(value5 - value6) >= 0xF801) {
            a5 = (uint8_t)(value5 - value6);
            a_hi5 = (uint16_t)(value5 - value6) >> 8;
        } else {
            a5 = (uint8_t)((uint16_t)(value5 - value6) + 0x1000 + ((uint16_t)(value5 - value6) >= 0xF801));
            a_hi5 = (uint16_t)((uint16_t)(value5 - value6) + 0x1000 + ((uint16_t)(value5 - value6) >= 0xF801)) >> 8;
        }
        a6 = a5;
        a_hi6 = a_hi5;
    }
    BUS16_SET(c, (uint16_t)(dp + 0x0E), (a_hi6 << 8) | a6);
    uint16_t value7 = BUS16_RDP(c, (uint16_t)(dp + 0xF6));
    uint16_t value8 = BUS16_RDP(c, (uint16_t)(dp + 0xF6));
    uint16_t x1;
    uint16_t y1;
    if ((value8 & 0x0100) == 0) {
        x1 = (((value7 & 0xFF) << 1) ^ 0x01FE) + 2;
        y1 = (value7 & 0xFF) << 1;
    } else {
        RAM8(0x0000 + sp0) = (value7 & 0xFF) << 1 >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)((value7 & 0xFF) << 1);
        RAM8(0x0000 + sp0 - 2) = (((value7 & 0xFF) << 1) ^ 0x01FE) + 2 >> 8;
        RAM8(0x0000 + sp0 - 3) = (uint8_t)((((value7 & 0xFF) << 1) ^ 0x01FE) + 2);
        x1 = (value7 & 0xFF) << 1;
        y1 = (((value7 & 0xFF) << 1) ^ 0x01FE) + 2;
    }
    uint16_t value9 = BUS16_RDP(c, (db << 0x10) + 0xFD22 + y1);
    BUS16_SET(c, (uint16_t)(dp + 2), value9);
    uint16_t value10 = BUS16_RDP(c, (db << 0x10) + 0xFD22 + x1);
    BUS16_SET(c, (uint16_t)(dp + 4), value10);
    uint8_t value11 = BUS8_RDP(c, (uint16_t)(dp + 3));
    uint8_t a_hi8;
    if (value11 == 0) {
        uint8_t value12 = BUS8_RDP(c, (uint16_t)(dp + 5));
        uint8_t a_hi7;
        if (value12 == 0) {
            uint8_t value13 = BUS8_RDP(c, (uint16_t)(dp + 4));
            BUS8_SET(c, (db << 0x10) + 0x4202, value13);
            uint16_t value14 = BUS16_RDP(c, (uint16_t)(dp + 2));
            r->a = (value10 >> 8 << 8) | value13;
            r->x = x1;
            r->y = value14;
            r->c = value7 & 0xFF & 0x8000;
            r->z = value14 == 0;
            r->n = value14 & 0x8000;
            r->v = value8 & 0x4000;
            { const uint16_t sp_call = r->sp; JSR(c, 0xB326, 0xC2B444); GUARD_JSR(c, sp_call, 0xB326); } /* multiply_ui_target_pair_in_first_coefficient_order */
            uint16_t a_all = r->a;
            BUS8_SET(c, (db << 0x10) + 0x4202, (uint8_t)value14);
            r->a = (a_all >> 8 << 8) | (uint8_t)value14;
            r->z = (uint8_t)value14 == 0;
            r->n = (uint8_t)value14 & 0x80;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0xB32D, 0xC2B435); GUARD_JSR(c, sp_call, 0xB32D); } /* multiply_ui_target_pair_in_second_coefficient_order */
            uint16_t a_all2 = r->a;
            a_hi7 = a_all2 >> 8;
        } else {
            uint8_t value15 = BUS8_RDP(c, (uint16_t)(dp + 2));
            BUS8_SET(c, (db << 0x10) + 0x4202, value15);
            r->a = (value10 >> 8 << 8) | value15;
            r->x = x1;
            r->y = y1;
            r->c = value7 & 0xFF & 0x8000;
            r->z = value15 == 0;
            r->n = value15 & 0x80;
            r->v = value8 & 0x4000;
            { const uint16_t sp_call = r->sp; JSR(c, 0xB312, 0xC2B435); GUARD_JSR(c, sp_call, 0xB312); } /* multiply_ui_target_pair_in_second_coefficient_order */
            uint16_t a_all3 = r->a;
            uint16_t value16 = BUS16_RDP(c, (uint16_t)(dp + 0x0C));
            BUS16_SET(c, (uint16_t)(dp + 2), value16);
            uint16_t value17 = BUS16_RDP(c, (uint16_t)(dp + 0x0E));
            BUS16_SET(c, (uint16_t)(dp + 6), value17);
            a_hi7 = a_all3 >> 8;
        }
        a_hi8 = a_hi7;
    } else {
        uint8_t value18 = BUS8_RDP(c, (uint16_t)(dp + 4));
        BUS8_SET(c, (db << 0x10) + 0x4202, value18);
        r->a = (value10 >> 8 << 8) | value18;
        r->x = x1;
        r->y = y1;
        r->c = value7 & 0xFF & 0x8000;
        r->z = value18 == 0;
        r->n = value18 & 0x80;
        r->v = value8 & 0x4000;
        { const uint16_t sp_call = r->sp; JSR(c, 0xB2FC, 0xC2B444); GUARD_JSR(c, sp_call, 0xB2FC); } /* multiply_ui_target_pair_in_first_coefficient_order */
        uint16_t a_all4 = r->a;
        uint16_t value19 = BUS16_RDP(c, (uint16_t)(dp + 0x0C));
        BUS16_SET(c, dp, value19);
        uint16_t value20 = BUS16_RDP(c, (uint16_t)(dp + 0x0E));
        BUS16_SET(c, (uint16_t)(dp + 4), value20);
        a_hi8 = a_all4 >> 8;
    }
    uint16_t value21 = BUS16_RDP(c, (uint16_t)(dp + 0xF7));
    uint8_t a9;
    uint8_t a_hi11;
    bool negative3;
    if (!(value21 & 0x01)) {
        uint8_t a7;
        uint8_t a_hi9;
        bool negative1;
        if (!(value21 >> 1 & 0x01)) {
            uint16_t value22 = BUS16_RDP(c, (uint16_t)(dp + 2));
            uint16_t value23 = BUS16_RDP(c, (uint16_t)(dp + 4));
            BUS16_SET(c, (uint16_t)(dp + 2), (uint16_t)(value22 - value23));
            uint16_t value24 = BUS16_RDP(c, (uint16_t)(dp + 6));
            uint16_t value25 = BUS16_RDP(c, dp);
            a7 = (uint8_t)(value24 + value25);
            a_hi9 = (uint16_t)(value24 + value25) >> 8;
            negative1 = (uint16_t)(value24 + value25) & 0x8000;
        } else {
            uint16_t value26 = BUS16_RDP(c, (uint16_t)(dp + 4));
            uint16_t value27 = BUS16_RDP(c, (uint16_t)(dp + 2));
            BUS16_SET(c, (uint16_t)(dp + 2), (uint16_t)(value26 - value27));
            uint16_t value28 = BUS16_RDP(c, (uint16_t)(dp + 6));
            uint16_t value29 = BUS16_RDP(c, dp);
            a7 = (uint8_t)(((uint16_t)(value28 + value29) ^ 0xFFFF) + 1);
            a_hi9 = (uint16_t)(((uint16_t)(value28 + value29) ^ 0xFFFF) + 1) >> 8;
            negative1 = (uint16_t)(((uint16_t)(value28 + value29) ^ 0xFFFF) + 1) & 0x8000;
        }
        a9 = a7;
        a_hi11 = a_hi9;
        negative3 = negative1;
    } else {
        uint8_t a8;
        uint8_t a_hi10;
        bool negative2;
        if (value21 >> 1 & 0x01) {
            uint16_t value30 = BUS16_RDP(c, (uint16_t)(dp + 2));
            uint16_t value31 = BUS16_RDP(c, (uint16_t)(dp + 4));
            BUS16_SET(c, (uint16_t)(dp + 2), (uint16_t)(value30 + value31));
            uint16_t value32 = BUS16_RDP(c, (uint16_t)(dp + 6));
            uint16_t value33 = BUS16_RDP(c, dp);
            a8 = (uint8_t)(value32 - value33);
            a_hi10 = (uint16_t)(value32 - value33) >> 8;
            negative2 = (uint16_t)(value32 - value33) & 0x8000;
        } else {
            uint16_t value34 = BUS16_RDP(c, (uint16_t)(dp + 2));
            uint16_t value35 = BUS16_RDP(c, (uint16_t)(dp + 4));
            BUS16_SET(c, (uint16_t)(dp + 2), (uint16_t)(((uint16_t)(value34 + value35) ^ 0xFFFF) + 1));
            uint16_t value36 = BUS16_RDP(c, dp);
            uint16_t value37 = BUS16_RDP(c, (uint16_t)(dp + 6));
            a8 = (uint8_t)(value36 - value37);
            a_hi10 = (uint16_t)(value36 - value37) >> 8;
            negative2 = (uint16_t)(value36 - value37) & 0x8000;
        }
        a9 = a8;
        a_hi11 = a_hi10;
        negative3 = negative2;
    }
    BUS16_SET(c, (uint16_t)(dp + 4), (a_hi11 << 8) | a9);
    if (negative3) {
        if ((uint16_t)((((a_hi11 << 8) | a9) ^ 0xFFFF) + 1) >= 0x0200) {
            r->a = (uint16_t)((((a_hi11 << 8) | a9) ^ 0xFFFF) + 1);
            r->c = 1;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        if ((uint16_t)((((a_hi11 << 8) | a9) ^ 0xFFFF) + 1) < 8) {
            r->a = (uint16_t)((((a_hi11 << 8) | a9) ^ 0xFFFF) + 1);
            r->c = 1;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        BUS16_SET(c, (uint16_t)(dp + 9), (uint16_t)((((a_hi11 << 8) | a9) ^ 0xFFFF) + 1) >> 1);
        uint16_t value38 = BUS16_RDP(c, (uint16_t)(dp + 2));
        uint8_t a10;
        uint8_t a_hi12;
        if (!(value38 & 0x8000)) {
            a10 = (uint8_t)value38;
            a_hi12 = value38 >> 8;
        } else {
            a10 = (uint8_t)((value38 ^ 0xFFFF) + 1);
            a_hi12 = (uint16_t)((value38 ^ 0xFFFF) + 1) >> 8;
        }
        if (((a_hi12 << 8) | a10) >= 0x0150) {
            r->a = (a_hi12 << 8) | a10;
            r->c = 1;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        BUS16_SET(c, dp, ((a_hi12 << 8) | a10) >> 1);
        uint16_t value39 = BUS16_RDP(c, dp);
        BUS16_SET(c, (db << 0x10) + 0x4204, ((uint8_t)(((((a_hi12 << 8) | a10) >> 3) ^ 0xFFFF) + value39 + 1) << 8) | ((uint16_t)(((((a_hi12 << 8) | a10) >> 3) ^ 0xFFFF) + value39 + 1) >> 8));
        uint8_t value40 = BUS8_RDP(c, (uint16_t)(dp + 9));
        uint8_t value41 = BUS8_RDP(c, (uint16_t)(dp + 9));
        BUS8_SET(c, (db << 0x10) + 0x4206, (uint8_t)(((uint8_t)((value40 ^ 0xFF) + 1) >> 3) + value41 + (((uint8_t)((value40 ^ 0xFF) + 1) >> 2) & 1)));
        uint16_t value42 = BUS16_RDP(c, (db << 0x10) + 0x4214);
        if (value42 >= 0x80) {
            r->a = value42;
            r->c = 1;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        uint8_t value43 = BUS8_RDP(c, (uint16_t)(dp + 3));
        uint8_t a11;
        if (!(value43 & 0x80)) {
            a11 = (uint8_t)value42;
        } else {
            a11 = (uint8_t)value42 ^ 0xFF;
        }
        BUS8_SET(c, (uint16_t)(dp + 8), (uint8_t)(a11 + 0x80));
        BUS8_SET(c, (uint16_t)(dp + 0x0A), 0);
        uint8_t value44 = BUS8_RDP(c, (uint16_t)(dp + 0xF8));
        uint8_t value45 = BUS8_RDP(c, (uint16_t)(dp + 0x0B));
        uint8_t a12;
        if (value44 >= value45) {
            a12 = (uint8_t)(value44 - value45);
        } else {
            uint8_t value46 = BUS8_RDP(c, (uint16_t)(dp + 0x0A));
            BUS8_SET(c, (uint16_t)(dp + 0x0A), (uint8_t)(value46 - 1));
            a12 = (uint8_t)(((uint8_t)(value44 - value45) ^ 0xFF) + 1);
        }
        BUS8_SET(c, (db << 0x10) + 0x4204, 0);
        BUS8_SET(c, (db << 0x10) + 0x4205, a12 >> 3);
        uint8_t value47 = BUS8_RDP(c, (uint16_t)(dp + 9));
        BUS8_SET(c, (db << 0x10) + 0x4206, value47);
        uint16_t value48 = BUS16_RDP(c, (db << 0x10) + 0x4214);
        if (value48 < 0x80) {
            uint8_t value49 = BUS8_RDP(c, (uint16_t)(dp + 0x0A));
            if (!(value49 & 0x80)) {
                uint8_t value50 = BUS8_RDP(c, (db << 0x10) + 0x0FD8);
                if ((uint8_t)value48 + value50 > 0xFF) {
                    r->a = (value48 >> 8 << 8) | (uint8_t)((uint8_t)value48 + value50);
                    r->c = 1;
                    r->mf = 1;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                if ((uint8_t)((uint8_t)value48 + value50) < 0x20) {
                    r->a = (value48 >> 8 << 8) | (uint8_t)((uint8_t)((uint8_t)value48 + value50) - 0x20);
                    r->c = 1;
                    r->mf = 1;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                uint8_t value51 = BUS8_RDP(c, (uint16_t)(dp + 9));
                BUS8_SET(c, (uint16_t)(dp + 9), (uint8_t)((uint8_t)((uint8_t)value48 + value50) - 0x20));
                r->a = ((uint8_t)((uint8_t)((uint8_t)value48 + value50) - 0x20) << 8) | ((value51 >> 5) ^ 7);
                r->c = 0;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTS(c);
            }
            uint8_t value52 = BUS8_RDP(c, (db << 0x10) + 0x0FD8);
            if ((uint8_t)(((uint8_t)value48 ^ 0xFF) + value52) & 0x80) {
                r->a = (value48 >> 8 << 8) | (uint8_t)(((uint8_t)value48 ^ 0xFF) + value52);
                r->c = 1;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTS(c);
            }
            if ((uint8_t)(((uint8_t)value48 ^ 0xFF) + value52) < 0x20) {
                r->a = (value48 >> 8 << 8) | (uint8_t)((uint8_t)(((uint8_t)value48 ^ 0xFF) + value52) - 0x20);
                r->c = 1;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTS(c);
            }
            uint8_t value53 = BUS8_RDP(c, (uint16_t)(dp + 9));
            BUS8_SET(c, (uint16_t)(dp + 9), (uint8_t)((uint8_t)(((uint8_t)value48 ^ 0xFF) + value52) - 0x20));
            r->a = ((uint8_t)((uint8_t)(((uint8_t)value48 ^ 0xFF) + value52) - 0x20) << 8) | ((value53 >> 5) ^ 7);
            r->c = 0;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = value48;
        r->c = 1;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = (a_hi11 << 8) | a9;
    r->c = 1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2B287, SOM_RTS, "gen", project_wrapped_ui_target_with_native_perspective, 0, L_A | L_B | L_C, 4, 1, 0, 430, 232)
