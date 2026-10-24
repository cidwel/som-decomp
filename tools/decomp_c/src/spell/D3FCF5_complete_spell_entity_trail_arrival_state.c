#include "som_c.h"

/* D3FCF5 complete_spell_entity_trail_arrival_state   [class A, 16 bytes, 10 instructions]
 * Source: src/rom/complete_spell_entity_trail_arrival_state.s
 * Documented in docs/actor-cast-entity-trail-state.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void complete_spell_entity_trail_arrival_state(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t y = r->y;
    RAM8(0x0152 + y) = 0;
    RAM8(0x0154 + y)++;
    r->x = y;
    r->z = dp == 0;
    r->n = dp & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD3FCF5, SOM_RTS, "gen", complete_spell_entity_trail_arrival_state, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 3, 1, 0, 16, 10)
