#include "som_c.h"

/* C03872 random_byte_with_preserved_direct_page   [class A, 18 bytes, 12 instructions]
 * Source: src/rom/random_byte_with_preserved_direct_page.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXY.
 */
static void random_byte_with_preserved_direct_page(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t dp = r->dp;
    r->a = 0x0300;
    r->z = 0;
    r->n = 0;
    r->dp = 0x0300;
    r->sp -= 4;
    JSR(c, 0x387F, 0xC038A0); /* advance_additive_random_generator */
    r->sp += 4;
    r->mf = 1;
    r->xf = 0;
    r->dp = dp;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC03872, SOM_RTL, "gen", random_byte_with_preserved_direct_page, 0, L_A | L_B | L_X | L_Y, 4, 1, 0, 18, 12)
