#include "som_c.h"

/* C10111 advance_actor_script_and_yield   [class A, 16 bytes, 7 instructions]
 * Source: src/rom/advance_actor_script_and_yield.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: nothing.
 */
static void advance_actor_script_and_yield(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    RAM16_SET(0x0144 + y, (uint16_t)((((a_hi << 8) | a) & 0xFF) + RAM16(0x0144 + y)));
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC10111, SOM_RTS, "gen", advance_actor_script_and_yield, 0, 0, 1, 1, 0, 16, 7)
