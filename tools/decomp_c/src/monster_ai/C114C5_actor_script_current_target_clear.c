#include "som_c.h"

/* C114C5 actor_script_current_target_clear   [class A, 8 bytes, 3 instructions]
 * Source: src/rom/actor_script_current_target_clear.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$01E7.  Callers read: ABXYCZNV.
 */
static void actor_script_current_target_clear(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x01E7) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    RAM8(0x01AC + y) = 0xFF;
    r->a = (a_hi << 8) | 0xFF;
    r->z = 0;
    r->n = 1;
    TAIL_CALL(c, 0xC10121, SOM_RTS); /* advance_actor_script_1_bytes */
}
SOM_REGISTER(0xC114C5, SOM_RTS, "gen", actor_script_current_target_clear, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 8, 3)
