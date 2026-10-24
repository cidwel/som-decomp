#include "som_c.h"

/* C12ED1 draw_spell_entity_bounded_random_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/draw_spell_entity_bounded_random_long.s
 * Documented in docs/actor-cast-entity-mode-two.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$01DA.  Callers read: ABYCV.
 */
static void draw_spell_entity_bounded_random_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x01DA) { c->fail = 3; return; }
    JSR(c, 0x2ED3, 0xC146C3); /* draw_spell_entity_random_below_rejection_bound */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC12ED1, SOM_RTL, "gen", draw_spell_entity_bounded_random_long, 0, L_A | L_B | L_Y | L_C | L_V, 1, 1, 0, 4, 2)
