#include "som_c.h"
#include "som_hand_d.h"

/* C07715 find_current_hero_owned_row_before_native_equipment_exchange   [class B, 210 bytes, 87 instructions]
 * Source: src/rom/find_current_hero_owned_row_before_native_equipment_exchange.s
 * Documented in docs/event-menu-equipment-swap.md
 * Entry: M=any X=any DB=any D=any.  Callers read: ABXYCZNV.
 */
static void find_current_hero_owned_row_before_native_equipment_exchange(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, -1, -1)) return;
L_C07715:;
    i_sep(r, 0x30);
    LDA(c, ABS, 0x185c);
    CMP(c, ABS, 0x180a);
    if (!r->z) goto L_C0777D;
    LDY(c, ABS, 0x180b);
    a_ldx(r, 0x0);
    LDA(c, ABS, 0x1808);
    i_inca(r);
L_C07728:;
    CMP(c, ABX, 0x18a0);
    if (r->z) goto L_C07735;
    i_inx(r);
    i_inx(r);
    i_dey(r);
    if (!r->z) goto L_C07728;
L_C07732:;
    TAIL_CALL(c, 0xC07598, SOM_RTS);
L_C07735:;
    i_txa(r);
    i_lsra(r);
    STA(c, ABS, 0x185c);
    i_sep(r, 0x20);
    a_lda(r, 0x20);
    TSB(c, ABS, 0x1804);
    JSL(c, 0x7744, 0xD0C800);
    i_rep(r, 0x30);
    STY(c, ABS, 0x1853);
    STZ(c, ABS, 0x1820);
    LDA(c, ABS, 0x185c);
    JSR(c, 0x7752, 0xC07866);
    STX(c, ABS, 0x184f);
    STY(c, ABS, 0x1855);
    LDA(c, ABS, 0x180a);
    JSR(c, 0x775e, 0xC07866);
    STX(c, ABS, 0x1851);
    STY(c, ABS, 0x1857);
    i_sep(r, 0x20);
    LDA(c, ABS, 0x19f0);
    a_cmp(r, 0x2);
    if (!r->z) goto L_C0777F;
    LDA(c, ALX, 0x7ee01c);
    if (!r->z) goto L_C0777D;
    LDX(c, ABS, 0x184f);
    LDA(c, ALX, 0x7ee01c);
    if (r->z) goto L_C0777F;
L_C0777D:;
    goto L_C07732;
L_C0777F:;
    i_rep(r, 0x30);
    INC(c, ABS, 0x1820);
    LDA(c, ABS, 0x185c);
    JSR(c, 0x7789, 0xC07866);
    LDA(c, ABS, 0x180a);
    JSR(c, 0x778f, 0xC07866);
    LDA(c, ABS, 0x184f);
    r->c = 0;
    ADC(c, ABS, 0x1853);
    i_tax(r);
    JSR(c, 0x779a, 0xC07A54);
    i_pha(c);
    i_phx(c);
    LDA(c, ABS, 0x1851);
    r->c = 0;
    ADC(c, ABS, 0x1853);
    i_tax(r);
    JSR(c, 0x77a7, 0xC07A54);
    i_plx(c);
    JSR(c, 0x77ab, 0xC0781E);
    LDA(c, ABS, 0x1851);
    r->c = 0;
    ADC(c, ABS, 0x1853);
    i_tax(r);
    i_pla(c);
    JSR(c, 0x77b7, 0xC0781E);
    LDA(c, ABS, 0x184f);
    LDY(c, ABS, 0x1857);
    JSR(c, 0x77c0, 0xC077E7);
    LDA(c, ABS, 0x1851);
    LDY(c, ABS, 0x1855);
    JSR(c, 0x77c9, 0xC077E7);
    i_sep(r, 0x20);
    LDA(c, ABS, 0x1850);
    if (!r->z) goto L_C077D2;
    i_inca(r);
L_C077D2:;
    STA(c, ABS, 0x19f2);
    LDA(c, ABS, 0x1852);
    if (!r->z) goto L_C077DB;
    i_inca(r);
L_C077DB:;
    ORA(c, ABS, 0x19f2);
    STA(c, ABS, 0x19f2);
    JSR(c, 0x77e3, 0xC0761A);
    TAIL_CALL(c, 0xC07601, SOM_RTS);
}
SOM_REGISTER(0xC07715, SOM_RTS, "hand", find_current_hero_owned_row_before_native_equipment_exchange, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 4, -1, -1, 210, 87)
