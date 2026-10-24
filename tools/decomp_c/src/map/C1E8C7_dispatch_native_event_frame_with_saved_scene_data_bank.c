#include "som_c.h"

/* C1E8C7 dispatch_native_event_frame_with_saved_scene_data_bank   [class A, 12 bytes, 8 instructions]
 * Source: src/rom/dispatch_native_event_frame_with_saved_scene_data_bank.s
 * Documented in docs/map-main-frame-menu-bridge.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void dispatch_native_event_frame_with_saved_scene_data_bank(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    r->a = (a_hi << 8) | 0x7E;
    r->db = 0x7E;
    r->sp -= 1;
    JSR(c, 0xE8D0, 0xC1E8D3); /* dispatch_native_event_opcode_or_wait_state */
    r->sp += 1;
    r->z = 1;
    r->n = 0;
    r->db = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1E8C7, SOM_RTL, "gen", dispatch_native_event_frame_with_saved_scene_data_bank, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 1, 0, 12, 8)
