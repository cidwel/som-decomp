#include "som_c.h"

/* C6459C await_next_mode_seven_scene_vblank   [class D, 13 bytes, 6 instructions]
 * Source: src/rom/await_next_mode_seven_scene_vblank.s
 * Documented in docs/ui-native-mode7-transition.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BY.
 */
static void await_next_mode_seven_scene_vblank(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    for (;;) {
        uint8_t value = BUS8(c, 0x004212);
        if (!((value & 0x80) != 0)) break;
    }
    for (;;) {
        uint8_t value2 = BUS8(c, 0x004212);
        if (!((value2 & 0x80) == 0)) break;
    }
    r->a = (a_hi << 8) | 0x80;
    r->y = y;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC6459C, SOM_RTS, "gen", await_next_mode_seven_scene_vblank, 0, L_B | L_Y, 1, 1, 0, 13, 6)
