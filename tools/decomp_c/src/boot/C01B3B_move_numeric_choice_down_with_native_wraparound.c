#include "som_c.h"

/* C01B3B move_numeric_choice_down_with_native_wraparound   [class B, 26 bytes, 13 instructions]
 * Source: src/rom/move_numeric_choice_down_with_native_wraparound.s
 * Documented in docs/event-dialogue-numeric-selection.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: nothing.
 */
static void move_numeric_choice_down_with_native_wraparound(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const bool zero = r->z;
    if (zero) {
        r->sp -= 1;
        JSR(c, 0x1B40, 0xC01B55); /* toggle_numeric_choice_tile_attributes_and_request_publication */
        r->sp += 1;
        uint16_t a_all = r->a;
        uint8_t value = RAM8(0xA200);
        uint8_t value2 = RAM8(0xA1D4);
        uint8_t a1;
        if ((uint8_t)(value + 1) < value2) {
            a1 = (uint8_t)(value + 1);
        } else {
            a1 = 0;
        }
        RAM8(0xA200) = a1;
        r->a = (a_all >> 8 << 8) | a1;
        r->y = (a_all >> 8 << 8) | a1;
        r->c = (uint8_t)(value + 1) >= value2;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 1;
        JSR(c, 0x1B52, 0xC01B55); /* toggle_numeric_choice_tile_attributes_and_request_publication */
        r->sp += 1;
    }
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01B3B, SOM_RTS, "gen", move_numeric_choice_down_with_native_wraparound, 0, 0, 1, 1, 0, 26, 13)
