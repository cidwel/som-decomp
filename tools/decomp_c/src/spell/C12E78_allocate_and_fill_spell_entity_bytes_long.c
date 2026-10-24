#include "som_c.h"

/* C12E78 allocate_and_fill_spell_entity_bytes_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/allocate_and_fill_spell_entity_bytes_long.s
 * Documented in docs/actor-cast-entity-mode-two.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$01D7.  Callers read: BXYCV.
 */
static void allocate_and_fill_spell_entity_bytes_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x01D7) { c->fail = 3; return; }
    JSR(c, 0x2E7A, 0xC13D48); /* allocate_and_fill_spell_entity_heap_bytes */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC12E78, SOM_RTL, "gen", allocate_and_fill_spell_entity_bytes_long, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 4, 2)
