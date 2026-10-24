#include "som_c.h"

/* C101F7 skip_actor_script_relative_operand   [class A, 28 bytes, 16 instructions]
 * Source: src/rom/skip_actor_script_relative_operand.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=any X=16 bit DB=$7E D=any.  Callers read: A.
 */
static void skip_actor_script_relative_operand(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint8_t value = BUS8(c, 0xD04F15 + x);
    uint16_t x1;
    if ((value & 0x80) != 0) {
        x1 = x;
    } else {
        x1 = (uint16_t)(x + 1);
    }
    RAM16_SET(0x0144 + y, (uint16_t)(x1 + 1));
    r->a = 0xFFFF;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC101F7, SOM_RTS, "gen", skip_actor_script_relative_operand, 0, L_A, 3, -1, 0, 28, 16)
