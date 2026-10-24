#include "som_c.h"

/* C000B9 return_from_public_hidden_effect_update   [class A, 1 bytes, 1 instructions]
 * Source: src/rom/return_from_public_hidden_effect_update.s
 * Documented in docs/boss-native59-hidden-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void return_from_public_hidden_effect_update(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    RETURN_RTL(c);
}
SOM_REGISTER(0xC000B9, SOM_RTL, "gen", return_from_public_hidden_effect_update, 0, 0, 1, 0, 0, 1, 1)
