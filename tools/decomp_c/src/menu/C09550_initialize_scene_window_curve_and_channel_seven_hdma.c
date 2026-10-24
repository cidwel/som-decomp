#include "som_c.h"

/* C09550 initialize_scene_window_curve_and_channel_seven_hdma   [class D, 68 bytes, 32 instructions]
 * Source: src/rom/initialize_scene_window_curve_and_channel_seven_hdma.s
 * Documented in docs/ui-native-scene-setup.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BCV.
 */
static void initialize_scene_window_curve_and_channel_seven_hdma(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const bool overflow = r->v;
    RAM8(0x002D) = 0;
    BUS8_SET(c, 0x002123, 0);
    uint8_t a_hi1 = a_hi;
    uint8_t x1 = 0;
    uint8_t y1 = 0;
    bool overflow1 = overflow;
    for (;;) {
        uint8_t value = BUS8(c, 0x0096E2 + y1);
        RAM8(0x0000) = value;
        RAM8(0x1833 + x1) = value | 0x80;
        uint8_t value2 = RAM8(0x0000);
        RAM8(0x1832 + x1) = (uint8_t)(0x80 - value2);
        x1 = (uint8_t)(x1 + 2);
        y1 = (uint8_t)(y1 + 1);
        overflow1 = ((value2 ^ 0x80) & ((uint8_t)(0x80 - value2) ^ 0x80) & 0x80) != 0;
        if (!(x1 < 0x20)) break;
    }
    RAM8(0x1830) = 1;
    RAM8(0x1850) = 1;
    RAM8(0x1831) = 0;
    RAM8(0x1851) = 0;
    uint8_t a_hi2 = a_hi1;
    uint8_t x2 = 0;
    bool carry1 = 0;
    for (;;) {
        uint8_t value3 = BUS8(c, 0x009594 + x2);
        BUS8_SET(c, 0x004370 + x2, value3);
        uint8_t x2_next = (uint8_t)(x2 + 1);
        bool carry1_next = (uint8_t)(x2 + 1) >= 8;
        x2 = x2_next;
        carry1 = carry1_next;
        if (!(x2 < 8)) break;
    }
    r->a = (a_hi2 << 8) | a;
    r->c = carry1;
    r->v = overflow1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC09550, SOM_RTS, "gen", initialize_scene_window_curve_and_channel_seven_hdma, 0, L_B | L_C | L_V, 1, 1, 1, 68, 32)
