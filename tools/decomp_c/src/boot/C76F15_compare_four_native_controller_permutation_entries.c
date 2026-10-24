#include "som_c.h"

/* C76F15 compare_four_native_controller_permutation_entries   [class A, 20 bytes, 11 instructions]
 * Source: src/rom/compare_four_native_controller_permutation_entries.s
 * Documented in docs/ui-native-controller-layout.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYCZNV.
 */
static void compare_four_native_controller_permutation_entries(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a1 = 4;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 0;
    bool carry1 = carry;
    bool zero1 = 1;
    bool negative1 = 0;
    for (;;) {
        uint8_t value = RAM8(0x9C00 + x1);
        uint8_t value2 = RAM8(0x9C04 + x1);
        uint8_t a_hi2;
        bool zero2;
        bool negative2;
        if (value != value2) {
            a_hi2 = a1;
            zero2 = value == value2;
            negative2 = (uint8_t)(value - value2) & 0x80;
        } else {
            if ((uint8_t)(a1 - 1) != 0) {
                uint8_t a1_next = (uint8_t)(a1 - 1);
                uint8_t a_hi1_next = value;
                uint16_t x1_next = (uint16_t)(x1 + 1);
                bool carry1_next = value >= value2;
                bool zero1_next = (uint8_t)(a1 - 1) == 0;
                bool negative1_next = (uint8_t)(a1 - 1) & 0x80;
                a1 = a1_next;
                a_hi1 = a_hi1_next;
                x1 = x1_next;
                carry1 = carry1_next;
                zero1 = zero1_next;
                negative1 = negative1_next;
                continue;
            }
            a_hi2 = value;
            zero2 = (uint8_t)(a1 - 1) == 0;
            negative2 = (uint8_t)(a1 - 1) & 0x80;
        }
        a_hi1 = a_hi2;
        carry1 = value >= value2;
        zero1 = zero2;
        negative1 = negative2;
        break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->y = y;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC76F15, SOM_RTS, "gen", compare_four_native_controller_permutation_entries, 0, L_B | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 20, 11)
