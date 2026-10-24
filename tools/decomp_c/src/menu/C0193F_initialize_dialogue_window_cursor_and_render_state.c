#include "som_c.h"

/* C0193F initialize_dialogue_window_cursor_and_render_state   [class B, 90 bytes, 33 instructions]
 * Source: src/rom/initialize_dialogue_window_cursor_and_render_state.s
 * Documented in docs/event-dialogue-number-window.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void initialize_dialogue_window_cursor_and_render_state(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint8_t value = RAM8(0x1D05);
    uint16_t x2;
    if (value != 7) {
        x2 = 0x4910;
    } else {
        uint8_t value2 = RAM8(0xA162);
        uint16_t x1;
        if (value2 == 1) {
            x1 = 0x65A0;
        } else {
            x1 = 0x6590;
        }
        x2 = x1;
    }
    RAM16_SET(0xA18C, x2);
    uint8_t value3 = RAM8(0xA162);
    uint16_t x3;
    if (value3 != 2) {
        x3 = 0x0122;
    } else {
        x3 = 0x01E0;
    }
    RAM16_SET(0xA17E, x3);
    RAM8(0xA17D) = RAM8(0xA197);
    RAM8(0xA17C) = RAM8(0xA196);
    RAM8(0xA180) = 0;
    RAM8(0xA15D) = 0;
    RAM8(0xA181) = 0;
    RAM8(0xA186) = 0;
    RAM16_SET(0xA189, 0x9000);
    RAM8(0xA193) = RAM8(0xA16C);
    RAM8(0xA15B) = 0x68;
    RAM8(0xA19F) = 0x48;
    r->x = 0x9000;
    r->c = value3 >= 2;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0193F, SOM_RTS, "gen", initialize_dialogue_window_cursor_and_render_state, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 90, 33)
