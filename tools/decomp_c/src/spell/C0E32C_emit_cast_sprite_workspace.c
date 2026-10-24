#include "som_c.h"

/* C0E32C emit_cast_sprite_workspace   [class A, 37 bytes, 19 instructions]
 * Source: src/rom/emit_cast_sprite_workspace.s
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void emit_cast_sprite_workspace(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a_hi = r->a >> 8;
    RAM8(0x0000 + sp0) = RAM8(0x00ED);
    RAM8(0x00ED) = 0x40;
    r->a = (a_hi << 8) | 0x40;
    r->z = 0;
    r->n = 0;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xE337, 0xC0E355); GUARD_JSR(c, sp_call, 0xE337); } /* initialize_map_sprite_workspace */
    r->sp += 1;
    uint16_t dp_ret = r->dp;
    uint16_t a_all = r->a;
    BUS8_SET(c, (uint16_t)(dp_ret + 0x7D), 1);
    BUS8_SET(c, (uint16_t)(dp_ret + 0x7C), 0);
    BUS8_SET(c, (uint16_t)(dp_ret + 0x5A), 0x10);
    BUS8_SET(c, (uint16_t)(dp_ret + 0x59), 1);
    r->a = (a_all >> 8 << 8) | 1;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xE34A, 0xC0E38E); GUARD_JSR(c, sp_call, 0xE34A); } /* emit_complete_map_actor_and_hud_sprites */
    r->sp += 1;
    uint16_t dp_ret2 = r->dp;
    BUS8_SET(c, (uint16_t)(dp_ret2 + 0xED), RAM8(0x0000 + sp0));
    r->mf = 1;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0E32C, SOM_RTS, "gen", emit_cast_sprite_workspace, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 37, 19)
