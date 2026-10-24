#include "som_c.h"

/* C2019E restore_complete_boss_screen_resources_and_character_tiles   [class B, 69 bytes, 33 instructions]
 * Source: src/rom/restore_complete_boss_screen_resources_and_character_tiles.s
 * Documented in docs/event-boss-screen-restore.md
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: XYCV.
 */
static void restore_complete_boss_screen_resources_and_character_tiles(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    RAM8(0x0000 + sp0) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 1) = dp >> 8;
    RAM8(0x0000 + sp0 - 2) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 3) = db;
    RAM8(0x0000 + sp0 - 4) = 0x7E;
    RAM16_SET(0x0364, RAM16(0x02C7));
    uint16_t value2 = RAM16(0x0FA2);
    uint16_t value3 = BUS16(c, 0xC20146 + (uint16_t)((uint16_t)(value2 - 0x54) << 1));
    r->a = value3;
    r->x = (uint16_t)((uint16_t)(value2 - 0x54) << 1);
    r->v = ((value2 ^ 0x54) & (value2 ^ (uint16_t)(value2 - 0x54)) & 0x8000) != 0;
    r->db = 0x7E;
    r->dp = 0x0200;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x01C1, 0xC221B7); GUARD_JSR(c, sp_call, 0x01C1); } /* interpret_boss_loader_commands */
    r->sp += 4;
    uint8_t db_ret = r->db;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x01C4, 0xC201E3); GUARD_JSR(c, sp_call, 0x01C4); } /* reload_active_boss_palette_slots_after_screen_restore */
    r->sp += 4;
    uint16_t value4 = BUS16_RDP(c, (db_ret << 0x10) + 0xEE8E);
    if (value4 == 0x3D34) {
        BUS16_SET(c, (db_ret << 0x10) + 0xEE00, 0);
    }
    uint16_t value5 = BUS16_RDP(c, (db_ret << 0x10) + 0xF08E);
    if (value5 == 0x3D34) {
        BUS16_SET(c, (db_ret << 0x10) + 0xF000, 0);
    }
    r->mf = 0;
    r->xf = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSL(c, 0x01DE, 0xDBF900); GUARD_JSL(c, sp_call, 0x01DE); } /* reload_all_active_screen_character_slots */
    r->sp += 4;
    uint8_t value6 = RAM8(0x0000 + sp0 - 3);
    uint8_t value7 = RAM8(0x0000 + sp0 - 2);
    uint8_t value8 = RAM8(0x0000 + sp0 - 1);
    uint8_t value9 = RAM8(0x0000 + sp0);
    r->c = value9 & 0x01;
    r->v = value9 & 0x40;
    r->mf = value9 & 0x20;
    r->xf = value9 & 0x10;
    r->db = value6;
    r->dp = (value8 << 8) | value7;
    r->i = value9 & 0x04;
    r->d = value9 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2019E, SOM_RTL, "gen", restore_complete_boss_screen_resources_and_character_tiles, 0, L_X | L_Y | L_C | L_V, 5, 0, 0, 69, 33)
