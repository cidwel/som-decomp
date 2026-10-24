#include "som_c.h"
#include "som_hand_d.h"

/* C09A60 scene_row_rle_decoder_rom_template   [class D, 49 bytes, 27 instructions]
 * Source: src/rom/scene_row_rle_decoder_rom_template.s
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
/* abs in the data bank of the caller: a 24-bit sum, no wrap inside the bank */
#define DBABS(off) ((((uint32_t)r->db << 16) + (off)) & 0xFFFFFF)

static void scene_row_rle_decoder_rom_template(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 0)) return;
    for (;;) {
        a_lda(r, BUS8(c, DBABS(0x8400 + r->y))); /* control byte: literal below $C0, run length + value above */
        if (c->fail) return;
        a_cmp(r, 0xC0);
        if (!r->c) {
            BUS8_SET(c, 0x2180, r->a); /* WMDATA */
            i_iny(r);
            i_dex(r);
            if (r->n) break;
        } else {
            a_and(r, 0x3F);
            dp_wr8(c, 0x3A, r->a);
            i_iny(r);
            a_lda(r, BUS8(c, DBABS(0x8400 + r->y)));
            if (c->fail) return;
            i_iny(r);
            i_phy(c);
            a_ldy(r, dp_rd16(c, 0x3A));
            do {
                BUS8_SET(c, 0x2180, r->a);
                i_dey(r);
            } while (!r->n);
            i_ply(c);
            i_rep(r, 0x20);
            i_txa(r);
            r->c = 0;
            a_sbc(r, dp_rd16(c, 0x3A));
            i_tax(r);
            i_sep(r, 0x20);
            if (r->n) break;
        }
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC09A60, SOM_RTS, "hand", scene_row_rle_decoder_rom_template, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 1, 0, 49, 27)
