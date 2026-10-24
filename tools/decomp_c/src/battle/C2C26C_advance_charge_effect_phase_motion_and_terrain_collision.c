#include "som_c.h"
#include "som_hand_d.h"

/* C2C26C advance_charge_effect_phase_motion_and_terrain_collision   [class C, 341 bytes, 164 instructions]
 * Source: src/rom/advance_charge_effect_phase_motion_and_terrain_collision.s
 * Documented in docs/actor-charge-effect-update.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void advance_charge_effect_phase_motion_and_terrain_collision(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    i_sep(r, 0x20);
    LDA(c, ABY, 0xD000); /* phase */
    if (r->z) RETURN_RTS(c);
    a_biti(r, 0xF8);
    if (!r->z) { /* still counting down in steps of 8 */
        r->c = 1;
        a_sbc(r, 0x08);
        STA(c, ABY, 0xD000);
        RETURN_RTS(c);
    }
    LDA(c, ABY, 0xD007); /* hold timer */
    if (!r->z) {
        i_deca(r);
        STA(c, ABY, 0xD007);
        if (r->z) STA(c, ABY, 0xD000);
        RETURN_RTS(c);
    }
    JSR(c, 0xC290, 0xC2C526);
    bool blocked = r->c;
    if (!blocked) {
        JSR(c, 0xC295, 0xC2C183);
        CMP(c, ABY, 0xD006);
        blocked = r->c;
    }
    if (blocked) {
        a_lda(r, 0x08);
        STA(c, ABY, 0xD007);
        LDA(c, ABY, 0xD00E);
        r->c = 0;
        a_adc(r, 0x02);
        STA(c, ABY, 0xD00E);
        RETURN_RTS(c);
    }
    LDA(c, ABY, 0xD008);
    r->c = 0;
    ADC(c, ABY, 0xD00A);
    if (r->c) {
        a_lda(r, 0x00);
        STA(c, ABY, 0xD00A);
        a_lda(r, 0xFF);
    }
    STA(c, ABY, 0xD008);
    LDA(c, ABY, 0xD009);
    r->c = 0;
    ADC(c, ABY, 0xD00A);
    if (r->c) a_lda(r, 0xFF);
    STA(c, ABY, 0xD009);
    i_phx(c);
    i_rep(r, 0x20);
    a_and(r, 0x00FF);
    a_cmp(r, 0x0080);
    if (r->c) a_eor(r, 0x00FF);
    i_asla(r);
    i_asla(r);
    i_tax(r);
    LDA(c, ALX, 0xFD22);
    for (int i = 0; i < 6; i++) i_lsra(r);
    STA(c, DP, 0x00);
    LDA(c, ABY, 0xD008);
    a_and(r, 0x00FF);
    i_asla(r);
    i_tax(r);
    LDA(c, ALX, 0xFD22);
    i_plx(c);
    for (int i = 0; i < 5; i++) i_lsra(r);
    i_sep(r, 0x20);
    a_eor(r, 0xFF);
    r->c = 1;
    a_adc(r, 0x08);
    STA(c, DP, 0x01);
    a_lda(r, 0x04);
    r->c = 1;
    SBC(c, DP, 0x00);
    STA(c, DP, 0x00);
    LDA(c, ABY, 0xD000);
    a_cmp(r, 0x03);
    if (!r->c) {
        LDA(c, ABY, 0xD009);
        if (r->n) {
            LDA(c, ABY, 0xD006);
            r->c = 1;
            SBC(c, DP, 0x00);
            if (!r->c) { /* ran out of room: stop */
                a_lda(r, 0x08);
                STA(c, ABY, 0xD007);
                LDA(c, ABY, 0xD00E);
                r->c = 0;
                a_adc(r, 0x02);
                STA(c, ABY, 0xD00E);
                RETURN_RTS(c);
            }
        } else {
            LDA(c, DP, 0x00);
            i_lsra(r);
            r->c = 0;
            ADC(c, DP, 0x00);
            STA(c, DP, 0x00);
            ADC(c, ABY, 0xD006);
        }
        STA(c, ABY, 0xD006);
        if (!r->c) {
            LDA(c, DP, 0x00);
            a_eor(r, 0xFF);
            i_inca(r);
            STA(c, DP, 0x00);
        }
    }
    LDA(c, ABY, 0xD001); /* direction bits */
    a_and(r, 0x03);
    a_cmp(r, 0x02);
    if (r->c) {
        LDA(c, ABY, 0xD000);
        a_cmp(r, 0x03);
        LDA(c, DP, 0x00);
        i_rep(r, 0x20);
        if (!r->c) { /* horizontal step, wrapped into the range of $C2 */
            if (r->n) {
                a_ora(r, 0xFF00);
                r->c = 0;
                ADC(c, ABY, 0xD004);
                if (r->n) ADC(c, DP, 0xC2);
            } else {
                a_and(r, 0x00FF);
                r->c = 0;
                ADC(c, ABY, 0xD004);
                CMP(c, DP, 0xC2);
                if (r->c) SBC(c, DP, 0xC2);
            }
            STA(c, ABY, 0xD004);
        }
        LDA(c, ABY, 0xD001);
        i_lsra(r);
        if (r->c) {
            LDA(c, DP, 0x01);
            a_and(r, 0x00FF);
            a_eor(r, 0xFFFF);
            ADC(c, ABY, 0xD002);
            if (r->n) ADC(c, DP, 0xC0);
        } else {
            LDA(c, DP, 0x01);
            a_and(r, 0x00FF);
            r->c = 0;
            ADC(c, ABY, 0xD002);
            CMP(c, DP, 0xC0);
            if (r->c) SBC(c, DP, 0xC0);
        }
        STA(c, ABY, 0xD002);
        RETURN_RTS(c);
    }
    LDA(c, ABY, 0xD001);
    i_lsra(r);
    i_rep(r, 0x20);
    if (!r->c) {
        LDA(c, DP, 0x01);
        a_and(r, 0x00FF);
        a_eor(r, 0xFFFF);
        ADC(c, ABY, 0xD004);
        if (r->n) ADC(c, DP, 0xC2);
    } else {
        LDA(c, DP, 0x01);
        a_and(r, 0x00FF);
        r->c = 0;
        ADC(c, ABY, 0xD004);
        CMP(c, DP, 0xC2);
        if (r->c) SBC(c, DP, 0xC2);
    }
    STA(c, ABY, 0xD004);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2C26C, SOM_RTS, "hand", advance_charge_effect_phase_motion_and_terrain_collision, 0, L_B | L_X | L_Y | L_C | L_V, 2, 0, 0, 341, 164)
