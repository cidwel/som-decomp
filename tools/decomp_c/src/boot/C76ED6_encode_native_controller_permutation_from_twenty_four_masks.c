#include "som_c.h"

/* C76ED6 encode_native_controller_permutation_from_twenty_four_masks   [class B, 63 bytes, 24 instructions]
 * Source: src/rom/encode_native_controller_permutation_from_twenty_four_masks.s
 * Documented in docs/ui-native-controller-layout.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYV.
 */
static void encode_native_controller_permutation_from_twenty_four_masks(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM16_SET(0xA1A2, 0);
    RAM8(0xA198) = 0x18;
    uint8_t a_hi1 = a_hi;
    uint16_t y1 = y;
    bool carry1 = carry;
    bool overflow1 = overflow;
    for (;;) {
        uint8_t value = RAM8(0xA198);
        uint8_t a_hi2;
        uint16_t y2;
        bool overflow2;
        if (value == 0) {
            a_hi2 = a_hi1;
            y2 = y1;
            overflow2 = overflow1;
        } else {
            uint16_t value2 = RAM16(0xA1A2);
            uint8_t value3 = BUS8(c, 0xC76FE9 + value2);
            RAM8(0xA1CB) = value3;
            RAM16_SET(0xA1A2, (uint16_t)(value2 + 1));
            uint16_t value4 = RAM16(0xA220);
            uint8_t value5 = RAM8(0xA22F + value4);
            uint8_t value6 = RAM8(0xA1CB);
            RAM8(0xA22F + value4) = (value5 & 3) | value6;
            r->a = (a_hi1 << 8) | ((value5 & 3) | value6);
            r->y = y1;
            r->v = overflow1;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            JSL(c, 0x6F05, 0xC76DFC); /* decode_native_controller_layout_and_publish_four_button_labels */
            uint16_t y_ret = r->y;
            bool overflow_ret = r->v;
            r->mf = 1;
            r->xf = 0;
            JSR(c, 0x6F08, 0xC76F15); /* compare_four_native_controller_permutation_entries */
            uint16_t a_all2 = r->a;
            bool carry_ret2 = r->c;
            bool zero_ret2 = r->z;
            RAM8(0xA198)--;
            if (!zero_ret2) {
                a_hi1 = a_all2 >> 8;
                y1 = y_ret;
                carry1 = carry_ret2;
                overflow1 = overflow_ret;
                continue;
            }
            r->mf = 1;
            r->xf = 0;
            JSL(c, 0x6F13, 0xC76F29); /* snapshot_native_controller_permutation_to_two_buffers */
            uint16_t a_all3 = r->a;
            a_hi2 = a_all3 >> 8;
            y2 = y_ret;
            overflow2 = overflow_ret;
        }
        a_hi1 = a_hi2;
        y1 = y2;
        overflow1 = overflow2;
        break;
    }
    r->a = (a_hi1 << 8) | a;
    r->y = y1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC76ED6, SOM_RTL, "gen", encode_native_controller_permutation_from_twenty_four_masks, 0, L_B | L_Y | L_V, 1, 1, 0, 63, 24)
