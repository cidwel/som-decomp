#include "som_c.h"

/* C0EA19 refresh_object_weapon_graphics_and_palette   [class B, 36 bytes, 14 instructions]
 * Source: src/rom/refresh_object_weapon_graphics_and_palette.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void refresh_object_weapon_graphics_and_palette(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x0014, x);
    RAM8(0xE084 + x) = 0;
    RAM8(0xE00C + x) = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xEA25, 0xC0EA41); GUARD_JSR(c, sp_call, 0xEA25); } /* prepare_object_weapon_graphics_resources */
    RAM16_SET(0x0008, 0x40);
    uint16_t value = RAM16(0x0000);
    RAM16_SET(0x0000, 0);
    r->a = 0xD4;
    r->y = value;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0xEA37, 0x01C599); GUARD_JSL(c, sp_call, 0xEA37); } /* dispatch_object_graphics_plane_conversion */
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0xEA3B, 0x0185E4); GUARD_JSL(c, sp_call, 0xEA3B); } /* load_object_weapon_palette_from_field_069 */
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0EA19, SOM_RTS, "gen", refresh_object_weapon_graphics_and_palette, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 36, 14)
