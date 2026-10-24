#include "som_c.h"

/* C01235 copy_dialogue_window_rows_with_upload_padding   [class B, 34 bytes, 19 instructions]
 * Source: src/rom/copy_dialogue_window_rows_with_upload_padding.s
 * Documented in docs/event-dialogue-render-publication.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: XYV.
 */
static void copy_dialogue_window_rows_with_upload_padding(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = x;
    uint16_t y1 = y;
    bool overflow1 = overflow;
    do {
        uint8_t a1 = 0x10;
        uint8_t a_hi2 = a_hi1;
        uint16_t x2 = x1;
        uint16_t y2 = y1;
        for (;;) {
            uint8_t value = RAM8(0x0000 + y2);
            RAM8(0x0000 + x2) = value;
            a1 = (uint8_t)(a1 - 1);
            a_hi2 = value;
            x2 = (uint16_t)(x2 + 1);
            y2 = (uint16_t)(y2 + 1);
            if (!(a1 != 0)) break;
        }
        r->x = x2;
        r->y = y2;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        JSR(c, 0x1246, 0xC014DB); /* clear_dialogue_tile_upload_padding */
        uint16_t x_ret = r->x;
        RAM8(0xA175)--;
        a_hi1 = (uint16_t)(y2 + 0x10) >> 8;
        x1 = x_ret;
        y1 = (uint16_t)(y2 + 0x10);
        overflow1 = ((y2 ^ (uint16_t)(y2 + 0x10)) & ((uint16_t)(y2 + 0x10) ^ 0x10) & 0x8000) != 0;
    } while (RAM8(0xA175) != 0);
    r->x = x1;
    r->y = y1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01235, SOM_RTS, "gen", copy_dialogue_window_rows_with_upload_padding, 0, L_X | L_Y | L_V, 1, 1, 0, 34, 19)
