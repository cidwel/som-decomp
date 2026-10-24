#include "som_c.h"

static void select_opposing_charge_effect_contact_actor_and_mark_source(SomCtx *c);

/* C2C526 test_charge_effect_contact_or_transfer_native_homing_continuation   [class C, 356 bytes, 179 instructions]
 * Source: src/rom/test_charge_effect_contact_or_transfer_native_homing_continuation.s
 * Documented in docs/actor-charge-effect-update.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void test_charge_effect_contact_or_transfer_native_homing_continuation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp + 2;
    const uint16_t sp_in = r->sp;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC528, 0xC2C4C9); GUARD_JSR(c, sp_call, 0xC528); } /* prepare_auxiliary_sprite_screen_position */
    uint16_t a_all = r->a;
    uint8_t value = RAM8(0xD000 + y);
    if (value < 3) {
        r->a = (a_all >> 8 << 8) | value;
        r->c = value >= 3;
        r->z = value == 3;
        r->n = (uint8_t)(value - 3) & 0x80;
        r->mf = 1;
        r->xf = 0;
        select_opposing_charge_effect_contact_actor_and_mark_source(c); return;
    }
    uint8_t value2 = RAM8(0xD008 + y);
    if (value2 != 0xFF) {
        r->a = (a_all >> 8 << 8) | value2;
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xC54B, select_opposing_charge_effect_contact_actor_and_mark_source, sp_in, 2); GUARD_JSR(c, sp_call, 0xC54B); }
        r->c = 0;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->mf = 1;
    r->xf = 0;
    r->sp += 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC53D, 0xC2C64E); GUARD_JSR(c, sp_call, 0xC53D); } /* test_charge_effect_homing_target_distance_threshold */
    r->sp -= 2;
    uint16_t a_all3 = r->a;
    bool carry_ret3 = r->c;
    if (carry_ret3) {
        uint8_t value5 = RAM8(0xD00A + y);
        uint8_t a1;
        if (value5 + 8 <= 0xFF) {
            a1 = (uint8_t)(value5 + 8);
        } else {
            a1 = (uint8_t)((uint8_t)(value5 + 8) - 8 - (value5 + 8 > 0xFF ^ 1));
        }
        RAM8(0xD00A + y) = a1;
        RAM8(0x0000 + sp0) = x >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
        uint16_t value6 = BUS16(c, 0x00FD22 + ((((a_all3 >> 8 << 8) | a1) & 0xFF) << 1));
        RAM16_SET(0x0002, value6 >> 5);
        uint16_t value7 = RAM16(0xE020 + x);
        uint16_t value8 = RAM16(0x0004);
        uint8_t a4;
        uint8_t a_hi3;
        if (!((uint16_t)(value7 - value8) & 0x8000)) {
            uint8_t a2;
            uint8_t a_hi1;
            if ((uint16_t)(value7 - value8) < 8) {
                a2 = (uint8_t)(value7 - value8);
                a_hi1 = (uint16_t)(value7 - value8) >> 8;
            } else {
                uint16_t value9 = RAM16(0x0002);
                a2 = (uint8_t)value9;
                a_hi1 = value9 >> 8;
            }
            a4 = a2;
            a_hi3 = a_hi1;
        } else {
            uint8_t a3;
            uint8_t a_hi2;
            if ((uint16_t)(value7 - value8) >= 0xFFF8) {
                a3 = (uint8_t)(value7 - value8);
                a_hi2 = (uint16_t)(value7 - value8) >> 8;
            } else {
                uint16_t value10 = RAM16(0x0002);
                a3 = (uint8_t)((value10 ^ 0xFFFF) + 1);
                a_hi2 = (uint16_t)((value10 ^ 0xFFFF) + 1) >> 8;
            }
            a4 = a3;
            a_hi3 = a_hi2;
        }
        RAM16_SET(0x0000, (a_hi3 << 8) | a4);
        uint16_t value11 = RAM16(0xE074 + x);
        uint16_t value12 = RAM16(0xE045 + x);
        uint16_t value13 = RAM16(0xE022 + x);
        uint16_t value14 = RAM16(0x0006);
        uint8_t a7;
        uint8_t a_hi6;
        if (!((uint16_t)((uint16_t)(((uint16_t)((value11 & 0x7F) + value12) ^ 0xFFFF) + value13 + 1) - value14) & 0x8000)) {
            uint8_t a5;
            uint8_t a_hi4;
            if ((uint16_t)((uint16_t)(((uint16_t)((value11 & 0x7F) + value12) ^ 0xFFFF) + value13 + 1) - value14) < 8) {
                a5 = (uint8_t)((uint16_t)(((uint16_t)((value11 & 0x7F) + value12) ^ 0xFFFF) + value13 + 1) - value14);
                a_hi4 = (uint16_t)((uint16_t)(((uint16_t)((value11 & 0x7F) + value12) ^ 0xFFFF) + value13 + 1) - value14) >> 8;
            } else {
                uint16_t value15 = RAM16(0x0002);
                a5 = (uint8_t)value15;
                a_hi4 = value15 >> 8;
            }
            a7 = a5;
            a_hi6 = a_hi4;
        } else {
            uint8_t a6;
            uint8_t a_hi5;
            if ((uint16_t)((uint16_t)(((uint16_t)((value11 & 0x7F) + value12) ^ 0xFFFF) + value13 + 1) - value14) >= 0xFFF8) {
                a6 = (uint8_t)((uint16_t)(((uint16_t)((value11 & 0x7F) + value12) ^ 0xFFFF) + value13 + 1) - value14);
                a_hi5 = (uint16_t)((uint16_t)(((uint16_t)((value11 & 0x7F) + value12) ^ 0xFFFF) + value13 + 1) - value14) >> 8;
            } else {
                uint16_t value16 = RAM16(0x0002);
                a6 = (uint8_t)((value16 ^ 0xFFFF) + 1);
                a_hi5 = (uint16_t)((value16 ^ 0xFFFF) + 1) >> 8;
            }
            a7 = a6;
            a_hi6 = a_hi5;
        }
        RAM16_SET(0x0002, (a_hi6 << 8) | a7);
        uint16_t value17 = RAM16(0xD001 + y);
        uint8_t a_hi13;
        if ((value17 & 3) == 0) {
            uint16_t value18 = RAM16(0x0002);
            uint8_t a_hi7;
            if (!(value18 & 0x8000)) {
                a_hi7 = value18 >> 8;
            } else {
                RAM16_SET(0x0002, (uint16_t)((value18 ^ 0xFFFF) + 1));
                a_hi7 = (uint16_t)((value18 ^ 0xFFFF) + 1) >> 8;
            }
            a_hi13 = a_hi7;
        } else {
            uint8_t a_hi12;
            if ((uint16_t)((value17 & 3) - 1) == 0) {
                uint16_t value19 = RAM16(0x0002);
                uint8_t a_hi8;
                if (value19 & 0x8000) {
                    a_hi8 = value19 >> 8;
                } else {
                    RAM16_SET(0x0002, (uint16_t)((value19 ^ 0xFFFF) + 1));
                    a_hi8 = (uint16_t)((value19 ^ 0xFFFF) + 1) >> 8;
                }
                a_hi12 = a_hi8;
            } else {
                uint8_t a_hi11;
                if ((uint16_t)((value17 & 3) - 2) == 0) {
                    uint16_t value20 = RAM16(0x0000);
                    uint8_t a_hi9;
                    if (value20 & 0x8000) {
                        a_hi9 = value20 >> 8;
                    } else {
                        RAM16_SET(0x0000, (uint16_t)((value20 ^ 0xFFFF) + 1));
                        a_hi9 = (uint16_t)((value20 ^ 0xFFFF) + 1) >> 8;
                    }
                    a_hi11 = a_hi9;
                } else {
                    uint16_t value21 = RAM16(0x0000);
                    uint8_t a_hi10;
                    if (!(value21 & 0x8000)) {
                        a_hi10 = value21 >> 8;
                    } else {
                        RAM16_SET(0x0000, (uint16_t)((value21 ^ 0xFFFF) + 1));
                        a_hi10 = (uint16_t)((value21 ^ 0xFFFF) + 1) >> 8;
                    }
                    a_hi11 = a_hi10;
                }
                a_hi12 = a_hi11;
            }
            a_hi13 = a_hi12;
        }
        uint16_t value22 = RAM16(0x0002);
        uint16_t value23 = RAM16(0xD004 + y);
        uint8_t a9;
        uint8_t a_hi15;
        if (!((uint16_t)(value22 + value23) & 0x8000)) {
            uint16_t value24 = RAM16(0x00C2);
            uint8_t a8;
            uint8_t a_hi14;
            if ((uint16_t)(value22 + value23) < value24) {
                a8 = (uint8_t)(value22 + value23);
                a_hi14 = (uint16_t)(value22 + value23) >> 8;
            } else {
                a8 = (uint8_t)((uint16_t)(value22 + value23) - value24 - ((uint16_t)(value22 + value23) >= value24 ^ 1));
                a_hi14 = (uint16_t)((uint16_t)(value22 + value23) - value24 - ((uint16_t)(value22 + value23) >= value24 ^ 1)) >> 8;
            }
            a9 = a8;
            a_hi15 = a_hi14;
        } else {
            uint16_t value25 = RAM16(0x00C2);
            a9 = (uint8_t)((uint16_t)(value22 + value23) + value25);
            a_hi15 = (uint16_t)((uint16_t)(value22 + value23) + value25) >> 8;
        }
        RAM16_SET(0xD004 + y, (a_hi15 << 8) | a9);
        uint16_t value26 = RAM16(0x0000);
        uint16_t value27 = RAM16(0xD002 + y);
        uint8_t a11;
        uint8_t a_hi17;
        bool carry2;
        bool overflow2;
        if (!((uint16_t)(value26 + value27) & 0x8000)) {
            uint16_t value28 = RAM16(0x00C0);
            uint8_t a10;
            uint8_t a_hi16;
            bool carry1;
            bool overflow1;
            if ((uint16_t)(value26 + value27) < value28) {
                a10 = (uint8_t)(value26 + value27);
                a_hi16 = (uint16_t)(value26 + value27) >> 8;
                carry1 = (uint16_t)(value26 + value27) >= value28;
                overflow1 = ((value26 ^ (uint16_t)(value26 + value27)) & (value27 ^ (uint16_t)(value26 + value27)) & 0x8000) != 0;
            } else {
                a10 = (uint8_t)((uint16_t)(value26 + value27) - value28 - ((uint16_t)(value26 + value27) >= value28 ^ 1));
                a_hi16 = (uint16_t)((uint16_t)(value26 + value27) - value28 - ((uint16_t)(value26 + value27) >= value28 ^ 1)) >> 8;
                carry1 = (uint16_t)(value26 + value27) - value28 >= ((uint16_t)(value26 + value27) >= value28 ^ 1);
                overflow1 = (((uint16_t)(value26 + value27) ^ value28) & ((uint16_t)(value26 + value27) ^ (uint16_t)((uint16_t)(value26 + value27) - value28 - ((uint16_t)(value26 + value27) >= value28 ^ 1))) & 0x8000) != 0;
            }
            a11 = a10;
            a_hi17 = a_hi16;
            carry2 = carry1;
            overflow2 = overflow1;
        } else {
            uint16_t value29 = RAM16(0x00C0);
            a11 = (uint8_t)((uint16_t)(value26 + value27) + value29);
            a_hi17 = (uint16_t)((uint16_t)(value26 + value27) + value29) >> 8;
            carry2 = (uint16_t)(value26 + value27) + value29 > 0xFFFF;
            overflow2 = (((uint16_t)(value26 + value27) ^ (uint16_t)((uint16_t)(value26 + value27) + value29)) & (value29 ^ (uint16_t)((uint16_t)(value26 + value27) + value29)) & 0x8000) != 0;
        }
        RAM16_SET(0xD002 + y, (a_hi17 << 8) | a11);
        r->a = (a_hi17 << 8) | a11;
        r->c = carry2;
        r->v = overflow2;
        r->mf = 0;
        r->xf = 0;
        r->sp += 2;
        RETURN_RTS(c);
    }
    RAM8(0xD000 + y) = 0;
    SET_A8(r, 0);
    r->mf = 1;
    r->xf = 0;
    r->sp += 2;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2C526, SOM_RTS, "gen", test_charge_effect_contact_or_transfer_native_homing_continuation, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_V, 6, 1, 0, 561, 179)

/* C2C54E select_opposing_charge_effect_contact_actor_and_mark_source   [class A, 102 bytes, 53 instructions]
 * Source: src/rom/test_charge_effect_contact_or_transfer_native_homing_continuation.s
 * Subroutine of test_charge_effect_contact_or_transfer_native_homing_continuation, translated in place.
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void select_opposing_charge_effect_contact_actor_and_mark_source(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t a_c565 = 0;
    uint8_t a_hi_c565 = 0;
    uint16_t y_c565 = 0;
    bool overflow_c565 = 0;
    RAM16_SET(0x0000, x);
    uint8_t value = RAM8(0xE02E + x);
    if (x < 0x0600) {
        if (value & 0x01) {
            if (value >> 1 & 0x01) {
                if (value >> 2 & 0x01) {
                    uint16_t value2 = RAM16(0x0000);
                    SET_A8(r, value >> 3);
                    r->x = value2;
                    r->c = 0;
                    r->z = value2 == 0;
                    r->n = value2 & 0x8000;
                    RETURN_RTS(c);
                }
                r->a = (a_hi << 8) | (value >> 3);
                r->x = 0x0A00;
                { const uint16_t sp_call = r->sp; JSR(c, 0xC5AD, 0xC2C5B4); GUARD_JSR(c, sp_call, 0xC5AD); } /* test_charge_effect_contact_geometry_and_mark_target */
                uint16_t a_all = r->a;
                bool carry_ret = r->c;
                if (carry_ret) {
                    uint16_t value3 = RAM16(0x0000);
                    uint8_t value4 = RAM8(0xE02E + value3);
                    RAM8(0xE02E + value3) = (a_all >> 8) | value4;
                    r->a = ((uint8_t)a_all << 8) | ((a_all >> 8) | value4);
                    r->x = value3;
                    r->z = ((a_all >> 8) | value4) == 0;
                    r->n = ((a_all >> 8) | value4) & 0x80;
                    r->mf = 1;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                uint16_t value5 = RAM16(0x0000);
                r->x = value5;
                r->c = 0;
                r->z = value5 == 0;
                r->n = value5 & 0x8000;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTS(c);
            }
            RAM8(0x0000 + sp0) = value >> 2;
            r->a = (a_hi << 8) | (value >> 2);
            r->x = 0x0800;
            r->sp -= 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0xC5A1, 0xC2C5B4); GUARD_JSR(c, sp_call, 0xC5A1); } /* test_charge_effect_contact_geometry_and_mark_target */
            r->sp += 1;
            uint16_t a_all2 = r->a;
            bool carry_ret2 = r->c;
            uint8_t value6 = RAM8(0x0000 + sp0);
            if (carry_ret2) {
                uint16_t value7 = RAM16(0x0000);
                uint8_t value8 = RAM8(0xE02E + value7);
                RAM8(0xE02E + value7) = (a_all2 >> 8) | value8;
                r->a = (value6 << 8) | ((a_all2 >> 8) | value8);
                r->x = value7;
                r->z = ((a_all2 >> 8) | value8) == 0;
                r->n = ((a_all2 >> 8) | value8) & 0x80;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTS(c);
            }
            if (value6 & 0x01) {
                uint16_t value9 = RAM16(0x0000);
                SET_A8(r, value6 >> 1);
                r->x = value9;
                r->c = 0;
                r->z = value9 == 0;
                r->n = value9 & 0x8000;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTS(c);
            }
            r->a = (a_all2 >> 8 << 8) | (value6 >> 1);
            r->x = 0x0A00;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0xC5AD, 0xC2C5B4); GUARD_JSR(c, sp_call, 0xC5AD); } /* test_charge_effect_contact_geometry_and_mark_target */
            uint16_t a_all3 = r->a;
            bool carry_ret3 = r->c;
            if (carry_ret3) {
                uint16_t value10 = RAM16(0x0000);
                uint8_t value11 = RAM8(0xE02E + value10);
                RAM8(0xE02E + value10) = (a_all3 >> 8) | value11;
                r->a = ((uint8_t)a_all3 << 8) | ((a_all3 >> 8) | value11);
                r->x = value10;
                r->z = ((a_all3 >> 8) | value11) == 0;
                r->n = ((a_all3 >> 8) | value11) & 0x80;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTS(c);
            }
            uint16_t value12 = RAM16(0x0000);
            r->x = value12;
            r->c = 0;
            r->z = value12 == 0;
            r->n = value12 & 0x8000;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTS(c);
        }
        RAM8(0x0000 + sp0) = value >> 1;
        r->a = (a_hi << 8) | (value >> 1);
        r->x = 0x0600;
        r->sp -= 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0xC594, 0xC2C5B4); GUARD_JSR(c, sp_call, 0xC594); } /* test_charge_effect_contact_geometry_and_mark_target */
        r->sp += 1;
        uint16_t a_all4 = r->a;
        bool carry_ret4 = r->c;
        uint8_t value13 = RAM8(0x0000 + sp0);
        if (carry_ret4) {
            uint16_t value14 = RAM16(0x0000);
            uint8_t value15 = RAM8(0xE02E + value14);
            RAM8(0xE02E + value14) = (a_all4 >> 8) | value15;
            r->a = (value13 << 8) | ((a_all4 >> 8) | value15);
            r->x = value14;
            r->z = ((a_all4 >> 8) | value15) == 0;
            r->n = ((a_all4 >> 8) | value15) & 0x80;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTS(c);
        }
        if (value13 & 0x01) {
            if (value13 >> 1 & 0x01) {
                uint16_t value16 = RAM16(0x0000);
                SET_A8(r, value13 >> 2);
                r->x = value16;
                r->c = 0;
                r->z = value16 == 0;
                r->n = value16 & 0x8000;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTS(c);
            }
            r->a = (a_all4 >> 8 << 8) | (value13 >> 2);
            r->x = 0x0A00;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0xC5AD, 0xC2C5B4); GUARD_JSR(c, sp_call, 0xC5AD); } /* test_charge_effect_contact_geometry_and_mark_target */
            uint16_t a_all5 = r->a;
            bool carry_ret5 = r->c;
            if (carry_ret5) {
                uint16_t value17 = RAM16(0x0000);
                uint8_t value18 = RAM8(0xE02E + value17);
                RAM8(0xE02E + value17) = (a_all5 >> 8) | value18;
                r->a = ((uint8_t)a_all5 << 8) | ((a_all5 >> 8) | value18);
                r->x = value17;
                r->z = ((a_all5 >> 8) | value18) == 0;
                r->n = ((a_all5 >> 8) | value18) & 0x80;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTS(c);
            }
            uint16_t value19 = RAM16(0x0000);
            r->x = value19;
            r->c = 0;
            r->z = value19 == 0;
            r->n = value19 & 0x8000;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTS(c);
        }
        RAM8(0x0000 + sp0) = value13 >> 1;
        r->a = (a_all4 >> 8 << 8) | (value13 >> 1);
        r->x = 0x0800;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0xC5A1, 0xC2C5B4); GUARD_JSR(c, sp_call, 0xC5A1); } /* test_charge_effect_contact_geometry_and_mark_target */
        r->sp += 1;
        uint16_t a_all6 = r->a;
        bool carry_ret6 = r->c;
        uint8_t value20 = RAM8(0x0000 + sp0);
        if (carry_ret6) {
            uint16_t value21 = RAM16(0x0000);
            uint8_t value22 = RAM8(0xE02E + value21);
            RAM8(0xE02E + value21) = (a_all6 >> 8) | value22;
            r->a = (value20 << 8) | ((a_all6 >> 8) | value22);
            r->x = value21;
            r->z = ((a_all6 >> 8) | value22) == 0;
            r->n = ((a_all6 >> 8) | value22) & 0x80;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTS(c);
        }
        if (value20 & 0x01) {
            uint16_t value23 = RAM16(0x0000);
            SET_A8(r, value20 >> 1);
            r->x = value23;
            r->c = 0;
            r->z = value23 == 0;
            r->n = value23 & 0x8000;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = (a_all6 >> 8 << 8) | (value20 >> 1);
        r->x = 0x0A00;
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0xC5AD, 0xC2C5B4); GUARD_JSR(c, sp_call, 0xC5AD); } /* test_charge_effect_contact_geometry_and_mark_target */
        uint16_t a_all7 = r->a;
        bool carry_ret7 = r->c;
        if (carry_ret7) {
            uint16_t value24 = RAM16(0x0000);
            uint8_t value25 = RAM8(0xE02E + value24);
            RAM8(0xE02E + value24) = (a_all7 >> 8) | value25;
            r->a = ((uint8_t)a_all7 << 8) | ((a_all7 >> 8) | value25);
            r->x = value24;
            r->z = ((a_all7 >> 8) | value25) == 0;
            r->n = ((a_all7 >> 8) | value25) & 0x80;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTS(c);
        }
        uint16_t value26 = RAM16(0x0000);
        r->x = value26;
        r->c = 0;
        r->z = value26 == 0;
        r->n = value26 & 0x8000;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    if (value & 0x01) {
        a_c565 = value >> 1;
        a_hi_c565 = a_hi;
        y_c565 = y;
        overflow_c565 = overflow;
        goto shared_C565;
    }
    RAM8(0x0000 + sp0) = value >> 1;
    r->a = (a_hi << 8) | (value >> 1);
    r->x = 0;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC561, 0xC2C5B4); GUARD_JSR(c, sp_call, 0xC561); } /* test_charge_effect_contact_geometry_and_mark_target */
    r->sp += 1;
    uint16_t a_all8 = r->a;
    bool carry_ret8 = r->c;
    bool overflow_ret8 = r->v;
    uint8_t value27 = RAM8(0x0000 + sp0);
    if (carry_ret8) {
        uint16_t value28 = RAM16(0x0000);
        uint8_t value29 = RAM8(0xE02E + value28);
        RAM8(0xE02E + value28) = (a_all8 >> 8) | value29;
        r->a = (value27 << 8) | ((a_all8 >> 8) | value29);
        r->x = value28;
        r->z = ((a_all8 >> 8) | value29) == 0;
        r->n = ((a_all8 >> 8) | value29) & 0x80;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    a_c565 = value27;
    a_hi_c565 = a_all8 >> 8;
    y_c565 = y;
    overflow_c565 = overflow_ret8;
    shared_C565:;
    if (a_c565 & 0x01) {
        if (a_c565 >> 1 & 0x01) {
            uint16_t value30 = RAM16(0x0000);
            r->a = (a_hi_c565 << 8) | (a_c565 >> 2);
            r->x = value30;
            r->y = y_c565;
            r->c = 0;
            r->z = value30 == 0;
            r->n = value30 & 0x8000;
            r->v = overflow_c565;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        r->a = (a_hi_c565 << 8) | (a_c565 >> 2);
        r->x = 0x0400;
        r->y = y_c565;
        r->v = overflow_c565;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0xC57A, 0xC2C5B4); GUARD_JSR(c, sp_call, 0xC57A); } /* test_charge_effect_contact_geometry_and_mark_target */
        uint16_t a_all9 = r->a;
        bool carry_ret9 = r->c;
        if (carry_ret9) {
            uint16_t value31 = RAM16(0x0000);
            uint8_t value32 = RAM8(0xE02E + value31);
            RAM8(0xE02E + value31) = (a_all9 >> 8) | value32;
            r->a = ((uint8_t)a_all9 << 8) | ((a_all9 >> 8) | value32);
            r->x = value31;
            r->z = ((a_all9 >> 8) | value32) == 0;
            r->n = ((a_all9 >> 8) | value32) & 0x80;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTS(c);
        }
        uint16_t value33 = RAM16(0x0000);
        r->x = value33;
        r->c = 0;
        r->z = value33 == 0;
        r->n = value33 & 0x8000;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    RAM8(0x0000 + sp0) = a_c565 >> 1;
    r->a = (a_hi_c565 << 8) | (a_c565 >> 1);
    r->x = 0x0200;
    r->y = y_c565;
    r->v = overflow_c565;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC56E, 0xC2C5B4); GUARD_JSR(c, sp_call, 0xC56E); } /* test_charge_effect_contact_geometry_and_mark_target */
    r->sp += 1;
    uint16_t a_all10 = r->a;
    bool carry_ret10 = r->c;
    uint8_t value34 = RAM8(0x0000 + sp0);
    if (carry_ret10) {
        uint16_t value35 = RAM16(0x0000);
        uint8_t value36 = RAM8(0xE02E + value35);
        RAM8(0xE02E + value35) = (a_all10 >> 8) | value36;
        r->a = (value34 << 8) | ((a_all10 >> 8) | value36);
        r->x = value35;
        r->z = ((a_all10 >> 8) | value36) == 0;
        r->n = ((a_all10 >> 8) | value36) & 0x80;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    if (value34 & 0x01) {
        uint16_t value37 = RAM16(0x0000);
        SET_A8(r, value34 >> 1);
        r->x = value37;
        r->c = 0;
        r->z = value37 == 0;
        r->n = value37 & 0x8000;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = (a_all10 >> 8 << 8) | (value34 >> 1);
    r->x = 0x0400;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC57A, 0xC2C5B4); GUARD_JSR(c, sp_call, 0xC57A); } /* test_charge_effect_contact_geometry_and_mark_target */
    uint16_t a_all11 = r->a;
    bool carry_ret11 = r->c;
    if (carry_ret11) {
        uint16_t value38 = RAM16(0x0000);
        uint8_t value39 = RAM8(0xE02E + value38);
        RAM8(0xE02E + value38) = (a_all11 >> 8) | value39;
        r->a = ((uint8_t)a_all11 << 8) | ((a_all11 >> 8) | value39);
        r->x = value38;
        r->z = ((a_all11 >> 8) | value39) == 0;
        r->n = ((a_all11 >> 8) | value39) & 0x80;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value40 = RAM16(0x0000);
    r->x = value40;
    r->c = 0;
    r->z = value40 == 0;
    r->n = value40 & 0x8000;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
