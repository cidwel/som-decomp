#include "som_c.h"

/* C0882B upload_scene_oam_and_attribute_frame_buffers   [class D, 164 bytes, 63 instructions]
 * Source: src/rom/upload_scene_oam_and_attribute_frame_buffers.s
 * Documented in docs/ui-native-scene-interrupts.md
 * Entry: M=16 bit X=8 bit DB=$00 D=$0000.  Callers read: ABYCV.
 */
static void upload_scene_oam_and_attribute_frame_buffers(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    BUS16_SET(c, 0x002102, 0);
    BUS16_SET(c, 0x004372, 0x0800);
    BUS16_SET(c, 0x004370, 0x0400);
    BUS8_SET(c, 0x004374, 0);
    BUS16_SET(c, 0x004375, 0x0220);
    BUS8_SET(c, 0x00420B, 0x80);
    BUS8_SET(c, 0x002115, 0x80);
    BUS16_SET(c, 0x004370, 0x1900);
    BUS16_SET(c, 0x004372, RAM16(0x00A2));
    BUS8_SET(c, 0x004374, 0x7E);
    BUS16_SET(c, 0x002116, RAM16(0x00A4));
    BUS16_SET(c, 0x004375, 0x80);
    BUS8_SET(c, 0x00420B, 0x80);
    if ((RAM16(0x00E3) & 6) != 0) {
        BUS16_SET(c, 0x004372, RAM16(0x0092));
        BUS16_SET(c, 0x002116, RAM16(0x0094));
        BUS16_SET(c, 0x004375, 0x40);
        BUS8_SET(c, 0x00420B, 0x80);
    }
    BUS8_SET(c, 0x002115, 1);
    BUS8_SET(c, 0x004374, 0xC6);
    BUS16_SET(c, 0x004370, 0x1800);
    uint16_t value6 = RAM16(0x00B4);
    uint8_t a_hi1;
    if (value6 == 0) {
        a_hi1 = value6 >> 8;
    } else {
        BUS16_SET(c, 0x004372, value6);
        BUS16_SET(c, 0x002116, RAM16(0x00B6));
        BUS16_SET(c, 0x004375, 0x10);
        BUS8_SET(c, 0x00420B, 0x80);
        a_hi1 = 0;
    }
    uint16_t value8 = RAM16(0x00B8);
    uint8_t a1;
    uint8_t a_hi2;
    if (value8 == 0) {
        a1 = (uint8_t)value8;
        a_hi2 = value8 >> 8;
    } else {
        BUS16_SET(c, 0x004372, value8);
        BUS16_SET(c, 0x002116, RAM16(0x00BA));
        BUS16_SET(c, 0x004375, 0x10);
        BUS8_SET(c, 0x00420B, 0x80);
        a1 = 0x10;
        a_hi2 = 0;
    }
    r->a = (a_hi2 << 8) | a1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0882B, SOM_RTS, "gen", upload_scene_oam_and_attribute_frame_buffers, 0, L_A | L_B | L_Y | L_C | L_V, 1, 0, 1, 164, 63)
