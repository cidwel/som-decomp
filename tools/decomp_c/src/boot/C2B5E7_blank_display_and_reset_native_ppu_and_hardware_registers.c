#include "som_c.h"

/* C2B5E7 blank_display_and_reset_native_ppu_and_hardware_registers   [class D, 126 bytes, 51 instructions]
 * Source: src/rom/blank_display_and_reset_native_ppu_and_hardware_registers.s
 * Documented in docs/ui-native-ui-to-map-reset.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: XYCV.
 */
static void blank_display_and_reset_native_ppu_and_hardware_registers(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool overflow = r->v;
    BUS8_SET(c, 0x002100, 0x8F);
    BUS8_SET(c, 0x004200, 0);
    BUS8_SET(c, 0x002101, 0);
    BUS8_SET(c, 0x002102, 0);
    BUS8_SET(c, 0x002103, 0);
    uint8_t x1 = 0;
    for (;;) {
        BUS8_SET(c, 0x002105 + x1, 0);
        x1 = (uint8_t)(x1 + 1);
        if (!(x1 != 8)) break;
    }
    uint8_t x2 = 0;
    for (;;) {
        BUS8_SET(c, 0x00210D + x2, 0);
        BUS8_SET(c, 0x00210D + x2, 0);
        x2 = (uint8_t)(x2 + 1);
        if (!(x2 < 8)) break;
    }
    BUS8_SET(c, 0x002115, 0x80);
    BUS8_SET(c, 0x002116, 0x80);
    BUS8_SET(c, 0x002117, 0x80);
    BUS8_SET(c, 0x002121, 0);
    uint8_t x3 = 0;
    bool carry1 = 0;
    for (;;) {
        BUS8_SET(c, 0x002123 + x3, 0);
        BUS8_SET(c, 0x004202 + x3, 0);
        uint8_t x3_next = (uint8_t)(x3 + 1);
        bool carry1_next = (uint8_t)(x3 + 1) >= 0x0C;
        x3 = x3_next;
        carry1 = carry1_next;
        if (!(x3 < 0x0C)) break;
    }
    BUS8_SET(c, 0x002131, 0);
    BUS8_SET(c, 0x002133, 0);
    BUS8_SET(c, 0x00211C, 0);
    BUS8_SET(c, 0x00211C, 0);
    BUS8_SET(c, 0x00211D, 0);
    BUS8_SET(c, 0x00211D, 0);
    BUS8_SET(c, 0x00211F, 0);
    BUS8_SET(c, 0x00211F, 0);
    BUS8_SET(c, 0x00211B, 1);
    BUS8_SET(c, 0x00211B, 0);
    BUS8_SET(c, 0x00211E, 1);
    BUS8_SET(c, 0x00211E, 0);
    BUS8_SET(c, 0x002130, 0x30);
    BUS8_SET(c, 0x002132, 0xE0);
    BUS8_SET(c, 0x004201, 0xFF);
    r->x = 0;
    r->y = (uint8_t)y;
    r->c = carry1;
    r->v = overflow;
    r->xf = 1;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2B5E7, SOM_RTL, "gen", blank_display_and_reset_native_ppu_and_hardware_registers, 0, L_X | L_Y | L_C | L_V, 1, 1, 0, 126, 51)
