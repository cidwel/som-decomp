#include "som_c.h"

/* C11F37 actor_script_write_command_43   [class A, 20 bytes, 7 instructions]
 * Source: src/rom/actor_script_write_command_43.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void actor_script_write_command_43(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    RAM8(0x0140 + y) = 0x43;
    uint16_t value = RAM16(0x0144 + y);
    uint8_t value2 = BUS8(c, 0xD04F16 + value);
    RAM8(0x0141 + y) = value2;
    r->a = (a_hi << 8) | 2;
    r->x = value;
    r->z = 0;
    r->n = 0;
    TAIL_CALL(c, 0xC10111, SOM_RTS); /* advance_actor_script_and_yield */
}
SOM_REGISTER(0xC11F37, SOM_RTS, "gen", actor_script_write_command_43, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 20, 7)
