#include "som_c.h"

/* C2AE55 initialize_complete_picker_cursor_object_buffer   [class D, 80 bytes, 33 instructions]
 * Source: src/rom/initialize_complete_picker_cursor_object_buffer.s
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: XYCV.
 */
static void initialize_complete_picker_cursor_object_buffer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t y = r->y;
    const bool overflow = r->v;
    uint16_t x1 = 0;
    for (;;) {
        BUS16_SET(c, 0x000800 + x1, 0xE0FF);
        x1 = (uint16_t)(x1 + 4);
        if (!(x1 < 0x0200)) break;
    }
    uint16_t x2 = x1;
    bool carry1 = 0;
    for (;;) {
        BUS16_SET(c, 0x000800 + x2, 0);
        uint16_t x2_next = (uint16_t)(x2 + 1);
        bool carry1_next = (uint16_t)(x2 + 1) >= 0x0220;
        x2 = x2_next;
        carry1 = carry1_next;
        if (!(x2 < 0x0220)) break;
    }
    RAM16_SET(0x0A00, 0xAA);
    RAM16_SET(0x0802, 0x3FE0);
    RAM16_SET(0x0806, 0x7FE0);
    RAM16_SET(0x080A, 0xBFE0);
    RAM16_SET(0x080E, 0xFFE0);
    BUS8_SET(c, 0x002101, 3);
    BUS8_SET(c, 0x002121, 0x81);
    BUS8_SET(c, 0x002122, 0xFF);
    BUS8_SET(c, 0x002122, 0xFF);
    r->x = (uint8_t)x2;
    r->y = y;
    r->c = carry1;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2AE55, SOM_RTS, "gen", initialize_complete_picker_cursor_object_buffer, 0, L_X | L_Y | L_C | L_V, 1, 1, 1, 80, 33)
