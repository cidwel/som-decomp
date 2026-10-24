#include "som_c.h"

/* C8E2F6 actor_selected_effect_request_event   [class A, 11 bytes, 5 instructions]
 * Source: src/rom/actor_selected_effect_request_event.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void actor_selected_effect_request_event(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint8_t value = RAM8(0xE1C9 + y);
    r->a = (5 << 8) | value;
    r->z = value == 0;
    r->n = value & 0x80;
    { const uint16_t sp_call = r->sp; JSL(c, 0xE2FF, 0x018000); GUARD_JSL(c, sp_call, 0xE2FF); } /* event_command_public_jump */
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8E2F6, SOM_RTS, "gen", actor_selected_effect_request_event, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 11, 5)
