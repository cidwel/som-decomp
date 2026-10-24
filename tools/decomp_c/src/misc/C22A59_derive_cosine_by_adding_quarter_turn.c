#include "som_c.h"

/* C22A59 derive_cosine_by_adding_quarter_turn   [class A, 14 bytes, 8 instructions]
 * Source: src/rom/derive_cosine_by_adding_quarter_turn.s
 * Documented in docs/boss-native-death-particles.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCV.
 */
static void derive_cosine_by_adding_quarter_turn(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    r->a = (((uint8_t)((a >> 8) + 1) << 8) | (uint8_t)a) & 0x03FF;
    JSR(c, 0x2A65, 0xC22A67); /* reflect_full_wave_and_negate_lower_half */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22A59, SOM_RTS, "gen", derive_cosine_by_adding_quarter_turn, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 14, 8)
