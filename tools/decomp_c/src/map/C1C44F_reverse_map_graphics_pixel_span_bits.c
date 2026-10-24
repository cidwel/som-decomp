#include "som_c.h"

/* C1C44F reverse_map_graphics_pixel_span_bits   [class B, 55 bytes, 36 instructions]
 * Source: src/rom/reverse_map_graphics_pixel_span_bits.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=$7F D=$0000.  Callers read: ABY.
 */
static void reverse_map_graphics_pixel_span_bits(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint16_t a = r->a;                           /* REP #$20: the whole accumulator */
    uint16_t word = dp_rd16(c, 0x00);
    bool carry = r->c;
    for (int bit = 0; bit < 16; bit++) {
        carry = a & 1;                           /* LSR */
        a >>= 1;
        const bool out = word >> 15;             /* ROL $00 */
        word = (uint16_t)((word << 1) | carry);
        carry = out;
    }
    dp_wr16(c, 0x00, word);
    r->a = word;                                 /* LDA $00 */
    hand_nz16(r, word);
    r->c = carry;
    r->mf = true;                                /* SEP #$20 */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1C44F, SOM_RTS, "hand", reverse_map_graphics_pixel_span_bits, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 0, 1, 1, 55, 36)
