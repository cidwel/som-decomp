#include "som_c.h"

/* C0AE35 decode_and_pack_complete_world_map_survey_tile_groups   [class D, 117 bytes, 53 instructions]
 * Source: src/rom/decode_and_pack_complete_world_map_survey_tile_groups.s
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: XY.
 */
static void decode_and_pack_complete_world_map_survey_tile_groups(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t x = r->x;
    uint8_t a_hi_ae43 = 0;
    uint16_t x_ae43 = 0;
    uint16_t direct_page_ae43 = 0;
    uint8_t a_hi_ae5d = 0;
    uint16_t x_ae5d = 0;
    uint16_t direct_page_ae5d = 0;
    uint8_t data_bank_ae5d = 0;
    uint8_t a_hi_ae5d2 = 0;
    uint16_t x_ae5d2 = 0;
    uint16_t direct_page_ae5d2 = 0;
    uint8_t data_bank_ae5d2 = 0;
    RAM16_SET(0x0012, 0x1E);
    RAM16_SET(0x0014, 0x10);
    RAM16_SET(0x0010, 0);
    a_hi_ae43 = 0;
    x_ae43 = x;
    direct_page_ae43 = 0;
    BUS8_SET(c, 0x002115, 0x80);
    BUS8_SET(c, 0x004374, 0x7F);
    BUS16_SET(c, 0x004370, 0x1801);
    BUS16_SET(c, 0x004372, 0x40);
    a_hi_ae5d = 0;
    x_ae5d = x_ae43;
    direct_page_ae5d = direct_page_ae43;
    data_bank_ae5d = 0;
    goto shared_AE5D;
    shared_AE5D:;
    BUS8_SET(c, (data_bank_ae5d << 0x10) + 0x2183, 1);
    uint16_t value = BUS16_RDP(c, (uint16_t)(direct_page_ae5d + 0x10));
    BUS16_SET(c, (data_bank_ae5d << 0x10) + 0x2181, (uint16_t)(((((value & 0x0F) << 8) | 0) << 1) + 0xE000));
    RAM8(0x0000 + sp0) = data_bank_ae5d;
    r->a = 0x0B00;
    r->x = x_ae5d;
    r->y = value;
    r->c = ((((value & 0x0F) << 8) | 0) << 1) + 0xE000 > 0xFFFF;
    r->z = 0;
    r->n = 0;
    r->v = ((((((value & 0x0F) << 8) | 0) << 1) ^ (uint16_t)(((((value & 0x0F) << 8) | 0) << 1) + 0xE000)) & ((uint16_t)(((((value & 0x0F) << 8) | 0) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_ae5d;
    r->dp = 0x0B00;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xAE7E, 0xC09A06); GUARD_JSR(c, sp_call, 0xAE7E); } /* external */
    r->sp += 1;
    uint16_t dp_ret = r->dp;
    uint16_t x_ret2 = r->x;
    uint8_t value2 = RAM8(0x0000 + sp0);
    uint16_t value3 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x10));
    BUS16_SET(c, (uint16_t)(dp_ret + 0x10), (uint16_t)(value3 + 1));
    if (((uint16_t)(value3 + 1) & 0x0F) != 0) {
        a_hi_ae5d = 0;
        x_ae5d = x_ret2;
        direct_page_ae5d = dp_ret;
        data_bank_ae5d = value2;
        goto shared_AE5D;
    }
    r->a = (uint16_t)(value3 + 1) & 0x0F;
    r->z = ((uint16_t)(value3 + 1) & 0x0F) == 0;
    r->n = (uint16_t)(value3 + 1) & 0x0F & 0x8000;
    r->mf = 0;
    r->xf = 0;
    r->db = value2;
    { const uint16_t sp_call = r->sp; JSR(c, 0xAE8E, 0xC0AE96); GUARD_JSR(c, sp_call, 0xAE8E); } /* average_four_world_map_pixels_and_pack_all_eight_bitplanes */
    uint8_t db_ret2 = r->db;
    uint16_t a_all2 = r->a;
    uint16_t x_ret3 = r->x;
    uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x12));
    BUS8_SET(c, (uint16_t)(dp_ret + 0x12), (uint8_t)(value4 - 1));
    if ((uint8_t)(value4 - 1) != 0) {
        a_hi_ae5d2 = a_all2 >> 8;
        x_ae5d2 = x_ret3;
        direct_page_ae5d2 = dp_ret;
        data_bank_ae5d2 = db_ret2;
        goto shared_AE5D_1;
    }
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
    shared_AE5D_1:;
    BUS8_SET(c, (data_bank_ae5d2 << 0x10) + 0x2183, 1);
    uint16_t value5 = BUS16_RDP(c, (uint16_t)(direct_page_ae5d2 + 0x10));
    BUS16_SET(c, (data_bank_ae5d2 << 0x10) + 0x2181, (uint16_t)(((((value5 & 0x0F) << 8) | 0) << 1) + 0xE000));
    RAM8(0x0000 + sp0) = data_bank_ae5d2;
    r->a = 0x0B00;
    r->x = x_ae5d2;
    r->y = value5;
    r->c = ((((value5 & 0x0F) << 8) | 0) << 1) + 0xE000 > 0xFFFF;
    r->z = 0;
    r->n = 0;
    r->v = ((((((value5 & 0x0F) << 8) | 0) << 1) ^ (uint16_t)(((((value5 & 0x0F) << 8) | 0) << 1) + 0xE000)) & ((uint16_t)(((((value5 & 0x0F) << 8) | 0) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_ae5d2;
    r->dp = 0x0B00;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xAE7E, 0xC09A06); GUARD_JSR(c, sp_call, 0xAE7E); } /* external */
    r->sp += 1;
    uint16_t dp_ret2 = r->dp;
    uint16_t x_ret5 = r->x;
    uint8_t value6 = RAM8(0x0000 + sp0);
    uint16_t value7 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 0x10));
    BUS16_SET(c, (uint16_t)(dp_ret2 + 0x10), (uint16_t)(value7 + 1));
    if (((uint16_t)(value7 + 1) & 0x0F) != 0) {
        a_hi_ae5d = 0;
        x_ae5d = x_ret5;
        direct_page_ae5d = dp_ret2;
        data_bank_ae5d = value6;
        goto shared_AE5D;
    }
    r->a = (uint16_t)(value7 + 1) & 0x0F;
    r->z = ((uint16_t)(value7 + 1) & 0x0F) == 0;
    r->n = (uint16_t)(value7 + 1) & 0x0F & 0x8000;
    r->mf = 0;
    r->xf = 0;
    r->db = value6;
    { const uint16_t sp_call = r->sp; JSR(c, 0xAE8E, 0xC0AE96); GUARD_JSR(c, sp_call, 0xAE8E); } /* average_four_world_map_pixels_and_pack_all_eight_bitplanes */
    uint8_t db_ret4 = r->db;
    uint16_t a_all4 = r->a;
    uint16_t x_ret6 = r->x;
    uint8_t value8 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 0x12));
    BUS8_SET(c, (uint16_t)(dp_ret2 + 0x12), (uint8_t)(value8 - 1));
    if ((uint8_t)(value8 - 1) != 0) {
        a_hi_ae5d2 = a_all4 >> 8;
        x_ae5d2 = x_ret6;
        direct_page_ae5d2 = dp_ret2;
        data_bank_ae5d2 = db_ret4;
        goto shared_AE5D_1;
    }
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0AE35, SOM_RTS, "gen", decode_and_pack_complete_world_map_survey_tile_groups, 0, L_X | L_Y, 1, 1, 0, 472, 53)
