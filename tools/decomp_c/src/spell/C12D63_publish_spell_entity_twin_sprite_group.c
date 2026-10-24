#include "som_c.h"
#include "som_hand_b.h"

/* C12D63 publish_spell_entity_twin_sprite_group   [class B, 77 bytes, 48 instructions]
 * Source: src/rom/publish_spell_entity_twin_sprite_group.s
 * Documented in docs/actor-cast-entity-twin-callbacks.md
 * Entry: DB=$7E, any M/X/D (REP #$20 comes first).  Callers read: nothing.
 */
/* A callee that replaces its own return address: the interpreter continues from the popped address (see som_hand_b.h). */
#undef I_JSL
#define I_JSL(c, retpc, target) HAND_JSL_RESUME(c, retpc, target, sp0)

static void publish_spell_entity_twin_sprite_group(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    const uint16_t sp0 = r->sp;
    if (!hand_require(c, 0x7E, -1, -1)) return;
    i_phd(c);
    i_php(c);
    i_rep(r, 0x20);
    i_tsc(r);
    r->c = 1;
    a_sbc(r, 0x0004);
    i_tcd(r);
    i_tcs(r);
    i_sep(r, 0x20);
    a_lda(r, RAM8(0x0018 + r->x));
    dp_wr8(c, 0x01, r->a);
    i_asla(r);
    i_asla(r);
    r->c = 0;
    a_adc(r, dp_rd8(c, 0x01));
    i_asla(r);
    i_asla(r);
    i_rep(r, 0x20);
    a_and(r, 0x00FF);
    r->c = 0;
    a_adc(r, 0xFB3D);
    r->c = 1;
    a_sbc(r, 0xF800);
    i_txy(r);
    i_tax(r);
    a_lda(r, RAM16(0x0014 + r->y));
    i_pha(c);
    a_lda(r, RAM16(0x0016 + r->y));
    i_pha(c);
    i_sep(r, 0x20);
    a_lda(r, 0x0A);
    dp_wr8(c, 0x04, r->a);
    do {
        if (r->xf) dp_wr8(c, 0x02, r->y); else dp_wr16(c, 0x02, r->y);   /* STY $02 */
        JSL(c, 0x2D9E, 0xC12E94); /* project_packed_spell_entity_sprite_record_long */
        if (r->xf) a_ldy(r, dp_rd8(c, 0x02)); else a_ldy(r, dp_rd16(c, 0x02));
        i_iny(r);
        i_iny(r);
        dp_wr8(c, 0x04, m_dec(r, dp_rd8(c, 0x04)));
    } while (!r->z);
    i_ply(c);
    i_ply(c);
    i_pla(c);
    i_pla(c);
    i_pla(c);
    i_pla(c);
    hand_plp(c);
    i_pld(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC12D63, SOM_RTS, "hand", publish_spell_entity_twin_sprite_group, 0, 0, 11, 1, 0, 77, 48)
