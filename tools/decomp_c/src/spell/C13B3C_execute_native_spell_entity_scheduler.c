#include "som_c.h"
#include "som_hand_d.h"

/* C13B3C execute_native_spell_entity_scheduler   [class C, 151 bytes, 78 instructions]
 * Source: src/rom/execute_native_spell_entity_scheduler.s
 * Documented in docs/actor-cast-entity-engine.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void execute_native_spell_entity_scheduler(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
L_C13B3C:;
    i_phd(c);
    i_php(c);
    i_rep(r, 0x20);
    i_tsc(r);
    r->c = 1;
    a_sbc(r, 0xa);
    i_tcd(r);
    i_tcs(r);
    i_sep(r, 0x20);
    i_phb(c);
    a_lda(r, 0x7e);
    i_pha(c);
    i_plb(c);
    i_rep(r, 0x20);
    i_txa(r);
    a_and(r, 0x1e00);
    r->c = 0;
    a_adc(r, 0xe000);
    i_tax(r);
    JSR(c, 0x3b5b, 0xC139CD);
    REQUIRE_X16(c);
    a_cpx(r, 0x0);
    if (r->z) goto L_C13BC1;
    STX(c, DP, 0x3);
L_C13B63:;
    JSR(c, 0x3b65, 0xC12FE4);
    LDX(c, DP, 0x3);
    LDA(c, ABX, 0x25);
    REQUIRE_M16(c);
    a_and(r, 0xff);
    i_asla(r);
    i_txy(r);
    i_tax(r);
    { push16(c, 0x3b73); uint16_t t_ = rd16(c, ((uint32_t)r->k << 16) | ((0x3b2e + r->x) & 0xFFFF), ((uint32_t)r->k << 16) | ((0x3b2e + r->x + 1) & 0xFFFF)); som_call(c, ((uint32_t)r->k << 16) | t_, SOM_RTS); }
    LDX(c, DP, 0x3);
    LDA(c, ABX, 0x2a);
    STA(c, DP, 0x1);
    JSR(c, 0x3b7d, 0xC12FE4);
L_C13B7E:;
    LDX(c, DP, 0x3);
    REQUIRE_M16(c);
    a_lda(r, 0xff);
    STA(c, DP, 0x9);
    REQUIRE_M16(c);
    a_lda(r, 0x4);
    STA(c, DP, 0x7);
    i_txa(r);
    r->c = 0;
    REQUIRE_M16(c);
    a_adc(r, 0x0);
L_C13B8F:;
    STA(c, DP, 0x5);
    i_tay(r);
    LDA(c, ABY, 0x4);
    if (r->z) goto L_C13BA0;
    push16(c, 0x3b9f);                  /* pea $3B9F; pha; rts is a call whose return lands on L_C13BA0 */
    LDX(c, ABY, 0x2);
    i_deca(r);
    { uint16_t t_ = (uint16_t)(r->a + 1); som_call(c, ((uint32_t)r->k << 16) | t_, SOM_RTS); }
L_C13BA0:;
    REQUIRE_M16(c);
    a_eor(r, 0xff);
    AND(c, DP, 0x9);
    STA(c, DP, 0x9);
    LDA(c, DP, 0x5);
    r->c = 0;
    REQUIRE_M16(c);
    a_adc(r, 0x8);
    DEC(c, DP, 0x7);
    if (!r->z) goto L_C13B8F;
    JSR(c, 0x3bb3, 0xC12FE4);
    LDA(c, DP, 0x9);
    REQUIRE_M16(c);
    a_and(r, 0xff);
    if (!r->z) goto L_C13BBF;
    DEC(c, DP, 0x1);
    if (!r->z) goto L_C13B7E;
L_C13BBF:;
    LDX(c, DP, 0x3);
L_C13BC1:;
    JSR(c, 0x3bc3, 0xC13AC5);
    REQUIRE_X16(c);
    a_cpx(r, 0x0);
    if (!r->z) goto L_C13B63;
    i_plb(c);
    i_tsc(r);
    r->c = 0;
    REQUIRE_M16(c);
    a_adc(r, 0xa);
    i_tcs(r);
    i_plp(c);
    i_pld(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC13B3C, SOM_RTS, "hand", execute_native_spell_entity_scheduler, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 18, 1, 0, 151, 78)
