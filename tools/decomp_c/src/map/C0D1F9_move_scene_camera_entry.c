#include "som_c.h"

/* C0D1F9 move_scene_camera_entry   [class A, 5 bytes, 2 instructions]
 * Source: src/rom/move_scene_camera_entry.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void move_scene_camera_entry(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 0)) return;
    i_sep(r, 0x30);
    TAIL_CALL(c, 0xC0DA81, SOM_RTS); /* move_primary_then_secondary_map_cameras */
}
SOM_REGISTER(0xC0D1F9, SOM_RTS, "hand", move_scene_camera_entry, SOM_STRICT, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 5, 2)
