#include "som_c.h"

/* C1E6A8 refresh_party_portraits_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/refresh_party_portraits_long.s
 * Documented in docs/rom-combat.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BYCV.
 */
static void refresh_party_portraits_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0xE6AA, 0xC1E6AC); /* wait_for_native_nmi_and_refresh_party_portraits */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1E6A8, SOM_RTL, "gen", refresh_party_portraits_long, 0, L_B | L_Y | L_C | L_V, 1, 1, 0, 4, 2)
