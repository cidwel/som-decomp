#include "som_c.h"

/* C201F9 update_boss_pool_then_consume_pending_cast_preserving_context   [class B, 65 bytes, 31 instructions]
 * Source: src/rom/update_boss_pool_then_consume_pending_cast_preserving_context.s
 * Documented in docs/boss-public-pool-update.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void update_boss_pool_then_consume_pending_cast_preserving_context(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    i_php(c);
    i_phd(c);
    i_phb(c);
    i_sep(r, 0x20);
    a_lda(r, 0x7E);
    i_pha(c);
    i_plb(c);
    i_rep(r, 0x30);
    a_lda(r, 0x0200);
    i_tcd(r);
    { const uint16_t sp_call = r->sp; JSR(c, 0x020A, 0xC20DB2); GUARD_JSR_DB(c, sp_call, 0x020A, 0x7E); } /* update_nine_boss_actor_slots_combat_definition_and_animation */
    HAND_REQUIRE_WIDE(c);
    a_lda(r, RAM16(0x0360));
    if (!r->z) {
        a_lda(r, RAM16(0x02CA));
        a_and(r, 0x00FF);
        if (r->z) {
            a_ldx(r, RAM16(0x0360));
            { const uint16_t sp_call = r->sp; JSL(c, 0x021E, 0xC0001B); GUARD_JSL_DB(c, sp_call, 0x021E, 0x7E); } /* cast_spell_public_jump */
            HAND_REQUIRE_WIDE(c);
            a_and(r, 0x00FF);
            if (r->z) {
                a_lda(r, RAM16(0x0360));
                i_tax(r);
                RAM16_SET(0x0060 + r->x, 0);
                a_and(r, 0x1FFF);
                i_tax(r);
                { const uint16_t sp_call = r->sp; JSL(c, 0x0232, 0xC1800F); GUARD_JSL_DB(c, sp_call, 0x0232, 0x7E); } /* cast_actor_request_public_jump */
            }
            RAM16_SET(0x0360, 0);
        }
    }
    hand_plb(c);
    hand_pld(c);
    hand_plp(c);
    RETURN_RTL(c);
}
SOM_REGISTER(0xC201F9, SOM_RTL, "hand", update_boss_pool_then_consume_pending_cast_preserving_context, 0, L_B | L_X | L_Y | L_C | L_V, 5, 0, 0, 65, 31)
