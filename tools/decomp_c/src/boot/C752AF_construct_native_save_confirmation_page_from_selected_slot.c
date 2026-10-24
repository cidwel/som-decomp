#include "som_c.h"
#include "som_hand_d.h"

/* C752AF construct_native_save_confirmation_page_from_selected_slot   [class B, 93 bytes, 34 instructions]
 * Source: src/rom/construct_native_save_confirmation_page_from_selected_slot.s
 * Documented in docs/ui-native-saved-game-menu-request.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: nothing.
 */
static void construct_native_save_confirmation_page_from_selected_slot(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
L_C752AF:;
    JSR(c, 0x52b1, 0xC75DDC);
    REQUIRE_M8(c);
    a_lda(r, 0x1);
    STA(c, ABS, 0xa20f);
    JSL(c, 0x52ba, 0xC02ACB);
    JSR(c, 0x52bd, 0xC7553F);
    JSR(c, 0x52c0, 0xC75DF9);
    LDA(c, ABS, 0xa215);
    STA(c, ABS, 0xa216);
    LDA(c, ABS, 0xa211);
    STA(c, ABS, 0xa162);
    if (r->z) goto L_C752D8;
L_C752CF:;
    LSR(c, ABS, 0xa216);
    LSR(c, ABS, 0xa216);
    i_deca(r);
    if (!r->z) goto L_C752CF;
L_C752D8:;
    REQUIRE_M8(c);
    a_lda(r, 0x0);
    STA(c, ABS, 0xa177);
    REQUIRE_X16(c);
    a_ldx(r, 0x0);
L_C752E0:;
    JSR(c, 0x52e2, 0xC7530C);
    INC(c, ABS, 0xa177);
    REQUIRE_M8(c);
    a_lda(r, 0x3);
    CMP(c, ABS, 0xa177);
    if (!r->z) goto L_C752E0;
    JSR(c, 0x52ef, 0xC75369);
    LDA(c, ABS, 0xa216);
    REQUIRE_M8(c);
    a_and(r, 0x3);
    REQUIRE_M8(c);
    a_cmp(r, 0x3);
    if (r->z) goto L_C752FC;
    JSR(c, 0x52fb, 0xC7541E);
L_C752FC:;
    JSL(c, 0x52ff, 0xC02ACF);
    JSR(c, 0x5302, 0xC75E95);
    JSL(c, 0x5306, 0xC02AD3);
    JSL(c, 0x530a, 0xC02AC7);
    RETURN_RTL(c);
}
SOM_REGISTER(0xC752AF, SOM_RTL, "hand", construct_native_save_confirmation_page_from_selected_slot, 0, 0, 1, 1, 0, 93, 34)
