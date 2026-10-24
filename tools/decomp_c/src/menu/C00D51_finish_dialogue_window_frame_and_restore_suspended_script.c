#include "som_c.h"

/* C00D51 finish_dialogue_window_frame_and_restore_suspended_script   [class B, 46 bytes, 16 instructions]
 * Source: src/rom/finish_dialogue_window_frame_and_restore_suspended_script.s
 * Documented in docs/event-dialogue-window-state.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void finish_dialogue_window_frame_and_restore_suspended_script(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM8(0xA15C) = 0;
    JSR(c, 0x0D56, 0xC0193F); /* initialize_dialogue_window_cursor_and_render_state */
    RAM8(0xA170) = 0;
    RAM8(0x1D00) &= 0xFA;
    RAM8(0x1D10) &= 0xFC;
    uint16_t value3 = RAM16(0x1D01);
    RAM16_SET(0x1D01, (uint16_t)(value3 + 1));
    r->a = (uint16_t)(value3 + 1);
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x0D7D, 0xC00F2C); /* restore_suspended_dialogue_context_and_script_cursor */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC00D51, SOM_RTS, "gen", finish_dialogue_window_frame_and_restore_suspended_script, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 46, 16)
