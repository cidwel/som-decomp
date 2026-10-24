#include "som_c.h"

/* C11E2C actor_script_compare_mp_to_spell_argument_cost   [class A, 27 bytes, 13 instructions]
 * Source: src/rom/actor_script_compare_mp_to_spell_argument_cost.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: BYCZNV.
 */
static void actor_script_compare_mp_to_spell_argument_cost(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    uint8_t value2 = BUS8(c, 0xD04F17 + RAM16(0x0144 + y));
    uint8_t value3 = RAM8(0x0186 + y);
    uint8_t value4 = BUS8(c, 0xD02ADF + ((((((a_hi << 8) | value2) & 0xFF) << 8) | 0) >> 2));
    r->a = (r->a & 0x00FF) | (((((((a_hi << 8) | value2) & 0xFF) << 8) | 0) >> 2 >> 8) << 8);
    r->c = value3 >= value4;
    r->z = (uint8_t)(value3 - value4) == 0;
    r->n = (uint8_t)(value3 - value4) & 0x80;
    r->v = ((value3 ^ value4) & (value3 ^ (uint8_t)(value3 - value4)) & 0x80) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC11E2C, SOM_RTS, "gen", actor_script_compare_mp_to_spell_argument_cost, 0, L_B | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 27, 13)
