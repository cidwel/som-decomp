#include "som_c.h"

/* C13D29 allocate_spell_entity_heap_bytes   [class A, 31 bytes, 23 instructions]
 * Source: src/rom/allocate_spell_entity_heap_bytes.s
 * Documented in docs/actor-cast-entity-memory.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: BXYCV.
 */
static void allocate_spell_entity_heap_bytes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool overflow = r->v;
    r->a = (uint16_t)(x + 0x3F) >> 6;
    r->c = (uint16_t)(x + 0x3F) >> 5 & 0x01;
    r->z = (uint16_t)(x + 0x3F) >> 6 == 0;
    r->n = (uint16_t)(x + 0x3F) >> 6 & 0x8000;
    r->v = ((x ^ (uint16_t)(x + 0x3F)) & ((uint16_t)(x + 0x3F) ^ 0x3F) & 0x8000) != 0;
    r->mf = 0;
    r->sp -= 4;
    JSR(c, 0x3D43, 0xC13C04); /* allocate_spell_entity_heap_units */
    r->sp += 4;
    r->c = carry;
    r->v = overflow;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC13D29, SOM_RTS, "gen", allocate_spell_entity_heap_bytes, 0, L_B | L_X | L_Y | L_C | L_V, 5, 1, 0, 31, 23)
