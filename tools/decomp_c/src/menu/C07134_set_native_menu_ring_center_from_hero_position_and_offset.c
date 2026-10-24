#include "som_c.h"

/* C07134 set_native_menu_ring_center_from_hero_position_and_offset   [class A, 24 bytes, 11 instructions]
 * Source: src/rom/set_native_menu_ring_center_from_hero_position_and_offset.s
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: XY.
 */
static void set_native_menu_ring_center_from_hero_position_and_offset(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    RAM16_SET(0x181A, (uint16_t)(RAM16(0xE020 + x) - 8));
    RAM8(0x0000 + sp0) = y >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)y;
    RAM16_SET(0x181C, (uint16_t)(RAM16(0xE022 + x) + RAM16(0x0000 + sp0 - 1)));
    RETURN_RTS(c);
}
SOM_REGISTER(0xC07134, SOM_RTS, "gen", set_native_menu_ring_center_from_hero_position_and_offset, 0, L_X | L_Y, 2, 0, 0, 24, 11)
