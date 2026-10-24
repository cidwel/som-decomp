#include "som_c.h"

/* C006A8 finish_dialogue_window_and_resume_script_cursor   [class B, 50 bytes, 20 instructions]
 * Source: src/rom/finish_dialogue_window_and_resume_script_cursor.s
 * Documented in docs/event-dialogue-render-core.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void finish_dialogue_window_and_resume_script_cursor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x06AA, 0xC0193F); /* initialize_dialogue_window_cursor_and_render_state */
    uint16_t a_all = r->a;
    RAM8(0xA15F) = 0;
    RAM8(0xA170) = 0;
    uint8_t value = RAM8(0x1D00);
    uint8_t a_hi1;
    if ((value & 0x10) != 0) {
        a_hi1 = a_all >> 8;
    } else {
        uint16_t value2 = RAM16(0x1D01);
        RAM16_SET(0x1D01, (uint16_t)(value2 + 1));
        a_hi1 = (uint16_t)(value2 + 1) >> 8;
    }
    RAM8(0x1D00) = 0;
    RAM8(0xA15F) = 0;
    RAM8(0xA15C) = 0;
    RAM8(0xA16F) = 0;
    r->a = (a_hi1 << 8) | 0;
    r->z = 1;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC006A8, SOM_RTS, "gen", finish_dialogue_window_and_resume_script_cursor, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 50, 20)
