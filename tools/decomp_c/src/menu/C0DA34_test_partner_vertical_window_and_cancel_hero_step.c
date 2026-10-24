#include "som_c.h"

/* C0DA34 test_partner_vertical_window_and_cancel_hero_step   [class B, 58 bytes, 29 instructions]
 * Source: src/rom/test_partner_vertical_window_and_cancel_hero_step.s
 * Documented in docs/map-hero-motion.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYCV.
 */
static void test_partner_vertical_window_and_cancel_hero_step(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint8_t value = RAM8(0xE000 + x);
    if (value == 0) {
        RETURN_RTS(c);
    }
    if (value & 0x80) {
        RETURN_RTS(c);
    }
    uint16_t value2 = RAM16(0x0000);
    uint8_t a3;
    uint8_t a_hi3;
    if (!(value2 & 0x8000)) {
        uint16_t value3 = RAM16(0xE004 + x);
        uint16_t value4 = RAM16(0x00C2);
        uint8_t a1;
        uint8_t a_hi1;
        if ((uint16_t)(value2 + value3) < value4) {
            a1 = (uint8_t)(value2 + value3);
            a_hi1 = (uint16_t)(value2 + value3) >> 8;
        } else {
            a1 = (uint8_t)((uint16_t)(value2 + value3) - value4 - ((uint16_t)(value2 + value3) >= value4 ^ 1));
            a_hi1 = (uint16_t)((uint16_t)(value2 + value3) - value4 - ((uint16_t)(value2 + value3) >= value4 ^ 1)) >> 8;
        }
        a3 = a1;
        a_hi3 = a_hi1;
    } else {
        uint16_t value5 = RAM16(0xE004 + x);
        uint8_t a2;
        uint8_t a_hi2;
        if (!((uint16_t)(value2 + value5) & 0x8000)) {
            a2 = (uint8_t)(value2 + value5);
            a_hi2 = (uint16_t)(value2 + value5) >> 8;
        } else {
            uint16_t value6 = RAM16(0x00C2);
            a2 = (uint8_t)((uint16_t)(value2 + value5) + value6);
            a_hi2 = (uint16_t)((uint16_t)(value2 + value5) + value6) >> 8;
        }
        a3 = a2;
        a_hi3 = a_hi2;
    }
    uint16_t value7 = RAM16(0x0018);
    uint8_t a4;
    uint8_t a_hi4;
    bool overflow1;
    if (((a_hi3 << 8) | a3) >= value7) {
        a4 = (uint8_t)(((a_hi3 << 8) | a3) - value7);
        a_hi4 = (uint16_t)(((a_hi3 << 8) | a3) - value7) >> 8;
        overflow1 = ((((a_hi3 << 8) | a3) ^ value7) & (((a_hi3 << 8) | a3) ^ (uint16_t)(((a_hi3 << 8) | a3) - value7)) & 0x8000) != 0;
    } else {
        uint16_t value8 = RAM16(0x00C2);
        a4 = (uint8_t)((uint16_t)(((a_hi3 << 8) | a3) - value7) + value8 + (((a_hi3 << 8) | a3) >= value7));
        a_hi4 = (uint16_t)((uint16_t)(((a_hi3 << 8) | a3) - value7) + value8 + (((a_hi3 << 8) | a3) >= value7)) >> 8;
        overflow1 = (((uint16_t)(((a_hi3 << 8) | a3) - value7) ^ (uint16_t)((uint16_t)(((a_hi3 << 8) | a3) - value7) + value8 + (((a_hi3 << 8) | a3) >= value7))) & (value8 ^ (uint16_t)((uint16_t)(((a_hi3 << 8) | a3) - value7) + value8 + (((a_hi3 << 8) | a3) >= value7))) & 0x8000) != 0;
    }
    if (((a_hi4 << 8) | a4) < 0x48) {
        RAM8(0x001F) = 0;
        r->a = (r->a & 0x00FF) | (a_hi4 << 8);
        r->c = ((a_hi4 << 8) | a4) >= 0x48;
        r->v = overflow1;
        RETURN_RTS(c);
    }
    if (((a_hi4 << 8) | a4) >= 0xB0) {
        RAM8(0x001F) = 0;
        r->a = (r->a & 0x00FF) | (a_hi4 << 8);
        r->c = ((a_hi4 << 8) | a4) >= 0xB0;
        r->v = overflow1;
        RETURN_RTS(c);
    }
    r->a = (a_hi4 << 8) | a4;
    r->c = ((a_hi4 << 8) | a4) >= 0xB0;
    r->v = overflow1;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0DA34, SOM_RTS, "gen", test_partner_vertical_window_and_cancel_hero_step, 0, L_B | L_Y | L_C | L_V, 1, 1, 0, 58, 29)
