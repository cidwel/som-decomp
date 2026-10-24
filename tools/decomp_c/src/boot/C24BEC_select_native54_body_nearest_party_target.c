#include "som_c.h"

/* C24BEC select_native54_body_nearest_party_target   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/select_native54_body_nearest_party_target.s
 * Documented in docs/boss-native54-body.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: AB.
 */
static void select_native54_body_nearest_party_target(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    JSR(c, 0x4BEE, 0xC23224); /* select_nearest_active_living_party_actor */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC24BEC, SOM_RTS, "gen", select_native54_body_nearest_party_target, 0, L_A | L_B, 1, 0, 0, 4, 2)
