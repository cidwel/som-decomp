#include "som_c.h"

/* C76F39 decode_six_native_controller_pair_swap_bits   [class A, 48 bytes, 27 instructions]
 * Source: src/rom/decode_six_native_controller_pair_swap_bits.s
 * Documented in docs/ui-native-controller-layout.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYCZNV.
 */
static void decode_six_native_controller_pair_swap_bits(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a1 = a;
    uint8_t a_hi1 = 0;
    uint16_t y1 = 0;
    bool carry1 = carry;
    bool zero1 = a == 0;
    bool negative1 = a & 0x80;
    for (;;) {
        if (a1 & 0x01) {
            uint8_t value = BUS8(c, 0xC76FD5 + ((a_hi1 << 8) | (uint8_t)((uint8_t)y1 << 1)));
            uint8_t value2 = BUS8(c, 0xC76FD6 + ((a_hi1 << 8) | (uint8_t)((uint8_t)y1 << 1)));
            uint8_t value3 = RAM8(0x9C00 + ((a_hi1 << 8) | value2));
            RAM8(0x9C00 + ((a_hi1 << 8) | value2)) = RAM8(0x9C00 + ((a_hi1 << 8) | value));
            RAM8(0x9C00 + ((a_hi1 << 8) | value)) = value3;
        }
        uint8_t a1_next = a1 >> 1;
        uint16_t y1_next = (uint16_t)(y1 + 1);
        bool carry1_next = (uint16_t)(y1 + 1) >= 7;
        bool zero1_next = (uint16_t)(y1 + 1) == 7;
        bool negative1_next = (uint16_t)((uint16_t)(y1 + 1) - 7) & 0x8000;
        a1 = a1_next;
        y1 = y1_next;
        carry1 = carry1_next;
        zero1 = zero1_next;
        negative1 = negative1_next;
        if (!(y1 != 7)) break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC76F39, SOM_RTS, "gen", decode_six_native_controller_pair_swap_bits, 0, L_B | L_Y | L_C | L_Z | L_N | L_V, 4, 1, 0, 48, 27)
