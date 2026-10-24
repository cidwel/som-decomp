#include "som_c.h"

/* C146B0 draw_spell_entity_random_byte   [class A, 19 bytes, 13 instructions]
 * Source: src/rom/draw_spell_entity_random_byte.s
 * Documented in docs/actor-cast-entity-mode-two.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$01CE.  Callers read: ABXYV.
 */
static void draw_spell_entity_random_byte(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x01CE) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const bool overflow = r->v;
    r->a = (a >> 8 << 8) | 0x7E;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->sp -= 4;
    JSL(c, 0x46BE, 0xC00018); /* public_random_byte_jump */
    r->sp += 4;
    r->v = overflow;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC146B0, SOM_RTS, "gen", draw_spell_entity_random_byte, 0, L_A | L_B | L_X | L_Y | L_V, 5, 0, 0, 19, 13)
