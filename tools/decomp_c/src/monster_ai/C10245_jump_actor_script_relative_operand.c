#include "som_c.h"

/* C10245 jump_actor_script_relative_operand   [class B, 64 bytes, 38 instructions]
 * Source: src/rom/jump_actor_script_relative_operand.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=any X=16 bit DB=$7E D=any.  Callers read: A.
 */
static void jump_actor_script_relative_operand(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint16_t value = BUS16(c, 0xD04F15 + x);
    uint8_t a3;
    uint8_t a_hi2;
    uint16_t x1;
    if (((uint8_t)value & 0x80) == 0) {
        uint8_t a1;
        if (((uint8_t)value & 0x40) == 0) {
            a1 = (uint8_t)value;
        } else {
            a1 = (uint8_t)value | 0x80;
        }
        a3 = a1;
        a_hi2 = value >> 8;
        x1 = (uint16_t)(x + 1);
    } else {
        uint8_t a2;
        uint8_t a_hi1;
        if (((uint8_t)value & 0x40) != 0) {
            a2 = 0xFF;
            a_hi1 = (uint8_t)value;
        } else {
            a2 = 0;
            a_hi1 = (uint8_t)value & 0x7F;
        }
        a3 = a2;
        a_hi2 = a_hi1;
        x1 = x;
    }
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), x1);
    RAM16_SET(0x0144 + y, (uint16_t)((uint16_t)(((a3 << 8) | a_hi2) + 1) + RAM16(0x0001 + (uint16_t)(sp0 - 5))));
    r->a = 0xFFFF;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC10245, SOM_RTS, "gen", jump_actor_script_relative_operand, 0, L_A, 5, -1, 0, 64, 38)
