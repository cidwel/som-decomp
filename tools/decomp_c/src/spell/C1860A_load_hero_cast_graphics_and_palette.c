#include "som_c.h"

/* C1860A load_hero_cast_graphics_and_palette   [class B, 42 bytes, 20 instructions]
 * Source: src/rom/load_hero_cast_graphics_and_palette.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void load_hero_cast_graphics_and_palette(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x0014, x);
    RAM16_SET(0x0008, 0x40);
    uint16_t value = RAM16(0x0001);
    RAM16_SET(0x0000, (value & 0xFF) << 1 << 1 << 1 << 1);
    uint16_t value2 = RAM16(0x0000);
    RAM16_SET(0x0000, 0);
    r->a = 0xD0;
    r->y = (uint16_t)((uint16_t)(((value & 0xFF) << 1 << 1 << 1 << 1 << 1) + value2 + ((value & 0xFF) << 1 << 1 << 1 << 1 >> 0x0F)) + 0xDF00 + (((value & 0xFF) << 1 << 1 << 1 << 1 << 1) + value2 + ((value & 0xFF) << 1 << 1 << 1 << 1 >> 0x0F) > 0xFFFF));
    r->c = (uint16_t)(((value & 0xFF) << 1 << 1 << 1 << 1 << 1) + value2 + ((value & 0xFF) << 1 << 1 << 1 << 1 >> 0x0F)) + 0xDF00 + (((value & 0xFF) << 1 << 1 << 1 << 1 << 1) + value2 + ((value & 0xFF) << 1 << 1 << 1 << 1 >> 0x0F) > 0xFFFF) > 0xFFFF;
    r->z = 0;
    r->n = 0;
    r->v = (((uint16_t)(((value & 0xFF) << 1 << 1 << 1 << 1 << 1) + value2 + ((value & 0xFF) << 1 << 1 << 1 << 1 >> 0x0F)) ^ (uint16_t)((uint16_t)(((value & 0xFF) << 1 << 1 << 1 << 1 << 1) + value2 + ((value & 0xFF) << 1 << 1 << 1 << 1 >> 0x0F)) + 0xDF00 + (((value & 0xFF) << 1 << 1 << 1 << 1 << 1) + value2 + ((value & 0xFF) << 1 << 1 << 1 << 1 >> 0x0F) > 0xFFFF))) & ((uint16_t)((uint16_t)(((value & 0xFF) << 1 << 1 << 1 << 1 << 1) + value2 + ((value & 0xFF) << 1 << 1 << 1 << 1 >> 0x0F)) + 0xDF00 + (((value & 0xFF) << 1 << 1 << 1 << 1 << 1) + value2 + ((value & 0xFF) << 1 << 1 << 1 << 1 >> 0x0F) > 0xFFFF)) ^ 0xDF00) & 0x8000) != 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x8630, 0x01C599); GUARD_JSL(c, sp_call, 0x8630); } /* dispatch_object_graphics_plane_conversion */
    r->mf = 1;
    r->xf = 0;
    TAIL_CALL(c, 0xC185D8, SOM_RTS); /* load_object_weapon_palette_from_field_04f */
}
SOM_REGISTER(0xC1860A, SOM_RTS, "gen", load_hero_cast_graphics_and_palette, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 42, 20)
