#include "som_c.h"

/* C11D5C actor_script_command_02_copy_field_1c0_if_gauge_zero   [class A, 24 bytes, 9 instructions]
 * Source: src/rom/actor_script_command_02_copy_field_1c0_if_gauge_zero.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void actor_script_command_02_copy_field_1c0_if_gauge_zero(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    uint8_t value = RAM8(0x01ED + y);
    if (value == 0) {
        RAM8(0x019B + y) = RAM8(0x01C0 + y);
        RAM8(0x0140 + y) = 2;
        r->a = (a_hi << 8) | 1;
        r->z = 0;
        r->n = 0;
        TAIL_CALL(c, 0xC10111, SOM_RTS); /* advance_actor_script_and_yield */
    }
    r->a = (a_hi << 8) | value;
    r->z = value == 0;
    r->n = value & 0x80;
    TAIL_CALL(c, 0xC10121, SOM_RTS); /* advance_actor_script_1_bytes */
}
SOM_REGISTER(0xC11D5C, SOM_RTS, "gen", actor_script_command_02_copy_field_1c0_if_gauge_zero, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 24, 9)
