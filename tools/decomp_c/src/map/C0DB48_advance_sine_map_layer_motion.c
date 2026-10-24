#include "som_c.h"

/* C0DB48 advance_sine_map_layer_motion   [class C, 146 bytes, 66 instructions]
 * Source: src/rom/advance_sine_map_layer_motion.s
 * Documented in docs/maps.md
 * Entry: any M/X/DB/D (REP #$30 comes first); every absolute address is relative to DB.  Callers read: BXY.
 */
#define ABSX(off) ((((uint32_t)r->db << 16) + (off) + r->x) & 0xFFFFFF)
#define ABS(off) ((((uint32_t)r->db << 16) + (off)) & 0xFFFFFF)
#define ABSY(off) ((((uint32_t)r->db << 16) + (off) + r->y) & 0xFFFFFF)

static void advance_sine_map_layer_motion(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t byte;
    uint16_t word;
    if (!hand_require(c, -1, -1, -1)) return;
    i_rep(r, 0x30);
    BUS16_OK(c, ABSX(0x0A8E), word);
    a_lda(r, word);
    r->c = 0;
    BUS16_OK(c, ABSX(0x0A8A), word);
    a_adc(r, word);
    a_and(r, 0x03FF);
    BUS16_SET(c, ABSX(0x0A8A), r->a);
    dp_wr16(c, 0x00, r->a);                 /* phase of the sine, 10 bits */
    i_sep(r, 0x20);
    dp_wr8(c, 0x01, m_lsr(r, dp_rd8(c, 0x01)));
    if (r->c) {                             /* second half of the period: mirror the table index */
        a_eor(r, 0xFF);
        i_inca(r);
    }
    i_rep(r, 0x20);
    a_and(r, 0x00FF);
    i_asla(r);
    i_tay(r);
    BUS16_OK(c, ABSY(0xFD22), word);
    a_lda(r, word);                         /* sine table */
    i_sep(r, 0x30);
    BUS8_SET(c, ABS(0x211B), r->a);            /* multiplicand: table word, low byte then high byte */
    i_xba(r);
    BUS8_SET(c, ABS(0x211B), r->a);
    BUS8_OK(c, ABSX(0x0A8C), byte);
    a_lda(r, byte);
    BUS8_SET(c, ABS(0x211C), r->a);            /* multiplier: layer amplitude */
    a_lda(r, BUS8(c, ABS(0x2134)));            /* product, low byte */
    r->c = 0;
    BUS8_OK(c, ABSX(0x0A86), byte);
    a_adc(r, byte);                         /* accumulate the fraction */
    BUS8_SET(c, ABSX(0x0A86), r->a);
    a_lda(r, BUS8(c, ABS(0x2135)));            /* product, middle byte */
    a_ldy(r, BUS8(c, ABS(0x2136)));            /* product, high byte */
    a_adc(r, 0x00);
    if (r->z) RETURN_RTS(c);
    a_cmp(r, 0x09);
    if (r->c) a_lda(r, 0x08);
    dp_wr8(c, 0x01, m_lsr(r, dp_rd8(c, 0x01)));
    if (r->c) a_ora(r, 0x80);
    /* dispatch_automatic_map_camera_motion: the layer index (X) selects the camera axis */
    a_cpx(r, 0x00);
    if (r->z) { dp_wr8(c, 0x84, r->a); TAIL_CALL(c, 0xC0DBDA, SOM_RTS); }   /* move_primary_camera_horizontal */
    a_cpx(r, 0x10);
    if (r->z) { dp_wr8(c, 0x86, r->a); TAIL_CALL(c, 0xC0DC18, SOM_RTS); }   /* move_primary_camera_vertical */
    a_cpx(r, 0x20);
    if (r->z) { dp_wr8(c, 0x84, r->a); TAIL_CALL(c, 0xC0DC56, SOM_RTS); }   /* move_secondary_camera_horizontal */
    dp_wr8(c, 0x86, r->a);
    TAIL_CALL(c, 0xC0DC99, SOM_RTS);                                         /* move_secondary_camera_vertical */
}
SOM_REGISTER(0xC0DB48, SOM_RTS, "hand", advance_sine_map_layer_motion, 0, L_B | L_X | L_Y, 1, 1, 0, 146, 66)
