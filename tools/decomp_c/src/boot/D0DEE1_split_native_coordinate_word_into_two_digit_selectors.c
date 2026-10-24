#include "som_c.h"

/* D0DEE1 split_native_coordinate_word_into_two_digit_selectors   [class A, 11 bytes, 10 instructions]
 * Source: src/rom/split_native_coordinate_word_into_two_digit_selectors.s
 * Documented in docs/event-menu-coordinates.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: AYCV.
 */
static void split_native_coordinate_word_into_two_digit_selectors(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    r->a = ((uint8_t)((a_hi << 8) | a) << 8) | a_hi;
    r->y = ((a_hi << 8) | a) >> 4;
    r->c = ((a_hi << 8) | a) >> 3 & 0x01;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0DEE1, SOM_RTS, "gen", split_native_coordinate_word_into_two_digit_selectors, 0, L_A | L_Y | L_C | L_V, 2, 1, 0, 11, 10)
