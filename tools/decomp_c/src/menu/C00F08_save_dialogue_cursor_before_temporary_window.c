#include "som_c.h"

/* C00F08 save_dialogue_cursor_before_temporary_window   [class A, 36 bytes, 13 instructions]
 * Source: src/rom/save_dialogue_cursor_before_temporary_window.s
 * Documented in docs/event-dialogue-pause.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYV.
 */
static void save_dialogue_cursor_before_temporary_window(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t value = RAM8(0xA162);
    uint8_t a_hi1;
    if (value == 2) {
        a_hi1 = a_hi;
    } else {
        uint16_t value2 = RAM16(0x1D01);
        RAM16_SET(0xA1D1, (uint16_t)(value2 + 1));
        RAM8(0xA1D3) = RAM8(0x1D03);
        RAM8(0xA188) = value;
        a_hi1 = (uint16_t)(value2 + 1) >> 8;
    }
    r->a = (r->a & 0x00FF) | (a_hi1 << 8);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC00F08, SOM_RTS, "gen", save_dialogue_cursor_before_temporary_window, 0, L_B | L_Y | L_V, 1, 1, 0, 36, 13)
