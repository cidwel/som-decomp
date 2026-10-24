#include "som_c.h"
#include "som_hand.h"

/* D3EF74 project_spell_sprite_object_child   [class B, 58 bytes, 37 instructions]
 * Source: src/rom/project_spell_sprite_object_child.s
 * Documented in docs/actor-cast-entity-sprite-motion.md
 * Entry: DB=$7E, any M/X/D (REP #$30 comes first).  Callers read: Y.
 */
static void project_spell_sprite_object_child(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, -1)) return;
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
    dp_wr8(c, 0x01, r->a);
    i_asla(r);
    r->c = 0;
    a_adc(r, dp_rd8(c, 0x01));
    r->c = 0;
    a_adc(r, RAM8(0x0006 + r->x));
    i_asla(r);
    i_rep(r, 0x20);
    a_and(r, 0x00FF);
    r->c = 0;
    a_adc(r, 0xF859);
    r->c = 1;
    a_sbc(r, 0xF800);
    i_txy(r);
    i_tax(r);
    a_lda(r, RAM16(0x0002 + r->y));
    i_pha(c);
    a_lda(r, RAM16(0x0004 + r->y));
    i_pha(c);
    { const uint16_t sp_call = r->sp; JSL(c, 0xEFA5, 0xC12E94); GUARD_JSL_DB(c, sp_call, 0xEFA5, 0x7E); } /* project_packed_spell_entity_sprite_record_long */
    i_pla(c);
    i_pla(c);
    i_sep(r, 0x20);
    i_pla(c);
    hand_plp(c);
    i_pld(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0xD3EF74, SOM_RTS, "hand", project_spell_sprite_object_child, 0, L_Y, 8, 1, 0, 58, 37)
