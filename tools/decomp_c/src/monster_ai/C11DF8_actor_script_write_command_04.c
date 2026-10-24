#include "som_c.h"

/* C11DF8 actor_script_write_command_04   [class A, 10 bytes, 4 instructions]
 * Source: src/rom/actor_script_write_command_04.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void actor_script_write_command_04(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    RAM8(0x0140 + y) = 4;
    r->a = (a_hi << 8) | 1;
    r->z = 0;
    r->n = 0;
    TAIL_CALL(c, 0xC10111, SOM_RTS); /* advance_actor_script_and_yield */
}
SOM_REGISTER(0xC11DF8, SOM_RTS, "gen", actor_script_write_command_04, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 10, 4)
