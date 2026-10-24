#include "som_c.h"

/* C116C7 actor_script_set_variable_1   [class A, 15 bytes, 5 instructions]
 * Source: src/rom/actor_script_set_variable_1.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$01E7.  Callers read: ABXYCZNV.
 */
static void actor_script_set_variable_1(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x01E7) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x0144 + y);
    uint8_t value2 = BUS8(c, 0xD04F16 + value);
    r->a = a_hi << 8 | (value2 & 0x0F);
    r->z = (value2 & 0x0F) == 0;
    r->n = value2 & 0x0F & 0x80;
    JSR(c, 0x16D2, 0xC101AE); /* write_actor_script_variable_1 */
    r->x = value;
    r->mf = 1;
    r->xf = 0;
    TAIL_CALL(c, 0xC1012B, SOM_RTS); /* advance_actor_script_2_bytes */
}
SOM_REGISTER(0xC116C7, SOM_RTS, "gen", actor_script_set_variable_1, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 15, 5)
