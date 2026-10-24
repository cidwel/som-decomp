#include "som_c.h"

/* C11FD1 actor_script_current_target_from_literal_byte   [class A, 13 bytes, 4 instructions]
 * Source: src/rom/actor_script_current_target_from_literal_byte.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void actor_script_current_target_from_literal_byte(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x0144 + y);
    uint8_t value2 = BUS8(c, 0xD04F16 + value);
    RAM8(0x01AC + y) = value2;
    r->a = (a_hi << 8) | value2;
    r->x = value;
    r->z = value2 == 0;
    r->n = value2 & 0x80;
    TAIL_CALL(c, 0xC1012B, SOM_RTS); /* advance_actor_script_2_bytes */
}
SOM_REGISTER(0xC11FD1, SOM_RTS, "gen", actor_script_current_target_from_literal_byte, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 13, 4)
