#include "som_c.h"
#include "som_hand_d.h"

/* C09C2B emit_ui_sprite_tile_grid   [class B, 128 bytes, 73 instructions]
 * Source: src/rom/emit_ui_sprite_tile_grid.s
 * Documented in docs/ui-native-ui-frame-sprites.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void emit_ui_sprite_tile_grid(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    uint8_t byte;
    uint16_t word;
    if (!hand_require(c, 0x00, 1, 1)) return;
    i_sep(r, 0x30);
    dp_wr8(c, 0x13, 0); /* row shear */
    a_ldy(r, 0x00);
    a_lda(r, dp_rd8(c, 0x08));
    dp_wr8(c, 0x0D, r->a); /* x of the row start */
    a_lda(r, dp_rd8(c, 0x09));
    dp_wr8(c, 0x0E, r->a); /* y of the row start */
    BUS8_OK(c, hand_idy(c, 0x00), byte); /* grid header: columns in the low nibble, rows in the high one */
    a_lda(r, byte);
    i_pha(c);
    a_and(r, 0x0F);
    dp_wr8(c, 0x0A, r->a); /* columns */
    dp_wr8(c, 0x0C, r->a); /* columns left in the row */
    a_cmp(r, 0x04);
    if (r->z) {
        a_lda(r, dp_rd8(c, 0x12));
        dp_wr8(c, 0x13, r->a);
        i_asla(r);
        a_eor(r, 0xFF);
        r->c = 1;
        a_adc(r, dp_rd8(c, 0x09));
        dp_wr8(c, 0x09, r->a);
        dp_wr8(c, 0x0E, r->a);
    }
    i_pla(c);
    i_lsra(r);
    i_lsra(r);
    i_lsra(r);
    i_lsra(r);
    dp_wr8(c, 0x0B, r->a); /* rows left */
    i_iny(r);
    a_ldx(r, dp_rd8(c, 0x7C)); /* OAM shadow write index */
    do {
        do {
            i_rep(r, 0x20);
            a_lda(r, dp_rd16(c, 0x08));
            RAM16_SET(0x0800 + r->x, r->a);
            BUS16_OK(c, hand_idy(c, 0x00), word);
            a_lda(r, word);
            RAM16_SET(0x0802 + r->x, r->a);
            i_inx(r);
            i_inx(r);
            i_inx(r);
            i_inx(r);
            i_sep(r, 0x20);
            i_iny(r);
            i_iny(r);
            a_lda(r, dp_rd8(c, 0x08));
            r->c = 0;
            a_adc(r, 0x08);
            dp_wr8(c, 0x08, r->a);
            a_lda(r, dp_rd8(c, 0x13));
            if (!r->z) {
                r->c = 0;
                a_adc(r, dp_rd8(c, 0x09));
                dp_wr8(c, 0x09, r->a);
                a_lda(r, dp_rd8(c, 0x0C));
                a_cmp(r, 0x03);
                if (r->z) {
                    a_lda(r, dp_rd8(c, 0x13));
                    r->c = 0;
                    a_adc(r, dp_rd8(c, 0x09));
                    dp_wr8(c, 0x09, r->a);
                }
            }
            byte = dp_rd8(c, 0x0C) - 1;
            dp_wr8(c, 0x0C, byte);
            hand_nz8(r, byte);
        } while (!r->z);
        a_lda(r, dp_rd8(c, 0x0D));
        dp_wr8(c, 0x08, r->a);
        a_lda(r, dp_rd8(c, 0x0A));
        dp_wr8(c, 0x0C, r->a);
        a_lda(r, dp_rd8(c, 0x0E));
        r->c = 0;
        a_adc(r, 0x08);
        dp_wr8(c, 0x0E, r->a);
        dp_wr8(c, 0x09, r->a);
        byte = dp_rd8(c, 0x0B) - 1;
        dp_wr8(c, 0x0B, byte);
        hand_nz8(r, byte);
    } while (!r->z);
    dp_wr8(c, 0x7C, r->x);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC09C2B, SOM_RTS, "hand", emit_ui_sprite_tile_grid, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 128, 73)
