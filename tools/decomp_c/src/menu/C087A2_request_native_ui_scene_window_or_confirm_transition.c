#include "som_c.h"

/* C087A2 request_native_ui_scene_window_or_confirm_transition   [class A, 34 bytes, 18 instructions]
 * Source: src/rom/request_native_ui_scene_window_or_confirm_transition.s
 * Documented in docs/ui-native-world-map-picker-exit.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void request_native_ui_scene_window_or_confirm_transition(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint8_t value = RAM8(0x00F2);
    if (!(value & 0x80)) {
        if ((value & 3) == 0) {
            RAM8(0x00F2) = value | 1;
            RAM8(0x0051) = 0x0E;
            r->v = value & 0x40;
            RETURN_RTS(c);
        }
        RAM8(0x00CC) |= 0x10;
        r->v = value & 0x40;
        RETURN_RTS(c);
    }
    uint8_t value3 = RAM8(0x00F8);
    if (value3 < 0x20) {
        r->c = value3 >= 0x20;
        r->v = value & 0x40;
        RETURN_RTS(c);
    }
    if ((value & 3) == 0) {
        RAM8(0x00F2) = value | 1;
        RAM8(0x0051) = 0x0E;
        r->c = value3 >= 0x20;
        r->v = value & 0x40;
        RETURN_RTS(c);
    }
    RAM8(0x00CC) |= 0x10;
    r->c = value3 >= 0x20;
    r->v = value & 0x40;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC087A2, SOM_RTS, "gen", request_native_ui_scene_window_or_confirm_transition, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 34, 18)
