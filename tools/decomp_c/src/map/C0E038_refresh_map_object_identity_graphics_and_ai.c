#include "som_c.h"

/* C0E038 refresh_map_object_identity_graphics_and_ai   [class B, 32 bytes, 15 instructions]
 * Source: src/rom/refresh_map_object_identity_graphics_and_ai.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void refresh_map_object_identity_graphics_and_ai(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    RAM8(0x0000 + sp0) = x >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
    uint8_t value = RAM8(0xE03D + x);
    r->a = (a >> 8 << 8) | value;
    r->z = value == 0;
    r->n = value & 0x80;
    r->mf = 1;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSL(c, 0xE041, 0xC0003F); GUARD_JSL(c, sp_call, 0xE041); } /* change_actor_identity_public_jump */
    r->sp += 2;
    uint16_t dp_ret = r->dp;
    uint8_t value2 = RAM8(0x0000 + sp0 - 1);
    uint8_t value3 = RAM8(0x0000 + sp0);
    r->x = (value3 << 8) | value2;
    r->z = ((value3 << 8) | value2) == 0;
    r->n = ((value3 << 8) | value2) & 0x8000;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xE047, 0xC0EA19); GUARD_JSR(c, sp_call, 0xE047); } /* refresh_object_weapon_graphics_and_palette */
    uint8_t db_ret2 = r->db;
    uint16_t a_all2 = r->a;
    uint16_t value4 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x14));
    uint8_t value5 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xE03D + value4);
    RAM8(0x0000 + sp0) = value4 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)value4;
    r->a = (a_all2 >> 8 << 8) | value5;
    r->x = value4;
    r->z = value5 == 0;
    r->n = value5 & 0x80;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSL(c, 0xE055, 0xC10020); GUARD_JSL(c, sp_call, 0xE055); } /* set_actor_program_long */
    r->sp += 2;
    bool x_ret5 = r->xf;
    if (x_ret5) {
        c->fail = 3;
        return;
    } else {
        r->x = (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1);
        r->xf = 0;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC0E038, SOM_RTS, "gen", refresh_map_object_identity_graphics_and_ai, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 2, 0, 0, 32, 15)
