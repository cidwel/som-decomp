#include "som_c.h"

/* C07A28 rebuild_native_equipped_actor_stats_and_cap_persistent_mana   [class B, 44 bytes, 24 instructions]
 * Source: src/rom/rebuild_native_equipped_actor_stats_and_cap_persistent_mana.s
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void rebuild_native_equipped_actor_stats_and_cap_persistent_mana(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = 0x7E;
    RAM8(0x0000 + sp0 - 2) = x >> 8;
    RAM8(0x0000 + sp0 - 3) = (uint8_t)x;
    r->a = (a >> 8 << 8) | 0x7E;
    r->z = 0;
    r->n = 0;
    r->db = 0x7E;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSL(c, 0x7A36, 0xC00036); GUARD_JSL(c, sp_call, 0x7A36); } /* rebuild_actor_stats_public_jump */
    r->sp += 4;
    uint8_t db_ret = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    if (x_ret) {
        c->fail = 3;
        return;
    } else {
        uint8_t value6 = RAM8(0x0000 + sp0 - 3);
        uint8_t value7 = RAM8(0x0000 + sp0 - 2);
        uint8_t value8 = BUS8_RDP(c, (db_ret << 0x10) + 0xCC7D + (((((uint8_t)((value7 << 8) | value6) << 8) | value7) >> 1) & 3));
        uint8_t value9 = RAM8(ACTOR_WEAPON_LEVEL + ((value7 << 8) | value6));
        if (value8 >= value9) {
            BUS8_SET(c, (db_ret << 0x10) + 0xCC7D + (((((uint8_t)((value7 << 8) | value6) << 8) | value7) >> 1) & 3), value9);
        }
        uint8_t value10 = RAM8(0x0000 + sp0 - 1);
        uint8_t value11 = RAM8(0x0000 + sp0);
        r->a = (uint8_t)a_all;
        r->x = (value7 << 8) | value6;
        r->y = ((((uint8_t)((value7 << 8) | value6) << 8) | value7) >> 1) & 3;
        r->c = value11 & 0x01;
        r->v = value11 & 0x40;
        r->mf = value11 & 0x20;
        r->xf = value11 & 0x10;
        r->db = value10;
        r->i = value11 & 0x04;
        r->d = value11 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC07A28, SOM_RTS, "gen", rebuild_native_equipped_actor_stats_and_cap_persistent_mana, 0, L_B | L_X | L_Y | L_C | L_V, 4, 0, 0, 44, 24)
