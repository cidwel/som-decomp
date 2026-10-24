#include "som_c.h"

/* C00057 jump_public_party_gold_transaction   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/jump_public_party_gold_transaction.s
 * Documented in docs/event-gold-hud-commands.md
 * Entry: M=16 bit X=8 bit DB=$7E D=$0000.  Callers read: nothing.
 */
static void jump_public_party_gold_transaction(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC0383F, SOM_RTL); /* jump_internal_party_gold_transaction */
}
SOM_REGISTER(0xC00057, SOM_RTL, "gen", jump_public_party_gold_transaction, 0, 0, 1, 0, 1, 3, 1)
