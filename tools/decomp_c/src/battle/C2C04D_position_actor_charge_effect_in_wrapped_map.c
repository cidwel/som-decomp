#include "som_c.h"

/* C2C04D position_actor_charge_effect_in_wrapped_map   [class B, 251 bytes, 115 instructions]
 * Source: src/rom/position_actor_charge_effect_in_wrapped_map.s
 * Documented in docs/actor-animation-special-helpers.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: AXYV.
 */
static void position_actor_charge_effect_in_wrapped_map(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    RAM16_SET(0xD00E + y, (uint16_t)(((RAM16(0xE092 + x) & 0x3000) | RAM16(0xE086 + x)) + 0x20));
    RAM16_SET(0xD002 + y, RAM16(0xE002 + x));
    uint16_t value4 = RAM16(0xE074 + x);
    uint16_t value5 = RAM16(0xE045 + x);
    RAM16_SET(0xD006 + y, (uint16_t)((value4 & 0x7F) + value5));
    uint16_t value6 = RAM16(0xE004 + x);
    uint8_t a1;
    uint8_t a_hi1;
    if (!((uint16_t)(((uint16_t)((value4 & 0x7F) + value5) ^ 0xFFFF) + value6 + 1) & 0x8000)) {
        a1 = (uint8_t)(((uint16_t)((value4 & 0x7F) + value5) ^ 0xFFFF) + value6 + 1);
        a_hi1 = (uint16_t)(((uint16_t)((value4 & 0x7F) + value5) ^ 0xFFFF) + value6 + 1) >> 8;
    } else {
        uint16_t value7 = RAM16(0x00C2);
        a1 = (uint8_t)((uint16_t)(((uint16_t)((value4 & 0x7F) + value5) ^ 0xFFFF) + value6 + 1) + value7);
        a_hi1 = (uint16_t)((uint16_t)(((uint16_t)((value4 & 0x7F) + value5) ^ 0xFFFF) + value6 + 1) + value7) >> 8;
    }
    RAM16_SET(0xD004 + y, (a_hi1 << 8) | a1);
    RAM8(0xD00B + y) = RAM8(0xD006 + y);
    uint8_t value9 = RAM8(0xD000 + y);
    uint8_t value10 = RAM8(0xD001 + y);
    uint8_t a6;
    uint8_t a_hi2;
    if ((value10 & 3) < 2) {
        RAM8(0xD00C + y) = 0xF8;
        RAM8(0xD00D + y) = 0xF8;
        uint8_t a2;
        if (!(value10 & 3 & 0x01)) {
            a2 = 0xF6;
        } else {
            RAM8(0xD00F + y) ^= 0xC0;
            a2 = 0x0A;
        }
        if (value9 == 1) {
            RAM8(0xD00F + y) ^= 0x40;
        }
        a6 = 0;
        a_hi2 = a2;
    } else {
        uint8_t a4;
        if (value9 == 1) {
            RAM8(0xD00D + y) = 0xF8;
            a4 = 0;
        } else {
            uint8_t a3;
            if (value9 == 2) {
                RAM8(0xD00D + y) = 0xF4;
                a3 = 0xF0;
            } else {
                RAM8(0xD00D + y) = 0xFC;
                a3 = 0xF8;
            }
            a4 = a3;
        }
        RAM8(0xD006 + y) = (uint8_t)((a4 ^ 0xFF) + RAM8(0xD006 + y) + 1);
        RAM8(0xD00C + y) = 0xF8;
        uint8_t a5;
        if (!(value10 & 3 & 0x01)) {
            a5 = 0x0A;
        } else {
            RAM8(0xD00F + y) ^= 0x40;
            a5 = 0xF6;
        }
        a6 = a5;
        a_hi2 = a4;
    }
    uint8_t a7;
    uint8_t a_hi3;
    if (a_hi2 < 0x80) {
        a7 = ((a6 << 8) | a_hi2) & 0xFF;
        a_hi3 = 0;
    } else {
        a7 = (uint8_t)((((a6 << 8) | a_hi2) & 0xFF) | 0xFF00);
        a_hi3 = ((((a6 << 8) | a_hi2) & 0xFF) | 0xFF00) >> 8;
    }
    uint16_t value15 = RAM16(0xD004 + y);
    uint8_t a9;
    uint8_t a_hi5;
    if (!((uint16_t)(((a_hi3 << 8) | a7) + value15) & 0x8000)) {
        uint16_t value16 = RAM16(0x00C2);
        uint8_t a8;
        uint8_t a_hi4;
        if ((uint16_t)(((a_hi3 << 8) | a7) + value15) < value16) {
            a8 = (uint8_t)(((a_hi3 << 8) | a7) + value15);
            a_hi4 = (uint16_t)(((a_hi3 << 8) | a7) + value15) >> 8;
        } else {
            a8 = (uint8_t)((uint16_t)(((a_hi3 << 8) | a7) + value15) - value16 - ((uint16_t)(((a_hi3 << 8) | a7) + value15) >= value16 ^ 1));
            a_hi4 = (uint16_t)((uint16_t)(((a_hi3 << 8) | a7) + value15) - value16 - ((uint16_t)(((a_hi3 << 8) | a7) + value15) >= value16 ^ 1)) >> 8;
        }
        a9 = a8;
        a_hi5 = a_hi4;
    } else {
        uint16_t value17 = RAM16(0x00C2);
        a9 = (uint8_t)((uint16_t)(((a_hi3 << 8) | a7) + value15) + value17 + (((a_hi3 << 8) | a7) + value15 > 0xFFFF));
        a_hi5 = (uint16_t)((uint16_t)(((a_hi3 << 8) | a7) + value15) + value17 + (((a_hi3 << 8) | a7) + value15 > 0xFFFF)) >> 8;
    }
    RAM16_SET(0xD004 + y, (a_hi5 << 8) | a9);
    uint8_t a10;
    uint8_t a_hi6;
    if (a6 < 0x80) {
        a10 = ((a_hi5 << 8) | a6) & 0xFF;
        a_hi6 = 0;
    } else {
        a10 = (uint8_t)((((a_hi5 << 8) | a6) & 0xFF) | 0xFF00);
        a_hi6 = ((((a_hi5 << 8) | a6) & 0xFF) | 0xFF00) >> 8;
    }
    uint16_t value18 = RAM16(0xD002 + y);
    uint8_t a12;
    uint8_t a_hi8;
    bool overflow2;
    if (!((uint16_t)(((a_hi6 << 8) | a10) + value18) & 0x8000)) {
        uint16_t value19 = RAM16(0x00C0);
        uint8_t a11;
        uint8_t a_hi7;
        bool overflow1;
        if ((uint16_t)(((a_hi6 << 8) | a10) + value18) < value19) {
            a11 = (uint8_t)(((a_hi6 << 8) | a10) + value18);
            a_hi7 = (uint16_t)(((a_hi6 << 8) | a10) + value18) >> 8;
            overflow1 = ((((a_hi6 << 8) | a10) ^ (uint16_t)(((a_hi6 << 8) | a10) + value18)) & (value18 ^ (uint16_t)(((a_hi6 << 8) | a10) + value18)) & 0x8000) != 0;
        } else {
            a11 = (uint8_t)((uint16_t)(((a_hi6 << 8) | a10) + value18) - value19 - ((uint16_t)(((a_hi6 << 8) | a10) + value18) >= value19 ^ 1));
            a_hi7 = (uint16_t)((uint16_t)(((a_hi6 << 8) | a10) + value18) - value19 - ((uint16_t)(((a_hi6 << 8) | a10) + value18) >= value19 ^ 1)) >> 8;
            overflow1 = (((uint16_t)(((a_hi6 << 8) | a10) + value18) ^ value19) & ((uint16_t)(((a_hi6 << 8) | a10) + value18) ^ (uint16_t)((uint16_t)(((a_hi6 << 8) | a10) + value18) - value19 - ((uint16_t)(((a_hi6 << 8) | a10) + value18) >= value19 ^ 1))) & 0x8000) != 0;
        }
        a12 = a11;
        a_hi8 = a_hi7;
        overflow2 = overflow1;
    } else {
        uint16_t value20 = RAM16(0x00C0);
        a12 = (uint8_t)((uint16_t)(((a_hi6 << 8) | a10) + value18) + value20 + (((a_hi6 << 8) | a10) + value18 > 0xFFFF));
        a_hi8 = (uint16_t)((uint16_t)(((a_hi6 << 8) | a10) + value18) + value20 + (((a_hi6 << 8) | a10) + value18 > 0xFFFF)) >> 8;
        overflow2 = (((uint16_t)(((a_hi6 << 8) | a10) + value18) ^ (uint16_t)((uint16_t)(((a_hi6 << 8) | a10) + value18) + value20 + (((a_hi6 << 8) | a10) + value18 > 0xFFFF))) & (value20 ^ (uint16_t)((uint16_t)(((a_hi6 << 8) | a10) + value18) + value20 + (((a_hi6 << 8) | a10) + value18 > 0xFFFF))) & 0x8000) != 0;
    }
    RAM16_SET(0xD002 + y, (a_hi8 << 8) | a12);
    SET_A8(r, a12);
    r->v = overflow2;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2C04D, SOM_RTS, "gen", position_actor_charge_effect_in_wrapped_map, 0, L_A | L_X | L_Y | L_V, 1, 1, 0, 251, 115)
