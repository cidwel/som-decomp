#include "som_c.h"

/* C2AFD0 refresh_all_three_party_status_cancelled_weapons   [class B, 19 bytes, 7 instructions]
 * Source: src/rom/refresh_all_three_party_status_cancelled_weapons.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: A.
 */
static void refresh_all_three_party_status_cancelled_weapons(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    r->x = 0;
    r->z = 1;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xAFD5, 0xC2AFE3); GUARD_JSR(c, sp_call, 0xAFD5); } /* clear_actor_status_four_and_refresh_live_weapon_graphics */
    if (r->xf != 0) { c->fail = 3; return; }
    r->x = 0x0200;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xAFDB, 0xC2AFE3); GUARD_JSR(c, sp_call, 0xAFDB); } /* clear_actor_status_four_and_refresh_live_weapon_graphics */
    if (r->xf != 0) { c->fail = 3; return; }
    r->x = 0x0400;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xAFE1, 0xC2AFE3); GUARD_JSR(c, sp_call, 0xAFE1); } /* clear_actor_status_four_and_refresh_live_weapon_graphics */
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2AFD0, SOM_RTL, "gen", refresh_all_three_party_status_cancelled_weapons, 0, L_A, 1, 1, 0, 19, 7)
