#include "som_c.h"

/* C24437 schedule_two_boss_palette_transitions_if_variant   [class B, 48 bytes, 19 instructions]
 * Source: src/rom/schedule_two_boss_palette_transitions_if_variant.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void schedule_two_boss_palette_transitions_if_variant(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x0042 + x);
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool zero1;
    bool negative1;
    bool overflow1;
    if (value == 0) {
        a1 = (uint8_t)value;
        a_hi1 = value >> 8;
        x1 = x;
        y1 = y;
        carry1 = carry;
        zero1 = value == 0;
        negative1 = value & 0x8000;
        overflow1 = overflow;
    } else {
        RAM8(0x033F + 0x0D) = 0x1C;
        RAM8(0x033F + 0x0E) = 0x1D;
        r->a = 0x10;
        r->x = 0x1C;
        r->y = 0x0D;
        JSR(c, 0x4459, 0xC2272D); /* allocate_boss_palette_transition_object */
        r->a = 0x10;
        r->x = 0x1D;
        r->y = 0x0E;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x4465, 0xC2272D); /* allocate_boss_palette_transition_object */
        uint16_t a_all2 = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret2 = r->y;
        bool carry_ret2 = r->c;
        bool zero_ret2 = r->z;
        bool negative_ret2 = r->n;
        bool overflow_ret2 = r->v;
        a1 = (uint8_t)a_all2;
        a_hi1 = a_all2 >> 8;
        x1 = x_ret2;
        y1 = y_ret2;
        carry1 = carry_ret2;
        zero1 = zero_ret2;
        negative1 = negative_ret2;
        overflow1 = overflow_ret2;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC24437, SOM_RTS, "gen", schedule_two_boss_palette_transitions_if_variant, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 48, 19)
