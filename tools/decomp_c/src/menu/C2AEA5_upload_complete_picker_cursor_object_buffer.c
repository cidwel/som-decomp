#include "som_c.h"

/* C2AEA5 upload_complete_picker_cursor_object_buffer   [class D, 39 bytes, 15 instructions]
 * Source: src/rom/upload_complete_picker_cursor_object_buffer.s
 * Documented in docs/ui-native-world-map-picker-scene.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: XYCV.
 */
static void upload_complete_picker_cursor_object_buffer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    BUS16_SET(c, 0x002102, 0);
    BUS16_SET(c, 0x004372, 0x0800);
    BUS16_SET(c, 0x004370, 0x0400);
    BUS16_SET(c, 0x004375, 0x0220);
    BUS8_SET(c, 0x004374, 0);
    BUS8_SET(c, 0x00420B, 0x80);
    r->x = 0x80;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2AEA5, SOM_RTS, "gen", upload_complete_picker_cursor_object_buffer, 0, L_X | L_Y | L_C | L_V, 1, 1, 1, 39, 15)
