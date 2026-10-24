#include "som_c.h"

/* C208D9 derive_target_manhattan_distance_in_sixteen_pixel_units   [class A, 10 bytes, 7 instructions]
 * Source: src/rom/derive_target_manhattan_distance_in_sixteen_pixel_units.s
 * Documented in docs/boss-descriptor-four.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYV.
 */
static void derive_target_manhattan_distance_in_sixteen_pixel_units(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    JSR(c, 0x08DB, 0xC208E3); /* derive_low_byte_target_manhattan_distance */
    uint16_t a_all = r->a;
    RAM16_SET(0x0299, a_all);
    r->a = a_all >> 4;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC208D9, SOM_RTS, "gen", derive_target_manhattan_distance_in_sixteen_pixel_units, 0, L_A | L_B | L_X | L_Y | L_V, 1, 0, 0, 10, 7)
