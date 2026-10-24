#include "som_c.h"

/* C09881 publish_scene_tile_row_with_horizontal_page_wrap   [class D, 99 bytes, 42 instructions]
 * Source: src/rom/publish_scene_tile_row_with_horizontal_page_wrap.s
 * Documented in docs/ui-native-scene-tile-rows.md
 * Entry: M=16 bit X=8 bit DB=$00 D=$0000.  Callers read: AV.
 */
static void publish_scene_tile_row_with_horizontal_page_wrap(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    if (RAM8(0x002E) & 0x80) {
        RAM8(0x002E) = 0;
        BUS8_SET(c, 0x002115, 0);
        BUS16_SET(c, 0x004370, 0x1800);
        BUS8_SET(c, 0x004374, 0x7F);
        uint16_t value2 = RAM16(0x0074);
        BUS16_SET(c, 0x004372, value2);
        uint16_t value3 = RAM16(0x0076);
        BUS16_SET(c, 0x002116, value3);
        BUS16_SET(c, 0x004375, ((value3 & 0x7F) ^ 0x7F) + 1);
        BUS8_SET(c, 0x00420B, 0x80);
        if (((value3 & 0x7F) ^ 0x7F) + 1 != 0x80) {
            BUS16_SET(c, 0x004375, (((value3 & 0x7F) ^ 0x7F) + 1 ^ 0x7F) + 1);
            BUS16_SET(c, 0x002116, value3 & 0x3F80);
            uint8_t a1;
            if ((value2 & 0x01FF) < 0x0180) {
                a1 = (uint8_t)(value2 & 0x01FF);
            } else {
                BUS16_SET(c, 0x004372, value2 & 0xFE00);
                a1 = (uint8_t)(value2 & 0xFE00);
            }
            BUS8_SET(c, 0x00420B, 0x80);
            r->a = (a >> 8 << 8) | a1;
            RETURN_RTS(c);
        }
        r->a = ((value3 & 0x7F) ^ 0x7F) + 1;
        RETURN_RTS(c);
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC09881, SOM_RTS, "gen", publish_scene_tile_row_with_horizontal_page_wrap, 0, L_A | L_V, 1, 0, 1, 99, 42)
