#include "som_c.h"

/* C00435 clear_dialogue_window_tile_run_and_advance_destination   [class A, 23 bytes, 14 instructions]
 * Source: src/rom/clear_dialogue_window_tile_run_and_advance_destination.s
 * Documented in docs/event-dialogue-render-core.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: BYV.
 */
static void clear_dialogue_window_tile_run_and_advance_destination(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t x = r->x;
    const bool overflow = r->v;
    uint8_t value = RAM8(0xA162);
    uint8_t a1;
    uint8_t a_hi1;
    if (value != 3) {
        a1 = value;
        a_hi1 = 0x20;
    } else {
        a1 = 0x20;
        a_hi1 = 0x60;
    }
    uint8_t a2 = a_hi1;
    uint8_t a_hi2 = a1;
    uint16_t x1 = x;
    for (;;) {
        RAM8(0x9400 + x1) = 0;
        a2 = (uint8_t)(a2 - 1);
        x1 = (uint16_t)(x1 + 1);
        if (!(a2 != 0)) break;
    }
    r->a = (a_hi2 << 8) | a2;
    r->y = x1;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC00435, SOM_RTS, "gen", clear_dialogue_window_tile_run_and_advance_destination, 0, L_B | L_Y | L_V, 1, 1, 0, 23, 14)
