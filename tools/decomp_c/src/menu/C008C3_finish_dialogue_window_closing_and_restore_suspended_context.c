#include "som_c.h"

/* C008C3 finish_dialogue_window_closing_and_restore_suspended_context   [class B, 76 bytes, 30 instructions]
 * Source: src/rom/finish_dialogue_window_closing_and_restore_suspended_context.s
 * Documented in docs/event-dialogue-window-close.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void finish_dialogue_window_closing_and_restore_suspended_context(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t value = RAM8(0xA162);
    uint16_t x2;
    uint16_t y2;
    if (value == 2) {
        x2 = x;
        y2 = y;
    } else {
        uint16_t x1 = 0;
        uint16_t y1 = 0x2C;
        for (;;) {
            RAM8(0x9C00 + x1) = 0;
            x1 = (uint16_t)(x1 + 1);
            y1 = (uint16_t)(y1 - 1);
            if (!(y1 != 0)) break;
        }
        x2 = x1;
        y2 = y1;
    }
    RAM8(0xA15E) = 0;
    RAM8(0xA16D) = 0;
    RAM8(0xA170) = 0;
    uint8_t value2 = RAM8(0x1D04);
    uint8_t a_hi1;
    if ((value2 & 0x80) != 0) {
        a_hi1 = a_hi;
    } else {
        uint16_t value3 = RAM16(0x1D01);
        RAM16_SET(0x1D01, (uint16_t)(value3 + 1));
        a_hi1 = (uint16_t)(value3 + 1) >> 8;
    }
    RAM8(0x1D00) |= 0x80;
    uint8_t value5 = RAM8(0xA162);
    uint8_t a1;
    bool zero1;
    bool negative1;
    if (value5 != 2) {
        a1 = value5;
        zero1 = value5 == 2;
        negative1 = (uint8_t)(value5 - 2) & 0x80;
    } else {
        uint8_t value6 = RAM8(0xA187);
        RAM8(0xA187) &= 0xFE;
        a1 = 1;
        zero1 = (value6 & 1) == 0;
        negative1 = 0;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x2;
    r->y = y2;
    r->c = value5 >= 2; /* CMP #$02; LDA and TRB leave C alone */
    r->z = zero1;
    r->n = negative1;
    r->v = overflow;
    JSR(c, 0x090D, 0xC00F2C); /* restore_suspended_dialogue_context_and_script_cursor */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC008C3, SOM_RTS, "hand", finish_dialogue_window_closing_and_restore_suspended_context, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 76, 30)
