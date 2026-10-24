#include "som_c.h"

/* C014C6 copy_requested_dialogue_rows_to_upload_buffer   [class A, 21 bytes, 12 instructions]
 * Source: src/rom/copy_requested_dialogue_rows_to_upload_buffer.s
 * Documented in docs/event-dialogue-render-publication.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: XY.
 */
static void copy_requested_dialogue_rows_to_upload_buffer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = x;
    uint16_t y1 = y;
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
        RAM8(0xA171)--;
        a_hi1 = a_hi2;
        x1 = x2;
        y1 = y2;
    } while (RAM8(0xA171) != 0);
    r->x = x1;
    r->y = y1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC014C6, SOM_RTS, "gen", copy_requested_dialogue_rows_to_upload_buffer, 0, L_X | L_Y, 1, 1, 0, 21, 12)
