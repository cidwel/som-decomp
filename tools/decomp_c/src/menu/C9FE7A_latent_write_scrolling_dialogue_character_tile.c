#include "som_c.h"

/* C9FE7A latent_write_scrolling_dialogue_character_tile   [class B, 49 bytes, 26 instructions]
 * Source: src/rom/latent_write_scrolling_dialogue_character_tile.s
 * Documented in docs/source-recovery-parallel-latent-scroll-flow.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
#define ABSX(off) ((((uint32_t)r->db << 16) + (off) + r->x) & 0xFFFFFF)
#define ABSY(off) ((((uint32_t)r->db << 16) + (off) + r->y) & 0xFFFFFF)
#define ABS(off) ((((uint32_t)r->db << 16) + (off)) & 0xFFFFFF)

static void latent_write_scrolling_dialogue_character_tile(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t character;
    uint16_t cursor;
    if (!hand_require(c, -1, 1, 0)) return;
    BUS16_OK(c, ABS(0xA19B), cursor);
    a_ldx(r, cursor);
    BUS8_PTR(c, ABSY(0x9000), 0x90, character);   /* an unmapped read returns the operand high byte */
    a_lda(r, character);
    i_iny(r);
    a_cmp(r, 0x20);
    if (r->z) {
        a_lda(r, 0x00);
    } else {
        a_cmp(r, 0x2E);
        if (r->z) {
            a_lda(r, 0x1B);
        } else {
            r->c = 1;
            a_sbc(r, 0x40);
        }
    }
    i_rep(r, 0x20);
    a_and(r, 0x00FF);
    i_asla(r);
    r->c = 0;
    a_adc(r, 0x2100);
    BUS16_SET(c, ABSX(0x9400), r->a);
    i_inx(r);
    i_inx(r);
    i_txa(r);
    BUS16_SET(c, ABS(0xA19B), r->a);
    i_sep(r, 0x20);
    r->c = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC9FE7A, SOM_RTS, "hand", latent_write_scrolling_dialogue_character_tile, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 49, 26)
