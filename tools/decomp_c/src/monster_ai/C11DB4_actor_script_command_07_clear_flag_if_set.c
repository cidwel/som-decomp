#include "som_c.h"

/* C11DB4 actor_script_command_07_clear_flag_if_set   [class A, 25 bytes, 10 instructions]
 * Source: src/rom/actor_script_command_07_clear_flag_if_set.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$01E7.  Callers read: ABXYCZNV.
 */
static void actor_script_command_07_clear_flag_if_set(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x01E7) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    uint8_t value = RAM8(0x014C + y);
    if ((value & 1) == 0) {
        r->a = (a_hi << 8) | value;
        r->z = (value & 1) == 0;
        r->n = value & 0x80;
        TAIL_CALL(c, 0xC10121, SOM_RTS); /* advance_actor_script_1_bytes */
    }
    RAM8(0x014C + y) = value & 0xFE;
    RAM8(0x0140 + y) = 7;
    r->a = (a_hi << 8) | 1;
    r->z = 0;
    r->n = 0;
    TAIL_CALL(c, 0xC10111, SOM_RTS); /* advance_actor_script_and_yield */
}
SOM_REGISTER(0xC11DB4, SOM_RTS, "gen", actor_script_command_07_clear_flag_if_set, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 25, 10)
