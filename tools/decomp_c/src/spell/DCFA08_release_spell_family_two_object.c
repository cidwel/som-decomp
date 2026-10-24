#include "som_c.h"
#include "som_hand_b.h"

/* DCFA08 release_spell_family_two_object   [class A, 29 bytes, 17 instructions]
 * Source: src/rom/release_spell_family_two_object.s
 * Documented in docs/actor-cast-entity-mode-two.md
 * Entry: any M/X/DB/D (REP #$20 comes first).  Callers read: nothing.
 */
/* A callee that replaces its own return address: the interpreter continues from the popped address (see som_hand_b.h). */
#undef I_JSL
#define I_JSL(c, retpc, target) HAND_JSL_RESUME(c, retpc, target, sp0)

static void release_spell_family_two_object(SomCtx *c)
{
    Cpu *r = &c->cpu;
    const uint16_t sp0 = r->sp;
    i_phd(c);
    i_php(c);
    i_rep(r, 0x20);
    i_phx(c);
    i_tsc(r);
    i_tcd(r);
    if (r->xf) dp_wr8(c, 0x01, r->x); else dp_wr16(c, 0x01, r->x);   /* STX $01 */
    a_lda(r, 0x0010);
    JSL(c, 0xFA17, 0xC12EB9); /* release_spell_entity_sprite_pointer_group_long */
    hand_ldx_dp(c, 0x01);
    JSL(c, 0xFA1D, 0xC12E7C); /* release_spell_entity_heap_bank_long */
    i_sep(r, 0x20);
    i_pla(c);
    i_pla(c);
    hand_plp(c);
    i_pld(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0xDCFA08, SOM_RTS, "hand", release_spell_family_two_object, 0, 0, 5, 1, 0, 29, 17)
