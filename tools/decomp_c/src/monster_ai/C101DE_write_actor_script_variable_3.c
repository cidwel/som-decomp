#include "som_c.h"

/* C101DE write_actor_script_variable_3   [class A, 25 bytes, 17 instructions]
 * Source: src/rom/write_actor_script_variable_3.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: Y.
 */
static void write_actor_script_variable_3(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint8_t a = r->a & 0xFF;
    const uint16_t y = r->y;
    RAM8(0x0147 + y) = (RAM8(0x0147 + y) & 0x0F) | (uint8_t)(a << 4);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC101DE, SOM_RTS, "gen", write_actor_script_variable_3, 0, L_Y, 4, 1, 0, 25, 17)
