#include "som_c.h"
#include "som_hand_d.h"

/* D3EC03 release_spell_entity_burst_sprite_object   [class B, 65 bytes, 38 instructions]
 * Source: src/rom/release_spell_entity_burst_sprite_object.s
 * Documented in docs/actor-cast-entity-burst-objects.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: nothing.
 */
static void release_spell_entity_burst_sprite_object(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    /* a six byte frame below the saved D and P holds the locals; D points into it */
    i_phd(c);
    i_php(c);
    i_rep(r, 0x20);
    i_tsc(r);
    r->c = 1;
    a_sbc(r, 0x0006);
    i_tcd(r);
    i_tcs(r);
    i_sep(r, 0x20);
    i_phb(c);
    a_lda(r, 0x7E);
    i_pha(c);
    i_plb(c);
    i_rep(r, 0x20);
    dp_wr16(c, 0x03, r->x); /* object */
    i_txy(r);
    a_lda(r, 0x0005);
    dp_wr16(c, 0x01, r->a); /* instances left */
    do {
        dp_wr16(c, 0x05, r->y);
        a_ldx(r, RAM16(r->y));
        JSL(c, 0xEC27, 0xC12E88); /* release_spell_sprite_instance_long */
        REQUIRE_M16(c);
        a_ldy(r, dp_rd16(c, 0x05));
        r->c = 0;
        i_tya(r);
        a_adc(r, 0x0010);
        i_tay(r);
        const uint16_t left = dp_rd16(c, 0x01) - 1;
        dp_wr16(c, 0x01, left);
        hand_nz16(r, left);
    } while (!r->z);
    a_ldx(r, dp_rd16(c, 0x03));
    JSL(c, 0xEC39, 0xC12E7C); /* release_spell_entity_heap_bank_long */
    i_plb(c);
    i_tsc(r);
    r->c = 0;
    a_adc(r, 0x0006);
    i_tcs(r);
    i_plp(c);
    i_pld(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0xD3EC03, SOM_RTS, "hand", release_spell_entity_burst_sprite_object, 0, 0, 11, 1, 0, 65, 38)
