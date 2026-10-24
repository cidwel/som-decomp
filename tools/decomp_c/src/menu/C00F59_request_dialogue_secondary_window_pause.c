#include "som_c.h"

/* C00F59 request_dialogue_secondary_window_pause   [class C, 46 bytes, 19 instructions]
 * Source: src/rom/request_dialogue_secondary_window_pause.s
 * Documented in docs/event-dialogue-pause.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void request_dialogue_secondary_window_pause(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    RAM8(0xA170) = 0x51;
    uint8_t value = RAM8(0xA187);
    uint8_t a1;
    uint8_t a_hi1;
    bool carry1;
    if ((value & 1) != 0) {
        r->a = a_hi << 8 | (value & 1);
        JSR(c, 0x0F7F, 0xC00F08); /* save_dialogue_cursor_before_temporary_window */
        uint16_t a_all = r->a;
        bool carry_ret = r->c;
        RAM8(0xA162) = 2;
        a1 = 2;
        a_hi1 = a_all >> 8;
        carry1 = carry_ret;
    } else {
        RAM8(0xA15E) = 4;
        a1 = 4;
        a_hi1 = a_hi;
        carry1 = carry;
    }
    r->a = (a_hi1 << 8) | a1;
    r->c = carry1;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC00F59, SOM_RTS, "gen", request_dialogue_secondary_window_pause, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 46, 19)
