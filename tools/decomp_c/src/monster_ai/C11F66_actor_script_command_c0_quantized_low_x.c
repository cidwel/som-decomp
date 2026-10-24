#include "som_c.h"

/* C11F66 actor_script_command_c0_quantized_low_x   [class A, 50 bytes, 22 instructions]
 * Source: src/rom/actor_script_command_c0_quantized_low_x.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void actor_script_command_c0_quantized_low_x(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    RAM8(0x0140 + y) = 0xC0;
    uint16_t value = RAM16(0x0144 + y);
    uint8_t value2 = BUS8(c, 0xD04F16 + value);
    RAM8(0x0141 + y) = value2;
    uint8_t value3 = BUS8(c, 0xD04F17 + value);
    RAM8(0x0142 + y) = value3;
    uint8_t value4 = RAM8(0x0020 + y);
    uint8_t a1;
    if ((value4 >> 1) + 4 >> 3 != 0) {
        a1 = (value4 >> 1) + 4 >> 3;
    } else {
        a1 = 1;
    }
    uint8_t a2;
    if (a1 < 0x10) {
        a2 = a1;
    } else {
        a2 = 0x0F;
    }
    RAM8(0x0143 + y) = a2;
    r->a = (a_hi << 8) | 3;
    r->x = value;
    r->c = a1 >= 0x10;
    r->z = 0;
    r->n = 0;
    r->v = (((value4 >> 1) ^ (value4 >> 1) + 4) & ((value4 >> 1) + 4 ^ 4) & 0x80) != 0;
    TAIL_CALL(c, 0xC10111, SOM_RTS); /* advance_actor_script_and_yield */
}
SOM_REGISTER(0xC11F66, SOM_RTS, "gen", actor_script_command_c0_quantized_low_x, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 50, 22)
