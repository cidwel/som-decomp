#include "som_c.h"

/* C1B147 append_map_scroll_animation_record   [class B, 55 bytes, 32 instructions]
 * Source: src/rom/append_map_scroll_animation_record.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$0000.  Callers read: BXY.
 */
static void append_map_scroll_animation_record(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint16_t y = r->y;
    BUS8_SET(c, 0x7F8000 + y, a);
    RAM8(0x0000 + sp0) = a;
    BUS8_SET(c, 0x7F8000 + (uint16_t)(y + 1), 0);
    BUS16_SET(c, 0x7F8000 + (uint16_t)(y + 2), ((((RAM8(0x0000 + sp0) & 0x3F) << 1) | 0x80) << 8) | 0);
    BUS16_SET(c, 0x7F8000 + (uint16_t)(y + 4), ((((RAM16(0x0000) & 7) << 8) | 0) >> 2) + 0x3600);
    BUS16_SET(c, 0x7F8000 + (uint16_t)(y + 6), 0);
    r->a = (r->a & 0x00FF) | (0 << 8);
    r->y = (uint16_t)(y + 8);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1B147, SOM_RTS, "gen", append_map_scroll_animation_record, 0, L_B | L_X | L_Y, 1, 1, 0, 55, 32)
