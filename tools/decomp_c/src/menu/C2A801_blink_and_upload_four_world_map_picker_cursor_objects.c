#include "som_c.h"

/* C2A801 blink_and_upload_four_world_map_picker_cursor_objects   [class D, 81 bytes, 29 instructions]
 * Source: src/rom/blink_and_upload_four_world_map_picker_cursor_objects.s
 * Documented in docs/ui-native-world-map-picker-scene.md
 * Entry: M=16 bit X=8 bit DB=$00 D=$0000.  Callers read: CV.
 */
static void blink_and_upload_four_world_map_picker_cursor_objects(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    uint8_t a1;
    uint8_t a_hi1;
    if ((a & 0x10) == 0) {
        RAM16_SET(0x0800, 0x6070);
        RAM16_SET(0x0804, 0x6080);
        RAM16_SET(0x0808, 0x7070);
        a1 = 0x80;
        a_hi1 = 0x70;
    } else {
        RAM16_SET(0x0800, 0xE0FF);
        RAM16_SET(0x0804, 0xE0FF);
        RAM16_SET(0x0808, 0xE0FF);
        RAM16_SET(0x0810, 0xE0FF);
        a1 = 0xFF;
        a_hi1 = 0xE0;
    }
    RAM16_SET(0x080C, (a_hi1 << 8) | a1);
    BUS16_SET(c, 0x002102, 0);
    BUS16_SET(c, 0x004372, 0x0800);
    BUS16_SET(c, 0x004370, 0x0400);
    BUS8_SET(c, 0x004374, 0);
    BUS16_SET(c, 0x004375, 0x10);
    BUS8_SET(c, 0x00420B, 0x80);
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2A801, SOM_RTL, "gen", blink_and_upload_four_world_map_picker_cursor_objects, 0, L_C | L_V, 1, 0, 1, 81, 29)
