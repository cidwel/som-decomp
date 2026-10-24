#include "som_c.h"

/* C101AE write_actor_script_variable_1   [class A, 25 bytes, 17 instructions]
 * Source: src/rom/write_actor_script_variable_1.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$01E7.  Callers read: Y.
 */
static void write_actor_script_variable_1(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x01E7) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint16_t y = r->y;
    RAM8(0x0146 + y) = (RAM8(0x0146 + y) & 0x0F) | (uint8_t)(a << 4);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC101AE, SOM_RTS, "gen", write_actor_script_variable_1, 0, L_Y, 4, 1, 0, 25, 17)
