#include "som_c.h"
#include "som_hand.h"

/* C1395B release_spell_entity_sprite_pointer_group   [class A, 34 bytes, 24 instructions]
 * Source: src/rom/release_spell_entity_sprite_pointer_group.s
 * Documented in docs/actor-cast-entity-sprite-groups.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: BYCV.
 */
static void release_spell_entity_sprite_pointer_group(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    i_phd(c);
    i_php(c);
    i_rep(r, 0x30);
    i_pha(c);
    i_tsc(r);
    i_inca(r);
    i_tcd(r);
    i_pla(c);
    i_phb(c);
    i_sep(r, 0x20);
    dp_wr8(c, 0x01, r->a);              /* the loop counter lands on the byte PHB pushed */
    i_txy(r);
    do {
        i_phy(c);
        {
            uint32_t lo, hi;
            ADR_ABY(r, 0x0000, lo, hi);
            if (!hand_rd_ok(lo) || !hand_rd_ok(hi)) { c->fail = 3; return; }
            a_ldx(r, rdx(c, lo, hi));
        }
        { const uint16_t sp_call = r->sp; JSL(c, 0x3971, 0xC12E88); GUARD_JSL(c, sp_call, 0x3971); } /* release_spell_sprite_instance_long */
        i_ply(c);
        i_iny(r);
        i_iny(r);
        dp_wr8(c, 0x01, m_dec(r, dp_rd8(c, 0x01)));
    } while (!r->z);
    i_pla(c);
    hand_plp(c);
    i_pld(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1395B, SOM_RTS, "hand", release_spell_entity_sprite_pointer_group, 0, L_B | L_Y | L_C | L_V, 6, 1, 0, 34, 24)
