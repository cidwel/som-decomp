#include "som_c.h"

/* C1F3F3 stage_event_menu_sprites_and_preserve_actor_context   [class A, 16 bytes, 9 instructions]
 * Source: src/rom/stage_event_menu_sprites_and_preserve_actor_context.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: XYCV.
 */
static void stage_event_menu_sprites_and_preserve_actor_context(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    RAM8(0x0000 + sp0) = y >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)y;
    RAM8(0x0000 + sp0 - 2) = x >> 8;
    RAM8(0x0000 + sp0 - 3) = (uint8_t)x;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSL(c, 0xF3F8, 0x00E328); GUARD_JSL(c, sp_call, 0xF3F8); } /* cast_sprite_emission_long */
    r->sp += 4;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xF3FD, 0xC1CB88); GUARD_JSR(c, sp_call, 0xF3FD); } /* update_event_sprite_shadow_palette_and_oam_priority */
    r->sp += 4;
    uint8_t value = RAM8(0x0000 + sp0 - 3);
    uint8_t value2 = RAM8(0x0000 + sp0 - 2);
    uint8_t value3 = RAM8(0x0000 + sp0 - 1);
    uint8_t value4 = RAM8(0x0000 + sp0);
    r->x = (value2 << 8) | value;
    r->y = (value4 << 8) | value3;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1F3F3, SOM_RTS, "gen", stage_event_menu_sprites_and_preserve_actor_context, 0, L_X | L_Y | L_C | L_V, 4, 0, 0, 16, 9)
