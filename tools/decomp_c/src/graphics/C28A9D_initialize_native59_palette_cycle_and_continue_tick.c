#include "som_c.h"

/* C28A9D initialize_native59_palette_cycle_and_continue_tick   [class B, 89 bytes, 33 instructions]
 * Source: src/rom/initialize_native59_palette_cycle_and_continue_tick.s
 * Documented in docs/boss-native59-children.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_native59_palette_cycle_and_continue_tick(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x0287);
    RAM16_SET(0x002B + value, 0xC0);
    RAM16_SET(0x0032 + value, 0xC0);
    RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
    RAM16_SET(0x0000 + value, 1);
    r->a = 0x0173;
    r->x = value;
    JSR(c, 0x8AB9, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
    RAM16_SET(0x00B0 + value, 0);
    RAM16_SET(0x0070 + value, 8);
    RAM16_SET(0x0022 + value, 0);
    uint16_t value2 = RAM16(0x0287);
    uint16_t value3 = RAM16(OBJECT_AGE + value2);
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool zero1;
    bool negative1;
    bool overflow1;
    if (value3 < 2) {
        a1 = (uint8_t)value3;
        a_hi1 = value3 >> 8;
        x1 = value2;
        y1 = y;
        zero1 = value3 == 2;
        negative1 = (uint16_t)(value3 - 2) & 0x8000;
        overflow1 = overflow;
    } else {
        uint16_t value5 = BUS16(c, 0xC28AF6 + RAM16(0x00B0 + value2));
        r->a = value5 & 0xFF;
        r->x = 0x0E;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x8AE0, 0xC226F9); /* copy_boss_palette_with_cpu_words */
        uint16_t y_ret = r->y;
        bool overflow_ret = r->v;
        uint16_t value6 = RAM16(0x0287);
        RAM16_SET(OBJECT_AGE + value6, 0);
        RAM16_SET(0x00B0 + value6, (uint16_t)(RAM16(0x00B0 + value6) + 1));
        uint16_t value7 = RAM16(0x00B0 + value6);
        if (value7 >= 6) {
            RAM16_SET(0x00B0 + value6, 0);
        }
        a1 = (uint8_t)value7;
        a_hi1 = value7 >> 8;
        x1 = value6;
        y1 = y_ret;
        zero1 = value7 == 6;
        negative1 = (uint16_t)(value7 - 6) & 0x8000;
        overflow1 = overflow_ret;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = 0;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC28A9D, SOM_RTS, "gen", initialize_native59_palette_cycle_and_continue_tick, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 89, 33)
