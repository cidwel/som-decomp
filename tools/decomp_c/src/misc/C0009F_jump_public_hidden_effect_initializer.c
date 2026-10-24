#include "som_c.h"

/* C0009F jump_public_hidden_effect_initializer   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/jump_public_hidden_effect_initializer.s
 * Documented in docs/boss-native59-hidden-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void jump_public_hidden_effect_initializer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC000A5, SOM_RTL); /* preserve_context_and_initialize_hidden_effect */
}
SOM_REGISTER(0xC0009F, SOM_RTL, "gen", jump_public_hidden_effect_initializer, 0, 0, 1, 0, 0, 3, 1)
