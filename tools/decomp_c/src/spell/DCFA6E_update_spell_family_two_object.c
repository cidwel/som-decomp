#include "som_c.h"
#include "som_hand_b.h"

/* DCFA6E update_spell_family_two_object   [class A, 29 bytes, 17 instructions]
 * Source: src/rom/update_spell_family_two_object.s
 * Documented in docs/actor-cast-entity-mode-two.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void update_spell_family_two_object(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    i_phd(c);
    i_php(c);
    r->mf = 0; /* REP #$20 */
    r->mf = 1; /* SEP #$20 */
    i_phx(c);
    JSR_CHK(c, 0xFA77, 0xDCFA25); /* project_spell_family_two_object */
    r->mf = 1;
    r->xf = 0;
    r->sp += 2; /* PLX */
    r->x = (uint16_t)(c->wram[(r->sp - 1) & 0x1FFFF] | (c->wram[r->sp & 0x1FFFF] << 8));
    hand_nz16(r, r->x);
    /* the callee can leave another data bank (it pops DB from the stack): index through the live DB */
    const uint32_t ea = (((uint32_t)r->db << 16) + 0x0024 + r->x) & 0xFFFFFF;
    uint8_t v = BUS8(c, ea);
    hand_lda8(r, v);
    v = (uint8_t)(v + 1);
    hand_lda8(r, v);
    r->c = v >= 2;
    hand_nz8(r, (uint8_t)(v - 2));
    if (r->c) { v = 0; hand_lda8(r, 0); }
    BUS8_SET(c, ea, v);
    hand_lda8(r, 0xFF);
    hand_plp(c);
    hand_pld(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0xDCFA6E, SOM_RTS, "hand", update_spell_family_two_object, 0, 0, 5, 1, 0, 29, 17)
