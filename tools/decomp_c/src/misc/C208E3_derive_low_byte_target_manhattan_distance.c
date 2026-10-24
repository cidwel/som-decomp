#include "som_c.h"

/* C208E3 derive_low_byte_target_manhattan_distance   [class A, 14 bytes, 8 instructions]
 * Source: src/rom/derive_low_byte_target_manhattan_distance.s
 * Documented in docs/boss-descriptor-four.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYV.
 */
static void derive_low_byte_target_manhattan_distance(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    r->a = (uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000);
    r->x = (uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000);
    JSR(c, 0x08EF, 0xC208F1); /* derive_actor_manhattan_distance_from_selected_boss */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC208E3, SOM_RTS, "gen", derive_low_byte_target_manhattan_distance, 0, L_A | L_B | L_X | L_Y | L_V, 1, 0, 0, 14, 8)
