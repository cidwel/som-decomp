#include "som_c.h"

/* C01AF1 cancel_numeric_choice_when_script_cancellation_is_available   [class B, 47 bytes, 21 instructions]
 * Source: src/rom/cancel_numeric_choice_when_script_cancellation_is_available.s
 * Documented in docs/event-dialogue-numeric-selection.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYV.
 */
static void cancel_numeric_choice_when_script_cancellation_is_available(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool zero = r->z;
    const bool overflow = r->v;
    uint8_t a_hi2;
    uint16_t x2;
    uint16_t y2;
    bool overflow2;
    if (!zero) {
        a_hi2 = a_hi;
        x2 = x;
        y2 = y;
        overflow2 = overflow;
    } else {
        uint16_t value = RAM16(0xA1D5);
        uint8_t value2 = RAM8(0x1D03);
        uint8_t value3 = BUS8(c, (value2 << 0x10) + value);
        uint8_t value4 = BUS8(c, (value2 << 0x10) + 1 + value);
        uint8_t a_hi1;
        uint16_t x1;
        uint16_t y1;
        bool overflow1;
        if ((value3 | value4) == 0) {
            a_hi1 = a_hi;
            x1 = value;
            y1 = y;
            overflow1 = overflow;
        } else {
            RAM16_SET(0x1D01, value);
            uint8_t value5 = RAM8(0xA160);
            RAM8(0xA160) = (uint8_t)(value5 + 1);
            r->a = (value >> 8 << 8) | (uint8_t)(value5 + 1);
            r->x = value;
            r->db = value2;
            r->sp -= 2;
            JSR(c, 0x1B1C, 0xC01BAF); /* external */
            r->sp += 2;
            uint16_t a_all = r->a;
            uint16_t x_ret = r->x;
            uint16_t y_ret = r->y;
            bool overflow_ret = r->v;
            a_hi1 = a_all >> 8;
            x1 = x_ret;
            y1 = y_ret;
            overflow1 = overflow_ret;
        }
        a_hi2 = a_hi1;
        x2 = x1;
        y2 = y1;
        overflow2 = overflow1;
    }
    r->a = (a_hi2 << 8) | a;
    r->x = x2;
    r->y = y2;
    r->v = overflow2;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01AF1, SOM_RTS, "gen", cancel_numeric_choice_when_script_cancellation_is_available, 0, L_A | L_B | L_X | L_Y | L_V, 3, 1, 0, 47, 21)
