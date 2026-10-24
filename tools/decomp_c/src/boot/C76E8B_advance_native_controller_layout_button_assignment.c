#include "som_c.h"

/* C76E8B advance_native_controller_layout_button_assignment   [class B, 75 bytes, 34 instructions]
 * Source: src/rom/advance_native_controller_layout_button_assignment.s
 * Documented in docs/ui-native-controller-layout.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void advance_native_controller_layout_button_assignment(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    RAM8(0xA175) = 1;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 4;
    for (;;) {
        RAM8(0x9C03 + x1) = RAM8(0x9C07 + x1);
        x1 = (uint16_t)(x1 - 1);
        if (!(x1 != 0)) break;
    }
    uint8_t value2 = RAM8(0xA211);
    uint8_t value3 = RAM8(0x9C00 + value2);
    uint8_t value4 = RAM8(0xA175);
    RAM8(0x9C00 + value2) = (uint8_t)(value3 + value4) & 3;
    uint16_t x2 = 0xFFFF;
    bool carry1 = value3 + value4 > 0xFF;
    for (;;) {
        uint8_t value5 = RAM8(0x9C04 + (uint16_t)(x2 + 1));
        x2 = (uint16_t)(x2 + 1);
        carry1 = ((uint8_t)(value3 + value4) & 3) >= value5;
        if (!(((uint8_t)(value3 + value4) & 3) != value5)) break;
    }
    RAM8(0x9C04 + x2) = RAM8(0x9C04 + value2);
    RAM8(0x9C04 + value2) = (uint8_t)(value3 + value4) & 3;
    JSR(c, 0x6ECA, 0xC76E36); /* publish_four_native_controller_button_label_tile_strips */
    RAM8(0xA20A) |= 2;
    RAM8(0xA212) |= 0x80;
    SET_A8(r, 0x80);
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC76E8B, SOM_RTL, "gen", advance_native_controller_layout_button_assignment, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 75, 34)
