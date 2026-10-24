#include "som_c.h"

/* C76E36 publish_four_native_controller_button_label_tile_strips   [class B, 85 bytes, 42 instructions]
 * Source: src/rom/publish_four_native_controller_button_label_tile_strips.s
 * Documented in docs/ui-native-controller-layout.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCZNV.
 */
static void publish_four_native_controller_button_label_tile_strips(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM16_SET(0xA171, 0);
    uint8_t a_hi1 = 0;
    uint16_t x1 = x;
    uint16_t y1 = y;
    bool carry1 = carry;
    bool zero1 = 1;
    bool negative1 = 0;
    bool overflow1 = overflow;
    for (;;) {
        uint16_t value = RAM16(0xA171);
        uint16_t value2 = RAM16(0xA1E0 + (uint16_t)(value << 2));
        uint16_t value4 = BUS16(c, 0xC76FE1 + ((RAM16(0x9C00 + value) & 0xFF) << 1));
        RAM16_SET(0xA173, RAM16(0x9000 + (uint16_t)(value2 + 0x42)) & 0x1C00);
        uint16_t value6 = RAM16(0xA173);
        uint8_t a1 = (uint8_t)(value4 | value6);
        uint8_t a_hi2 = (value4 | value6) >> 8;
        uint16_t x2 = (uint16_t)(value2 + 0x42);
        uint16_t y2 = 7;
        for (;;) {
            RAM16_SET(0x9000 + x2, (a_hi2 << 8) | a1);
            RAM16_SET(0x9040 + x2, (uint16_t)(((a_hi2 << 8) | a1) + 2));
            uint8_t a1_next = (uint8_t)(((a_hi2 << 8) | a1) + 4);
            uint8_t a_hi2_next = (uint16_t)(((a_hi2 << 8) | a1) + 4) >> 8;
            uint16_t x2_next = (uint16_t)(x2 + 2);
            uint16_t y2_next = (uint16_t)(y2 - 1);
            a1 = a1_next;
            a_hi2 = a_hi2_next;
            x2 = x2_next;
            y2 = y2_next;
            if (!(y2 != 0)) break;
        }
        RAM16_SET(0xA171, (uint16_t)(RAM16(0xA171) + 1));
        uint16_t value7 = RAM16(0xA171);
        a_hi1 = 0;
        x1 = x2;
        y1 = y2;
        carry1 = value7 <= 4;
        zero1 = value7 == 4;
        negative1 = (uint16_t)(4 - value7) & 0x8000;
        overflow1 = ((value2 ^ (uint16_t)(value2 + 0x42)) & ((uint16_t)(value2 + 0x42) ^ 0x42) & 0x8000) != 0;
        if (!(value7 != 4)) break;
    }
    r->a = (a_hi1 << 8) | a;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC76E36, SOM_RTS, "gen", publish_four_native_controller_button_label_tile_strips, 0, L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 1, 0, 85, 42)
