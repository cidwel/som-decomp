#include "som_c.h"

/* C0EB06 advance_native_charge_and_partner_follow_frame   [class B, 18 bytes, 10 instructions]
 * Source: src/rom/advance_native_charge_and_partner_follow_frame.s
 * Documented in docs/actor-party-obstacle-detour.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void advance_native_charge_and_partner_follow_frame(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    r->a = (a_hi << 8) | 0x7E;
    r->db = 0x7E;
    r->sp -= 1;
    JSR(c, 0xEB0F, 0xC0EB18); /* advance_three_hero_charge_workers_after_link_preparation */
    r->sp += 1;
    r->mf = 1;
    r->xf = 1;
    r->sp -= 1;
    JSR(c, 0xEB12, 0xC0EE8C); /* update_native_two_partners_from_selected_leader */
    r->sp += 1;
    r->mf = 1;
    r->xf = 1;
    r->sp -= 1;
    JSR(c, 0xEB15, 0xC0FB8F); /* advance_all_normal_charge_workers_with_native_actor_loop */
    r->sp += 1;
    r->mf = 0;
    r->xf = 0;
    r->db = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0EB06, SOM_RTS, "gen", advance_native_charge_and_partner_follow_frame, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 1, 18, 10)
