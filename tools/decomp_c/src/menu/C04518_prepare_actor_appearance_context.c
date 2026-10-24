#include "som_c.h"

/* C04518 prepare_actor_appearance_context   [class A, 24 bytes, 15 instructions]
 * Source: src/rom/prepare_actor_appearance_context.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void prepare_actor_appearance_context(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x03BD, x & 0x1FFF);
    RAM8(0x03BA) = (x & 0x1FFF) >> 9;
    r->a = (r->a & 0x00FF) | ((uint8_t)(x & 0x1FFF) << 8);
    r->x = x & 0x1FFF;
    r->c = (x & 0x1FFF) >> 8 & 0x01;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC04518, SOM_RTS, "gen", prepare_actor_appearance_context, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 24, 15)
