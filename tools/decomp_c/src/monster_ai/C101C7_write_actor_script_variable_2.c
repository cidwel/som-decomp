#include "som_c.h"

/* C101C7 write_actor_script_variable_2   [class A, 23 bytes, 14 instructions]
 * Source: src/rom/write_actor_script_variable_2.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$01E7.  Callers read: Y.
 */
static void write_actor_script_variable_2(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x01E7) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint16_t y = r->y;
    RAM8(0x0147 + y) = (RAM8(0x0147 + y) & 0xF0) | (a & 0x0F);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC101C7, SOM_RTS, "gen", write_actor_script_variable_2, 0, L_Y, 4, 1, 0, 23, 14)
