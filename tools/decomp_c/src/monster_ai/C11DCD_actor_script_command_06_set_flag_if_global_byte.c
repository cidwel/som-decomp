#include "som_c.h"

/* C11DCD actor_script_command_06_set_flag_if_global_byte   [class B, 43 bytes, 20 instructions]
 * Source: src/rom/actor_script_command_06_set_flag_if_global_byte.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$01E7.  Callers read: ABXYCZNV.
 */
static void actor_script_command_06_set_flag_if_global_byte(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x01E7) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint8_t value = RAM8(0xCC7D + (((uint8_t)((uint16_t)(y - 0xE000) >> 1) << 8) | ((uint16_t)(y - 0xE000) >> 1 >> 8)));
    if (value == 0) {
        r->a = ((uint8_t)((uint16_t)(y - 0xE000) >> 1) << 8) | value;
        r->x = ((uint8_t)((uint16_t)(y - 0xE000) >> 1) << 8) | ((uint16_t)(y - 0xE000) >> 1 >> 8);
        r->c = (uint16_t)(y - 0xE000) & 0x01;
        r->z = value == 0;
        r->n = value & 0x80;
        r->v = ((y ^ 0xE000) & (y ^ (uint16_t)(y - 0xE000)) & 0x8000) != 0;
        TAIL_CALL(c, 0xC10121, SOM_RTS); /* advance_actor_script_1_bytes */
    }
    uint8_t value2 = RAM8(0x014C + y);
    if ((value2 & 1) != 0) {
        r->a = ((uint8_t)((uint16_t)(y - 0xE000) >> 1) << 8) | value2;
        r->x = ((uint8_t)((uint16_t)(y - 0xE000) >> 1) << 8) | ((uint16_t)(y - 0xE000) >> 1 >> 8);
        r->c = (uint16_t)(y - 0xE000) & 0x01;
        r->z = (value2 & 1) == 0;
        r->n = value2 & 0x80;
        r->v = ((y ^ 0xE000) & (y ^ (uint16_t)(y - 0xE000)) & 0x8000) != 0;
        TAIL_CALL(c, 0xC10121, SOM_RTS); /* advance_actor_script_1_bytes */
    }
    RAM8(0x014C + y) = value2 | 1;
    RAM8(0x0140 + y) = 6;
    r->a = ((uint8_t)((uint16_t)(y - 0xE000) >> 1) << 8) | 1;
    r->x = ((uint8_t)((uint16_t)(y - 0xE000) >> 1) << 8) | ((uint16_t)(y - 0xE000) >> 1 >> 8);
    r->c = (uint16_t)(y - 0xE000) & 0x01;
    r->z = 0;
    r->n = 0;
    r->v = ((y ^ 0xE000) & (y ^ (uint16_t)(y - 0xE000)) & 0x8000) != 0;
    TAIL_CALL(c, 0xC10111, SOM_RTS); /* advance_actor_script_and_yield */
}
SOM_REGISTER(0xC11DCD, SOM_RTS, "gen", actor_script_command_06_set_flag_if_global_byte, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 43, 20)
