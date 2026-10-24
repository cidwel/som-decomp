#include "som_c.h"

/* C01B20 move_numeric_choice_up_with_native_wraparound   [class B, 27 bytes, 14 instructions]
 * Source: src/rom/move_numeric_choice_up_with_native_wraparound.s
 * Documented in docs/event-dialogue-numeric-selection.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYV.
 */
static void move_numeric_choice_up_with_native_wraparound(SomCtx *c)
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
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool overflow1;
    if (!zero) {
        a_hi1 = a_hi;
        x1 = x;
        y1 = y;
        overflow1 = overflow;
    } else {
        r->sp -= 1;
        JSR(c, 0x1B25, 0xC01B55); /* toggle_numeric_choice_tile_attributes_and_request_publication */
        r->sp += 1;
        uint16_t a_all = r->a;
        uint8_t value = RAM8(0xA200);
        uint8_t a1;
        if ((uint8_t)(value - 1) != 0xFF) {
            a1 = (uint8_t)(value - 1);
        } else {
            a1 = (uint8_t)(RAM8(0xA1D4) - 1);
        }
        RAM8(0xA200) = a1;
        r->a = (a_all >> 8 << 8) | a1;
        r->y = (a_all >> 8 << 8) | a1;
        r->c = (uint8_t)(value - 1) >= 0xFF;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 1;
        JSR(c, 0x1B38, 0xC01B55); /* toggle_numeric_choice_tile_attributes_and_request_publication */
        r->sp += 1;
        uint16_t a_all2 = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret2 = r->y;
        bool overflow_ret2 = r->v;
        a_hi1 = a_all2 >> 8;
        x1 = x_ret2;
        y1 = y_ret2;
        overflow1 = overflow_ret2;
    }
    r->a = (a_hi1 << 8) | a;
    r->x = x1;
    r->y = y1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01B20, SOM_RTS, "gen", move_numeric_choice_up_with_native_wraparound, 0, L_A | L_B | L_X | L_Y | L_V, 1, 1, 0, 27, 14)
