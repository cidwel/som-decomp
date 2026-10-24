#include "som_c.h"
#include "som_hand_d.h"

/* C14161 initialize_spell_entity_sprite_slots   [class B, 47 bytes, 26 instructions]
 * Source: src/rom/initialize_spell_entity_sprite_slots.s
 * Documented in docs/actor-cast-entity-setup.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$01CC.  Callers read: BXYCZNV.
 */
static void initialize_spell_entity_sprite_slots(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, 0)) return;
    i_phd(c);
    i_php(c);
    i_rep(r, 0x20);
    i_sep(r, 0x20);
    i_phb(c);
    a_lda(r, 0x7E);
    i_pha(c);
    i_plb(c);
    i_rep(r, 0x20);
    a_ldx(r, 0x0400);
    a_lda(r, 0x0000);
    JSR(c, 0x4176, 0xC13D48); /* allocate_and_fill_spell_entity_heap_bytes */
    REQUIRE_M16X16(c);
    RAM16_SET(0x8424, r->x); /* sprite slot table */
    a_ldy(r, 0x0010);
    do {
        a_lda(r, 0x8000);
        RAM16_SET(r->x, r->a);
        r->c = 0;
        i_txa(r);
        a_adc(r, 0x0020);
        i_tax(r);
        i_dey(r);
    } while (!r->z);
    i_plb(c);
    i_plp(c);
    i_pld(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC14161, SOM_RTS, "hand", initialize_spell_entity_sprite_slots, 0, L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 0, 0, 47, 26)
