#include "som_c.h"
#include "som_hand_d.h"
/* SOM_PLAIN_CALLS: every memory access below goes through the live DB / D registers, so a callee that returns with another data
 * bank is followed exactly and needs no data-bank check. */
#undef JSR
#undef JSL
#define JSR(c, retpc, target) CALL_JSR((c), (retpc), (target))
#define JSL(c, retpc, target) CALL_JSL((c), (retpc), (target))

/* 7E90DA submit_transfer_or_program_hdma   [class D, 138 bytes, 68 instructions]
 * Source: src/boot/submit_transfer_or_program_hdma.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$7F D=any.  Callers read: ABXYCZNV.
 */
#define ABSX(off) ((((uint32_t)r->db << 16) + (off) + r->x) & 0xFFFFFF)
#define ABSY(off) ((((uint32_t)r->db << 16) + (off) + r->y) & 0xFFFFFF)
#define ABS(off) ((((uint32_t)r->db << 16) + (off)) & 0xFFFFFF)

#define BANK7F(off) (0x7F0000u + (uint32_t)(off))

static void submit_transfer_or_program_hdma(SomCtx *c)
{
    Cpu *r = &c->cpu;
L_7E90DA:;
    i_phd(c);
    i_php(c);
    i_rep(r, 0x30);
    i_phx(c);
    i_tsc(r);
    i_tcd(r);
    i_sep(r, 0x20);
    i_phb(c);
    a_lda(r, 0x7f);
    i_pha(c);
    i_plb(c);
    a_cpx(r, 0x0);
    if (!r->z) goto L_7E90F0;
    goto L_7E915E;
L_7E90F0:;
    STX(c, DP, 0x1);
    LDA(c, ABX, 0xf);
    a_cmp(r, 0x5);
    if (r->z) goto L_7E9118;
    a_ora(r, 0x80);
    STA(c, ABX, 0xf);
    i_php(c);
    r->i = 1;
    i_rep(r, 0x20);
    LDA(c, ABS, 0x6c);
    i_asla(r);
    r->c = 0;
    ADC(c, ABS, 0x66);
    i_tax(r);
    LDA(c, DP, 0x1);
    STA(c, ABX, 0x0);
    i_sep(r, 0x20);
    INC(c, ABS, 0x6c);
    i_plp(c);
    goto L_7E915E;
L_7E9118:;
    LDA(c, ABX, 0x9);
    i_rep(r, 0x20);
    a_and(r, 0xff);
    i_tax(r);
    JSR(c, 0x9123, 0x7EC365);
    i_asla(r);
    i_asla(r);
    i_asla(r);
    i_asla(r);
    i_tax(r);
    LDY(c, DP, 0x1);
    LDA(c, ABY, 0x0);
    STA(c, ALX, 0x4300);
    LDA(c, ABY, 0x1);
    STA(c, ALX, 0x4301);
    LDA(c, ABY, 0x4);
    STA(c, ALX, 0x4304);
    i_rep(r, 0x20);
    LDA(c, ABY, 0x2);
    STA(c, ALX, 0x4302);
    i_sep(r, 0x20);
    LDA(c, ABY, 0x9);
    ORA(c, ABS, 0x70);
    STA(c, ABS, 0x70);
    LDA(c, ABY, 0x9);
    a_cmp(r, 0x1);
    if (!r->z) goto L_7E915E;
    STY(c, ABS, 0x7a);
L_7E915E:;
    i_plb(c);
    i_pla(c);
    i_pla(c);
    i_plp(c);
    i_pld(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E90DA, SOM_RTS, "hand", submit_transfer_or_program_hdma, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 9, 1, 0, 138, 68)
