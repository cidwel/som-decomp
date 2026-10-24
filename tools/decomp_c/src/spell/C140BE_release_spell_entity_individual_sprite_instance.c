#include "som_c.h"
#include "som_hand_d.h"

/* C140BE release_spell_entity_individual_sprite_instance   [class A, 39 bytes, 20 instructions]
 * Source: src/rom/release_spell_entity_individual_sprite_instance.s
 * Documented in docs/actor-cast-entity-sprite-instances.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: BYCV.
 */
static void release_spell_entity_individual_sprite_instance(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    i_phd(c);
    i_php(c);
    i_rep(r, 0x20);
    a_lda(r, 0xFFF0);
    RAM16_SET(0x0002 + r->x, r->a);
    RAM16_SET(0x0004 + r->x, 0);
    RAM16_SET(0x0008 + r->x, 0);
    a_lda(r, RAM16(0x000A + r->x));
    a_and(r, 0x00FF);
    i_asla(r);
    i_asla(r);
    r->c = 0;
    a_adc(r, RAM16(0x841E));
    i_tax(r);
    i_sep(r, 0x20);
    a_lda(r, 0xF0);
    RAM8(0x0001 + r->x) = r->a;
    i_plp(c);
    i_pld(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC140BE, SOM_RTS, "hand", release_spell_entity_individual_sprite_instance, 0, L_B | L_Y | L_C | L_V, 3, 1, 0, 39, 20)
