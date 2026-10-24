#include "som_c.h"

/* C0205A copy_four_native_menu_frame_tile_chunks   [class B, 40 bytes, 21 instructions]
 * Source: src/rom/copy_four_native_menu_frame_tile_chunks.s
 * Documented in docs/event-menu-constructor.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: X.
 */
static void copy_four_native_menu_frame_tile_chunks(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    RAM8(0xA175) = 4;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 0;
    uint16_t y1 = y;
    do {
        uint8_t a1 = 8;
        uint8_t a_hi2 = a_hi1;
        uint16_t x2 = x1;
        uint16_t y2 = y1;
        for (;;) {
            uint8_t value = BUS8(c, 0xC777E5 + x2);
            RAM8(0x9000 + y2) = value;
            a1 = (uint8_t)(a1 - 1);
            a_hi2 = value;
            x2 = (uint16_t)(x2 + 1);
            y2 = (uint16_t)(y2 + 1);
            if (!(a1 != 0)) break;
        }
        RAM8(0xA175)--;
        a_hi1 = (uint16_t)(y2 + 0x38) >> 8;
        x1 = x2;
        y1 = (uint16_t)(y2 + 0x38);
    } while (RAM8(0xA175) != 0);
    r->x = x1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0205A, SOM_RTS, "gen", copy_four_native_menu_frame_tile_chunks, 0, L_X, 1, 1, 0, 40, 21)
