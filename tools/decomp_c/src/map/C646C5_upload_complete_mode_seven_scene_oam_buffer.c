#include "som_c.h"

/* C646C5 upload_complete_mode_seven_scene_oam_buffer   [class D, 37 bytes, 14 instructions]
 * Source: src/rom/upload_complete_mode_seven_scene_oam_buffer.s
 * Documented in docs/ui-native-mode7-transition.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BY.
 */
static void upload_complete_mode_seven_scene_oam_buffer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    BUS8_SET(c, 0x002102, 0);
    BUS8_SET(c, 0x002103, 0);
    BUS8_SET(c, 0x004300, 0);
    BUS8_SET(c, 0x004301, 4);
    BUS16_SET(c, 0x004302, 0x15E0);
    BUS8_SET(c, 0x004304, 0);
    BUS16_SET(c, 0x004305, 0x0220);
    BUS8_SET(c, 0x00420B, 1);
    RETURN_RTL(c);
}
SOM_REGISTER(0xC646C5, SOM_RTL, "gen", upload_complete_mode_seven_scene_oam_buffer, 0, L_B | L_Y, 1, 1, 0, 37, 14)
