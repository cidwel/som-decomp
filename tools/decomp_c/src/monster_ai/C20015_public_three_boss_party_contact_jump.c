#include "som_c.h"

/* C20015 public_three_boss_party_contact_jump   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/public_three_boss_party_contact_jump.s
 * Documented in docs/boss-public-party-services.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABYCV.
 */
static void public_three_boss_party_contact_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC20363, SOM_RTL); /* check_first_three_active_boss_contacts_preserving_context */
}
SOM_REGISTER(0xC20015, SOM_RTL, "gen", public_three_boss_party_contact_jump, 0, L_A | L_B | L_Y | L_C | L_V, 1, 1, 0, 3, 1)
