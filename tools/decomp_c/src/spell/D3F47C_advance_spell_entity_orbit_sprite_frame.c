#include "som_c.h"
#include "som_hand_b.h"

/* D3F47C advance_spell_entity_orbit_sprite_frame   [class B, 51 bytes, 29 instructions]
 * Source: src/rom/advance_spell_entity_orbit_sprite_frame.s
 * Documented in docs/actor-cast-entity-orbit-callbacks.md
 * Entry: DB=$7E, any M/X/D (REP #$20 comes first).  Callers read: nothing.
 */
static void advance_spell_entity_orbit_sprite_frame(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, -1)) return;
    i_phd(c);
    i_php(c);
    i_rep(r, 0x20);
    i_phx(c);
    i_tsc(r);
    i_tcd(r);
    i_sep(r, 0x20);
    if (r->xf) dp_wr8(c, 0x01, r->x); else dp_wr16(c, 0x01, r->x);   /* STX $01 */
    a_lda(r, RAM8(0x001A + r->x));
    { const uint16_t sp_call = r->sp; JSR(c, 0xF48C, 0xD3F34F); GUARD_JSR_DB(c, sp_call, 0xF48C, 0x7E); } /* project_spell_entity_orbit_sprite_group */
    hand_ldx_dp(c, 0x01);
    a_ldy(r, r->xf ? RAM8(0x001A + r->x) : RAM16(0x001A + r->x));
    r->c = 0;
    i_rep(r, 0x20);
    i_txa(r);
    a_adc(r, 0x000C);
    i_tax(r);
    i_sep(r, 0x20);
    i_tya(r);
    { const uint16_t sp_call = r->sp; JSR(c, 0xF49F, 0xD3F34F); GUARD_JSR_DB(c, sp_call, 0xF49F, 0x7E); } /* project_spell_entity_orbit_sprite_group */
    hand_ldx_dp(c, 0x01);
    RAM8(0x001A + r->x) = m_inc(r, RAM8(0x001A + r->x));
    a_lda(r, 0x06);
    RAM8(0x0018 + r->x) = r->a;
    i_pla(c);
    i_pla(c);
    hand_plp(c);
    i_pld(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0xD3F47C, SOM_RTS, "hand", advance_spell_entity_orbit_sprite_frame, 0, 0, 5, 1, 0, 51, 29)
