#include "som_c.h"
#include "som_hand_d.h"

/* D3F4B3 update_spell_entity_orbit_sprite_object   [class B, 62 bytes, 36 instructions]
 * Source: src/rom/update_spell_entity_orbit_sprite_object.s
 * Documented in docs/actor-cast-entity-orbit-callbacks.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: nothing.
 */
static void update_spell_entity_orbit_sprite_object(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    /* a four byte frame below the saved D and P holds the locals; D points into it */
    i_phd(c);
    i_php(c);
    i_rep(r, 0x20);
    i_tsc(r);
    r->c = 1;
    a_sbc(r, 0x0004);
    i_tcd(r);
    i_tcs(r);
    dp_wr16(c, 0x03, r->x); /* object */
    RAM16_SET(0x00E8 + r->x, m_dec(r, RAM16(0x00E8 + r->x)));
    if (r->z) JSR(c, 0xF4C7, 0xD3F398); /* advance_spell_entity_orbit_state */
    REQUIRE_M16(c);
    a_lda(r, 0x0008);
    dp_wr16(c, 0x01, r->a); /* sprites left */
    a_ldx(r, dp_rd16(c, 0x03));
    do {
        RAM16_SET(0x0018 + r->x, m_dec(r, RAM16(0x0018 + r->x)));
        if (r->z) {
            i_phx(c);
            JSR(c, 0xF4D7, 0xD3F47C); /* advance_spell_entity_orbit_sprite_frame */
            i_plx(c);
        }
        r->c = 0;
        i_txa(r);
        REQUIRE_M16(c);
        a_adc(r, 0x001C);
        i_tax(r);
        const uint16_t left = dp_rd16(c, 0x01) - 1;
        dp_wr16(c, 0x01, left);
        hand_nz16(r, left);
    } while (!r->z);
    a_lda(r, 0x00FF);
    i_sep(r, 0x20);
    som_wr(c, (uint16_t)(r->sp + 4), r->a); /* STA $04,S */
    i_pla(c);
    i_pla(c);
    i_pla(c);
    i_pla(c);
    i_plp(c);
    i_pld(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0xD3F4B3, SOM_RTS, "hand", update_spell_entity_orbit_sprite_object, 0, 0, 9, 1, 0, 62, 36)
