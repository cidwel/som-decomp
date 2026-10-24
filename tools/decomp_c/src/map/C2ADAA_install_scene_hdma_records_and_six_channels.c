#include "som_c.h"

/* C2ADAA install_scene_hdma_records_and_six_channels   [class D, 68 bytes, 28 instructions]
 * Source: src/rom/install_scene_hdma_records_and_six_channels.s
 * Documented in docs/ui-native-scene-setup.md
 * Entry: M=16 bit X=8 bit DB=$00 D=$0000.  Callers read: YCV.
 */
static void install_scene_hdma_records_and_six_channels(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint8_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a_hi1 = a >> 8;
    uint8_t x1 = 0x26;
    for (;;) {
        uint16_t value = BUS16(c, 0x02AD52 + x1);
        RAM16_SET(0x0FD8 + x1, value);
        a_hi1 = value >> 8;
        x1 = (uint8_t)(x1 - 2);
        if (!(!(x1 & 0x80))) break;
    }
    uint8_t a_hi2 = a_hi1;
    uint8_t x2 = 6;
    for (;;) {
        uint16_t value2 = BUS16(c, 0x02AD7A + x2);
        BUS16_SET(c, 0x024300 + x2, value2);
        uint16_t value3 = BUS16(c, 0x02AD82 + x2);
        BUS16_SET(c, 0x024310 + x2, value3);
        uint16_t value4 = BUS16(c, 0x02AD8A + x2);
        BUS16_SET(c, 0x024320 + x2, value4);
        uint16_t value5 = BUS16(c, 0x02AD92 + x2);
        BUS16_SET(c, 0x024330 + x2, value5);
        uint16_t value6 = BUS16(c, 0x02AD9A + x2);
        BUS16_SET(c, 0x024340 + x2, value6);
        uint16_t value7 = BUS16(c, 0x02ADA2 + x2);
        BUS16_SET(c, 0x024350 + x2, value7);
        a_hi2 = value7 >> 8;
        x2 = (uint8_t)(x2 - 2);
        if (!(!(x2 & 0x80))) break;
    }
    r->y = y;
    r->c = carry;
    r->v = overflow;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2ADAA, SOM_RTL, "gen", install_scene_hdma_records_and_six_channels, 0, L_Y | L_C | L_V, 2, 0, 1, 68, 28)
