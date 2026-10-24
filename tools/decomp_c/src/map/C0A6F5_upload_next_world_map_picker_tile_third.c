#include "som_c.h"

/* C0A6F5 upload_next_world_map_picker_tile_third   [class D, 62 bytes, 26 instructions]
 * Source: src/rom/upload_next_world_map_picker_tile_third.s
 * Documented in docs/ui-native-world-map-picker-scene.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: CV.
 */
static void upload_next_world_map_picker_tile_third(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t y = r->y;
    BUS8_SET(c, 0x002115, 0);
    BUS8_SET(c, 0x004374, 0x7F);
    BUS16_SET(c, 0x004370, 0x1800);
    BUS16_SET(c, 0x004375, 0x1556);
    uint8_t a2;
    uint8_t a_hi2;
    if ((uint8_t)(y - 1) != 0) {
        uint8_t a1;
        uint8_t a_hi1;
        if ((uint8_t)(y - 2) != 0) {
            BUS8_SET(c, 0x00420C, 0);
            RAM8(0x000D) = 1;
            a1 = 0xAA;
            a_hi1 = 0x2A;
        } else {
            a1 = 0x55;
            a_hi1 = 0x15;
        }
        a2 = a1;
        a_hi2 = a_hi1;
    } else {
        a2 = 0;
        a_hi2 = 0;
    }
    BUS16_SET(c, 0x004372, (a_hi2 << 8) | a2);
    BUS16_SET(c, 0x002116, (a_hi2 << 8) | a2);
    BUS8_SET(c, 0x00420B, 0x80);
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0A6F5, SOM_RTS, "gen", upload_next_world_map_picker_tile_third, 0, L_C | L_V, 1, 1, 1, 62, 26)
