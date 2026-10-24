#include "som_c.h"

/* C0D962 test_hero_horizontal_step_against_camera_window   [class B, 76 bytes, 41 instructions]
 * Source: src/rom/test_hero_horizontal_step_against_camera_window.s
 * Documented in docs/map-hero-motion.md
 * Entry: M=8 bit X=8 bit DB=$7E D=$0000.  Callers read: BYCV.
 */
static void test_hero_horizontal_step_against_camera_window(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t value = RAM8(0x001E);
    uint8_t a3;
    uint8_t a_hi3;
    if (value >= 0x80) {
        RAM16_SET(0x0000, (uint16_t)(((((a_hi << 8) | value) & 0x7F) ^ 0xFFFF) + 1));
        uint16_t value2 = RAM16(0x0012);
        uint8_t a1;
        uint8_t a_hi1;
        if (!((uint16_t)((uint16_t)(((((a_hi << 8) | value) & 0x7F) ^ 0xFFFF) + 1) + value2) & 0x8000)) {
            a1 = (uint8_t)((uint16_t)(((((a_hi << 8) | value) & 0x7F) ^ 0xFFFF) + 1) + value2);
            a_hi1 = (uint16_t)((uint16_t)(((((a_hi << 8) | value) & 0x7F) ^ 0xFFFF) + 1) + value2) >> 8;
        } else {
            uint16_t value3 = RAM16(0x00C0);
            a1 = (uint8_t)((uint16_t)((uint16_t)(((((a_hi << 8) | value) & 0x7F) ^ 0xFFFF) + 1) + value2) + value3);
            a_hi1 = (uint16_t)((uint16_t)((uint16_t)(((((a_hi << 8) | value) & 0x7F) ^ 0xFFFF) + 1) + value2) + value3) >> 8;
        }
        a3 = a1;
        a_hi3 = a_hi1;
    } else {
        RAM16_SET(0x0000, ((a_hi << 8) | value) & 0x7F);
        uint16_t value4 = RAM16(0x0012);
        uint16_t value5 = RAM16(0x00C0);
        uint8_t a2;
        uint8_t a_hi2;
        if ((uint16_t)((((a_hi << 8) | value) & 0x7F) + value4 + (value >= 0x80)) < value5) {
            a2 = (uint8_t)((((a_hi << 8) | value) & 0x7F) + value4 + (value >= 0x80));
            a_hi2 = (uint16_t)((((a_hi << 8) | value) & 0x7F) + value4 + (value >= 0x80)) >> 8;
        } else {
            a2 = (uint8_t)((uint16_t)((((a_hi << 8) | value) & 0x7F) + value4 + (value >= 0x80)) - value5 - ((uint16_t)((((a_hi << 8) | value) & 0x7F) + value4 + (value >= 0x80)) >= value5 ^ 1));
            a_hi2 = (uint16_t)((uint16_t)((((a_hi << 8) | value) & 0x7F) + value4 + (value >= 0x80)) - value5 - ((uint16_t)((((a_hi << 8) | value) & 0x7F) + value4 + (value >= 0x80)) >= value5 ^ 1)) >> 8;
        }
        a3 = a2;
        a_hi3 = a_hi2;
    }
    uint16_t value6 = RAM16(0x0016);
    uint8_t a4;
    uint8_t a_hi4;
    if (((a_hi3 << 8) | a3) >= value6) {
        a4 = (uint8_t)(((a_hi3 << 8) | a3) - value6);
        a_hi4 = (uint16_t)(((a_hi3 << 8) | a3) - value6) >> 8;
    } else {
        uint16_t value7 = RAM16(0x00C0);
        a4 = (uint8_t)((uint16_t)(((a_hi3 << 8) | a3) - value6) + value7 + (((a_hi3 << 8) | a3) >= value6));
        a_hi4 = (uint16_t)((uint16_t)(((a_hi3 << 8) | a3) - value6) + value7 + (((a_hi3 << 8) | a3) >= value6)) >> 8;
    }
    uint16_t value8 = RAM16(0x001D);
    if (value8 & 0x8000) {
        if (((a_hi4 << 8) | a4) < 0x38) {
            uint16_t value9 = RAM16(0x0000);
            RAM16_SET(0x0000, (uint16_t)((value9 ^ 0xFFFF) + 1));
            r->a = (uint16_t)((value9 ^ 0xFFFF) + 1);
            r->c = 1;
            r->v = value8 & 0x4000;
            r->mf = 0;
            RETURN_RTS(c);
        }
        r->a = (a_hi4 << 8) | a4;
        r->c = 0;
        r->v = value8 & 0x4000;
        r->mf = 0;
        RETURN_RTS(c);
    }
    if (((a_hi4 << 8) | a4) >= 0xC8) {
        uint16_t value10 = RAM16(0x0000);
        RAM16_SET(0x0000, (uint16_t)((value10 ^ 0xFFFF) + 1));
        r->a = (uint16_t)((value10 ^ 0xFFFF) + 1);
        r->c = 1;
        r->v = value8 & 0x4000;
        r->mf = 0;
        RETURN_RTS(c);
    }
    r->a = (a_hi4 << 8) | a4;
    r->c = 0;
    r->v = value8 & 0x4000;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0D962, SOM_RTS, "gen", test_hero_horizontal_step_against_camera_window, 0, L_B | L_Y | L_C | L_V, 1, 1, 1, 76, 41)
