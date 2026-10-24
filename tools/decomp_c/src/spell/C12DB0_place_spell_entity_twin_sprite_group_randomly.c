#include "som_c.h"
#include "som_hand_d.h"

/* C12DB0 place_spell_entity_twin_sprite_group_randomly   [class B, 82 bytes, 42 instructions]
 * Source: src/rom/place_spell_entity_twin_sprite_group_randomly.s
 * Documented in docs/actor-cast-entity-twin-callbacks.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: V.
 */
static void place_spell_entity_twin_sprite_group_randomly(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
L_C12DB0:;
    i_phd(c);
    i_php(c);
    i_rep(r, 0x20);
    i_tsc(r);
    r->c = 1;
    a_sbc(r, 0x4);
    i_tcd(r);
    i_tcs(r);
    STX(c, DP, 0x1);
    STY(c, DP, 0x3);
    a_lda(r, 0x40);
    JSL(c, 0x2dc5, 0xC12ED1);
    r->c = 1;
    REQUIRE_M16(c);
    a_sbc(r, 0x20);
    LDY(c, DP, 0x3);
    r->c = 0;
    ADC(c, ABY, 0x2);
    LDX(c, DP, 0x1);
    STA(c, ABX, 0x16);
    REQUIRE_M16(c);
    a_lda(r, 0x40);
    JSL(c, 0x2ddb, 0xC12ED1);
    r->c = 1;
    REQUIRE_M16(c);
    a_sbc(r, 0x20);
    LDY(c, DP, 0x3);
    r->c = 0;
    ADC(c, ABY, 0x0);
    LDX(c, DP, 0x1);
    STA(c, ABX, 0x14);
    i_sep(r, 0x20);
    a_lda(r, 0x4);
    JSL(c, 0x2df2, 0xC12ED1);
    REQUIRE_M8(c);
    a_eor(r, 0xff);
    i_inca(r);
    LDX(c, DP, 0x1);
    STA(c, ABX, 0x18);
    i_pla(c);
    i_pla(c);
    i_pla(c);
    i_pla(c);
    i_plp(c);
    i_pld(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC12DB0, SOM_RTS, "hand", place_spell_entity_twin_sprite_group_randomly, 0, L_V, 7, 1, 0, 82, 42)
