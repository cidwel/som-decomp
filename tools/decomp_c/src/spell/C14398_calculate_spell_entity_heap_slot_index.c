#include "som_c.h"

/* C14398 calculate_spell_entity_heap_slot_index   [class A, 30 bytes, 22 instructions]
 * Source: src/rom/calculate_spell_entity_heap_slot_index.s
 * Documented in docs/actor-entity-index-bits.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void calculate_spell_entity_heap_slot_index(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    r->a = ((uint16_t)(x - RAM16(0x8424)) >> 5) & 7;
    r->z = 0;
    r->n = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC14398, SOM_RTS, "gen", calculate_spell_entity_heap_slot_index, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 1, 0, 30, 22)
