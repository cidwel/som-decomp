#include "som_c.h"

/* C1FE58 publish_clipped_ui_angular_icon_tiles_and_high_x_bits   [class B, 138 bytes, 72 instructions]
 * Source: src/rom/publish_clipped_ui_angular_icon_tiles_and_high_x_bits.s
 * Documented in docs/ui-native-ui-frame-projection.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: Y.
 */
static void publish_clipped_ui_angular_icon_tiles_and_high_x_bits(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    RAM16_SET(0x0002, a);
    RAM16_SET(0x0002, (uint16_t)(((uint16_t)(((a >> 1) | ((a >= 0x8000) << 0x0F)) + RAM16(0x0002)) ^ 0xFFFF) + 0x81));
    uint16_t value2 = RAM16(0x0000);
    uint8_t a1;
    if ((value2 & 0x80) == 0) {
        RAM16_SET(0x0004, 3);
        a1 = 0xF4;
    } else {
        RAM16_SET(0x0004, 4);
        a1 = 0xF0;
    }
    uint8_t a2 = a1;
    uint8_t a_hi1 = 0xFF;
    uint16_t x1 = (uint16_t)(x + 2);
    uint16_t y1 = y;
    for (;;) {
        uint16_t value3 = RAM16(0x0002);
        RAM16_SET(0x0002, (uint16_t)(((a_hi1 << 8) | a2) + value3));
        uint8_t a_hi3;
        uint16_t y3;
        if ((uint16_t)(((a_hi1 << 8) | a2) + value3) < 0x0100) {
            BUS16_SET(c, 0x0800 + y1, (uint16_t)(((a_hi1 << 8) | a2) + value3) | 0x1000);
            uint16_t value4 = BUS16(c, 0x010000u + x1) /* LDA long $01:0000,X */;
            BUS16_SET(c, 0x0802 + y1, value4);
            a_hi3 = value4 >> 8;
            y3 = (uint16_t)(y1 + 4);
        } else {
            uint8_t a_hi2;
            uint16_t y2;
            if ((uint16_t)(((a_hi1 << 8) | a2) + value3) < 0xFFF8) {
                a_hi2 = (uint16_t)(((a_hi1 << 8) | a2) + value3) >> 8;
                y2 = y1;
            } else {
                uint8_t a5;
                if (((uint8_t)y1 & 0x0C) == 0) {
                    a5 = 1;
                } else {
                    uint8_t a4;
                    if (((uint8_t)y1 & 0x0C) == 4) {
                        a4 = 4;
                    } else {
                        uint8_t a3;
                        if (((uint8_t)y1 & 0x0C) == 8) {
                            a3 = 0x10;
                        } else {
                            a3 = 0x40;
                        }
                        a4 = a3;
                    }
                    a5 = a4;
                }
                BUS8_SET(c, 0x0A00 + (y1 >> 4), a5 | RAM8(0x0A00 + (y1 >> 4)));
                BUS16_SET(c, 0x0800 + y1, ((uint16_t)(((a_hi1 << 8) | a2) + value3) & 0xFF) | 0x1000);
                uint16_t value6 = BUS16(c, 0x010000u + x1) /* LDA long $01:0000,X */;
                BUS16_SET(c, 0x0802 + y1, value6);
                a_hi2 = value6 >> 8;
                y2 = (uint16_t)(y1 + 4);
            }
            a_hi3 = a_hi2;
            y3 = y2;
        }
        RAM16_SET(0x0004, (uint16_t)(RAM16(0x0004) - 1));
        a2 = 8;
        a_hi1 = 0;
        x1 = (uint16_t)(x1 + 2);
        y1 = y3;
        if (!(RAM16(0x0004) != a_hi1)) break;
    }
    r->y = y1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1FE58, SOM_RTS, "hand", publish_clipped_ui_angular_icon_tiles_and_high_x_bits, 0, L_Y, 6, 0, 0, 138, 72)
