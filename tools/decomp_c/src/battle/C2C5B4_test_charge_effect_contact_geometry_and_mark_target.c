#include "som_c.h"

/* C2C5B4 test_charge_effect_contact_geometry_and_mark_target   [class B, 154 bytes, 77 instructions]
 * Source: src/rom/test_charge_effect_contact_geometry_and_mark_target.s
 * Entry: M=any X=16 bit DB=$7E D=any.  Callers read: ABYCV.
 */
static void test_charge_effect_contact_geometry_and_mark_target(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint8_t value = RAM8(0xE000 + x);
    if (value == 0) {
        SET_A8(r, value);
        r->c = 0;
        r->mf = 1;
        RETURN_RTS(c);
    }
    if (!(value & 0x80)) {
        uint8_t value2 = RAM8(0xE00B + x);
        uint8_t value3 = RAM8(0xD001 + y);
        if ((value2 ^ value3) & 0x80) {
            SET_A8(r, value2 ^ value3);
            r->c = 0;
            r->mf = 1;
            RETURN_RTS(c);
        }
        uint8_t value4 = RAM8(0xD000 + y);
        uint8_t a1;
        if (value4 != 2) {
            a1 = 0x10;
        } else {
            a1 = 0x20;
        }
        BUS8_SET(c, (uint16_t)(dp + 2), a1);
        BUS8_SET(c, (uint16_t)(dp + 3), a1);
        uint16_t value5 = RAM16(0xE0CA + x);
        if (value5 == 0) {
            r->a = value5;
            r->c = 0;
            r->mf = 1;
            RETURN_RTS(c);
        }
        uint16_t value6 = BUS16_RDP(c, (uint16_t)(dp + 2));
        BUS16_SET(c, (uint16_t)(dp + 2), (uint16_t)(value5 + value6));
        uint16_t value7 = RAM16(0xE020 + x);
        uint16_t value8 = BUS16_RDP(c, (uint16_t)(dp + 4));
        uint8_t a2;
        uint8_t a_hi1;
        if (!((uint16_t)(value7 - value8) & 0x8000)) {
            a2 = (uint8_t)(value7 - value8);
            a_hi1 = (uint16_t)(value7 - value8) >> 8;
        } else {
            a2 = (uint8_t)(((uint16_t)(value7 - value8) ^ 0xFFFF) + 1);
            a_hi1 = (uint16_t)(((uint16_t)(value7 - value8) ^ 0xFFFF) + 1) >> 8;
        }
        if (((a_hi1 << 8) | a2) >= 0x60) {
            r->a = (a_hi1 << 8) | a2;
            r->c = 0;
            r->v = ((value7 ^ value8) & (value7 ^ (uint16_t)(value7 - value8)) & 0x8000) != 0;
            r->mf = 1;
            RETURN_RTS(c);
        }
        uint8_t value9 = BUS8_RDP(c, (uint16_t)(dp + 2));
        if ((uint8_t)(a2 << 1) >= value9) {
            r->a = (a_hi1 << 8) | (uint8_t)(a2 << 1);
            r->c = 0;
            r->v = ((value7 ^ value8) & (value7 ^ (uint16_t)(value7 - value8)) & 0x8000) != 0;
            r->mf = 1;
            RETURN_RTS(c);
        }
        uint16_t value10 = RAM16(0xE074 + x);
        uint16_t value11 = RAM16(0xE045 + x);
        uint16_t value12 = RAM16(0xE022 + x);
        uint16_t value13 = BUS16_RDP(c, (uint16_t)(dp + 6));
        uint8_t a3;
        uint8_t a_hi2;
        if (!((uint16_t)((uint16_t)(((uint16_t)((value10 & 0x7F) + value11) ^ 0xFFFF) + value12) - value13) & 0x8000)) {
            a3 = (uint8_t)((uint16_t)(((uint16_t)((value10 & 0x7F) + value11) ^ 0xFFFF) + value12) - value13);
            a_hi2 = (uint16_t)((uint16_t)(((uint16_t)((value10 & 0x7F) + value11) ^ 0xFFFF) + value12) - value13) >> 8;
        } else {
            a3 = (uint8_t)(((uint16_t)((uint16_t)(((uint16_t)((value10 & 0x7F) + value11) ^ 0xFFFF) + value12) - value13) ^ 0xFFFF) + 1);
            a_hi2 = (uint16_t)(((uint16_t)((uint16_t)(((uint16_t)((value10 & 0x7F) + value11) ^ 0xFFFF) + value12) - value13) ^ 0xFFFF) + 1) >> 8;
        }
        if (((a_hi2 << 8) | a3) >= 0x60) {
            r->a = (a_hi2 << 8) | a3;
            r->c = 0;
            r->v = (((uint16_t)(((uint16_t)((value10 & 0x7F) + value11) ^ 0xFFFF) + value12) ^ value13) & ((uint16_t)(((uint16_t)((value10 & 0x7F) + value11) ^ 0xFFFF) + value12) ^ (uint16_t)((uint16_t)(((uint16_t)((value10 & 0x7F) + value11) ^ 0xFFFF) + value12) - value13)) & 0x8000) != 0;
            r->mf = 1;
            RETURN_RTS(c);
        }
        uint8_t value14 = BUS8_RDP(c, (uint16_t)(dp + 3));
        if ((uint8_t)(a3 << 1) >= value14) {
            r->a = (a_hi2 << 8) | (uint8_t)(a3 << 1);
            r->c = 0;
            r->v = (((uint16_t)(((uint16_t)((value10 & 0x7F) + value11) ^ 0xFFFF) + value12) ^ value13) & ((uint16_t)(((uint16_t)((value10 & 0x7F) + value11) ^ 0xFFFF) + value12) ^ (uint16_t)((uint16_t)(((uint16_t)((value10 & 0x7F) + value11) ^ 0xFFFF) + value12) - value13)) & 0x8000) != 0;
            r->mf = 1;
            RETURN_RTS(c);
        }
        RAM8(0x0000 + sp0) = x >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
        uint8_t a4;
        bool overflow1;
        if (x >> 8 < 6) {
            a4 = x >> 8;
            overflow1 = (((uint16_t)(((uint16_t)((value10 & 0x7F) + value11) ^ 0xFFFF) + value12) ^ value13) & ((uint16_t)(((uint16_t)((value10 & 0x7F) + value11) ^ 0xFFFF) + value12) ^ (uint16_t)((uint16_t)(((uint16_t)((value10 & 0x7F) + value11) ^ 0xFFFF) + value12) - value13)) & 0x8000) != 0;
        } else {
            a4 = (uint8_t)((x >> 8) - 6 - (x >> 8 >= 6 ^ 1));
            overflow1 = (((x >> 8) ^ 6) & ((x >> 8) ^ (uint8_t)((x >> 8) - 6 - (x >> 8 >= 6 ^ 1))) & 0x80) != 0;
        }
        uint8_t a5;
        if ((a4 & 0x0F) != 0) {
            a5 = a4 & 0x0F;
        } else {
            a5 = 1;
        }
        uint8_t value15 = BUS8_RDP(c, (uint16_t)(dp + 1));
        uint8_t a6;
        bool overflow2;
        if (value15 < 6) {
            a6 = value15;
            overflow2 = overflow1;
        } else {
            a6 = (uint8_t)(value15 - 6 - (value15 >= 6 ^ 1));
            overflow2 = ((value15 ^ 6) & (value15 ^ (uint8_t)(value15 - 6 - (value15 >= 6 ^ 1))) & 0x80) != 0;
        }
        uint8_t a7;
        if ((a6 & 0x0F) != 0) {
            a7 = a6 & 0x0F;
        } else {
            a7 = 1;
        }
        uint8_t hero_hit_mask = RAM8(HERO_HIT_MASK + x);
        RAM8(HERO_HIT_MASK + x) = a7 | hero_hit_mask;
        r->a = (a5 << 8) | (a7 | hero_hit_mask);
        r->c = 1;
        r->v = overflow2;
        r->mf = 1;
        RETURN_RTS(c);
    }
    SET_A8(r, value);
    r->c = 0;
    r->mf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2C5B4, SOM_RTS, "gen", test_charge_effect_contact_geometry_and_mark_target, 0, L_A | L_B | L_Y | L_C | L_V, 2, -1, 0, 154, 77)
