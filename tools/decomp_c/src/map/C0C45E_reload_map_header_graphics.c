#include "som_c.h"

/* C0C45E reload_map_header_graphics   [class A, 35 bytes, 17 instructions]
 * Source: src/rom/reload_map_header_graphics.s
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void reload_map_header_graphics(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value = RAM16(0x00DC);
    uint16_t value2 = BUS16(c, 0xC87000 + (uint16_t)(value << 1));
    RAM16_SET(0x001D, value2);
    RAM8(0x001F) = 0xC8;
    uint8_t value3 = BUS8_RDL(c, (RAM8(0x001F) << 0x10) + RAM16(0x001D) + 1, RAM8(0x001F));
    RAM8(0x001B) = value3;
    uint8_t value4 = BUS8_RDL(c, (RAM8(0x001F) << 0x10) + RAM16(0x001D), RAM8(0x001F));
    RAM8(0x001C) = value4;
    r->a = (value2 >> 8 << 8) | value4;
    r->x = (uint8_t)(value << 1);
    r->y = 0;
    r->c = value & 0x8000;
    r->z = value4 == 0;
    r->n = value4 & 0x80;
    { const uint16_t sp_call = r->sp; JSL(c, 0xC47F, 0x01F403); GUARD_JSL(c, sp_call, 0xC47F); } /* initialize_map_graphics_resources */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC0C45E, SOM_RTL, "gen", reload_map_header_graphics, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 35, 17)
