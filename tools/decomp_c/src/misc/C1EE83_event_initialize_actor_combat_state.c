#include "som_c.h"

/* C1EE83 event_initialize_actor_combat_state   [class A, 9 bytes, 4 instructions]
 * Source: src/rom/event_initialize_actor_combat_state.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void event_initialize_actor_combat_state(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    r->a = (a_hi << 8) | 0xFF;
    r->z = 0;
    r->n = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0xEE8A, 0x0180BA); GUARD_JSL(c, sp_call, 0xEE8A); } /* external */
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1EE83, SOM_RTS, "gen", event_initialize_actor_combat_state, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 9, 4)
