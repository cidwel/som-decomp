#include "som_c.h"

/* C76DFC decode_native_controller_layout_and_publish_four_button_labels   [class A, 27 bytes, 13 instructions]
 * Source: src/rom/decode_native_controller_layout_and_publish_four_button_labels.s
 * Documented in docs/ui-native-controller-layout.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYCZNV.
 */
static void decode_native_controller_layout_and_publish_four_button_labels(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const bool overflow = r->v;
    uint8_t a1 = 3;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 4;
    for (;;) {
        RAM8(0x9BFF + x1) = a1;
        a1 = (uint8_t)(a1 - 1);
        x1 = (uint16_t)(x1 - 1);
        if (!(x1 != 0)) break;
    }
    r->a = (a_hi1 << 8) | (RAM8(0xA22F + RAM16(0xA220)) >> 2);
    r->v = overflow;
    JSR(c, 0x6E12, 0xC76F39); /* decode_six_native_controller_pair_swap_bits */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x6E15, 0xC76E36); /* publish_four_native_controller_button_label_tile_strips */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC76DFC, SOM_RTL, "gen", decode_native_controller_layout_and_publish_four_button_labels, 0, L_B | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 27, 13)
