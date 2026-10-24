#include "som_c.h"

/* C11646 actor_script_copy_current_to_second_target   [class A, 9 bytes, 3 instructions]
 * Source: src/rom/actor_script_copy_current_to_second_target.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void actor_script_copy_current_to_second_target(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    uint8_t value = RAM8(0x01AC + y);
    RAM8(0x01AD + y) = value;
    r->a = (a_hi << 8) | value;
    r->z = value == 0;
    r->n = value & 0x80;
    TAIL_CALL(c, 0xC10121, SOM_RTS); /* advance_actor_script_1_bytes */
}
SOM_REGISTER(0xC11646, SOM_RTS, "gen", actor_script_copy_current_to_second_target, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 9, 3)
