#include "som_c.h"

/* C014DB clear_dialogue_tile_upload_padding   [class A, 16 bytes, 9 instructions]
 * Source: src/rom/clear_dialogue_tile_upload_padding.s
 * Documented in docs/event-dialogue-render-publication.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: XY.
 */
static void clear_dialogue_tile_upload_padding(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint8_t a1 = 8;
    uint8_t a_hi1 = 0;
    uint16_t x1 = x;
    for (;;) {
        RAM16_SET(0x0000 + x1, 0);
        bool again = (uint16_t)(((a_hi1 << 8) | a1) - 1) != 0;
        uint8_t a1_next = (uint8_t)(((a_hi1 << 8) | a1) - 1);
        uint8_t a_hi1_next = (uint16_t)(((a_hi1 << 8) | a1) - 1) >> 8;
        uint16_t x1_next = (uint16_t)(x1 + 2);
        a1 = a1_next;
        a_hi1 = a_hi1_next;
        x1 = x1_next;
        if (!again) break;
    }
    r->x = x1;
    r->y = y;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC014DB, SOM_RTS, "gen", clear_dialogue_tile_upload_padding, 0, L_X | L_Y, 1, 1, 0, 16, 9)
