#include "som_c.h"

/* D0D263 append_native_menu_descriptor_from_category_table   [class A, 18 bytes, 11 instructions]
 * Source: src/rom/append_native_menu_descriptor_from_category_table.s
 * Documented in docs/event-menu-descriptor-sources.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: XYV.
 */
static void append_native_menu_descriptor_from_category_table(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x1828);
    uint16_t value2 = BUS16(c, 0xD8FD60 + (uint16_t)((uint16_t)(a << 1) + value));
    BUS16_SET(c, 0x0000 + y, value2);
    r->y = (uint16_t)(y + 2);
    r->v = (((uint16_t)(a << 1) ^ (uint16_t)((uint16_t)(a << 1) + value)) & (value ^ (uint16_t)((uint16_t)(a << 1) + value)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0D263, SOM_RTS, "hand", append_native_menu_descriptor_from_category_table, 0, L_X | L_Y | L_V, 2, 0, 0, 18, 11)
