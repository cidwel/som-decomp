#include "som_c.h"

/* C233BE create_boss_projectile_with_graphics_and_palette   [class B, 122 bytes, 58 instructions]
 * Source: src/rom/create_boss_projectile_with_graphics_and_palette.s
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: BXYCV.
 */
static void create_boss_projectile_with_graphics_and_palette(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    BUS16_SET(c, (uint16_t)(dp + 0x9D), a);
    BUS16_SET(c, (uint16_t)(dp + 0x9F), y);
    uint16_t value = RAM16(0x002B + x);
    uint16_t value2 = BUS16_RDP(c, (uint16_t)(dp + 0x95));
    BUS16_SET(c, (uint16_t)(dp + 0x95), (uint16_t)(value + value2));
    BUS16_SET(c, (uint16_t)(dp + 0x99), RAM16(0x0066 + x) >> 1);
    uint16_t value4 = RAM16(0x0032 + x);
    uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp + 0x97));
    uint16_t value6 = BUS16_RDP(c, (uint16_t)(dp + 0x99));
    BUS16_SET(c, (uint16_t)(dp + 0x97), (uint16_t)((uint16_t)(value4 + value5) - value6));
    BUS16_SET(c, (uint16_t)(dp + 0x99), x);
    BUS16_SET(c, (uint16_t)(dp + 0x9B), (uint16_t)(((((y & 3) << 8) | 0) << 1) + 0xE000));
    uint16_t value7 = RAM16(0x0098 + x);
    uint16_t value8 = BUS16_RDP(c, (uint16_t)(dp + 0x9D));
    uint16_t value9 = BUS16(c, 0xDCE683 + (uint16_t)(value8 << 1));
    r->a = value9;
    r->x = value9;
    r->y = (value7 & 3) | 0xAA20;
    r->c = value8 & 0x8000;
    r->z = value9 == 0;
    r->n = value9 & 0x8000;
    r->v = ((((((y & 3) << 8) | 0) << 1) ^ (uint16_t)(((((y & 3) << 8) | 0) << 1) + 0xE000)) & ((uint16_t)(((((y & 3) << 8) | 0) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x33FE, 0xC20D53); GUARD_JSR(c, sp_call, 0x33FE); } /* allocate_boss_object_pool_slot */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    bool m_flag;
    bool x_flag;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool overflow1;
    uint8_t data_bank;
    uint16_t direct_page;
    if (carry_ret) {
        m_flag = 0;
        x_flag = 0;
        a_hi1 = a_all >> 8;
        x1 = x_ret;
        y1 = (value7 & 3) | 0xAA20;
        carry1 = carry_ret;
        overflow1 = overflow_ret;
        data_bank = 0x7E;
        direct_page = dp;
    } else {
        uint16_t value10 = BUS16_RDP(c, (uint16_t)(dp + 0xA1));
        uint16_t value11 = BUS16_RDP(c, (uint16_t)(dp + 0x95));
        RAM16_SET(0x002B + x_ret, value11);
        uint16_t value12 = BUS16_RDP(c, (uint16_t)(dp + 0x97));
        RAM16_SET(0x0032 + x_ret, value12);
        uint16_t value13 = BUS16_RDP(c, (uint16_t)(dp + 0x99));
        RAM16_SET(0x00B0 + x_ret, value13);
        uint16_t value14 = BUS16_RDP(c, (uint16_t)(dp + 0x9B));
        RAM16_SET(0x00B2 + x_ret, value14);
        uint16_t value15 = BUS16_RDP(c, (uint16_t)(dp + 0x9F));
        RAM16_SET(0x00B8 + x_ret, value15);
        uint16_t value16 = BUS16_RDP(c, (uint16_t)(dp + 0x9D));
        RAM16_SET(0x00B4 + x_ret, value16);
        RAM8(0x0000 + sp0) = x_ret >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)x_ret;
        r->a = value16;
        r->z = value16 == 0;
        r->n = value16 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x3424, 0xC22476); GUARD_JSR(c, sp_call, 0x3424); } /* load_boss_projectile_graphics_list */
        r->sp += 2;
        uint16_t value17 = BUS16_RDP(c, (uint16_t)(dp + 0x9D));
        uint16_t value18 = BUS16(c, 0xDCE6C1 + (uint16_t)(value17 << 1));
        RAM16_SET(0x00B6 + ((RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1)), value18);
        r->a = value18;
        r->x = 0x0F;
        r->c = value17 & 0x8000;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x3436, 0xC22700); GUARD_JSR(c, sp_call, 0x3436); } /* external */
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        bool m_ret = r->mf;
        bool x_ret3 = r->xf;
        uint16_t a_all3 = r->a;
        uint16_t x_ret4 = r->x;
        uint16_t y_ret2 = r->y;
        bool carry_ret3 = r->c;
        bool overflow_ret3 = r->v;
        m_flag = m_ret;
        x_flag = x_ret3;
        a_hi1 = a_all3 >> 8;
        x1 = x_ret4;
        y1 = y_ret2;
        carry1 = carry_ret3;
        overflow1 = overflow_ret3;
        data_bank = db_ret;
        direct_page = dp_ret;
    }
    r->a = (a_hi1 << 8) | (uint8_t)a;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = m_flag;
    r->xf = x_flag;
    r->db = data_bank;
    r->dp = direct_page;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC233BE, SOM_RTS, "gen", create_boss_projectile_with_graphics_and_palette, 0, L_B | L_X | L_Y | L_C | L_V, 2, 0, 0, 122, 58)
