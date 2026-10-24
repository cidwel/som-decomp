#include "som_c.h"

/* 7E9808 initialize_nine_native_title_particle_sprites_and_random_velocity   [class B, 109 bytes, 54 instructions]
 * Source: src/boot/initialize_nine_native_title_particle_sprites_and_random_velocity.s
 * Entry: M=16 bit X=16 bit DB=$7F D=any.  Callers read: YCZNV.
 */
static void initialize_nine_native_title_particle_sprites_and_random_velocity(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    BUS8_SET(c, (uint16_t)(dp + 0x20), 9);
    BUS8_SET(c, (uint16_t)(dp + 0x22), 0xF3);
    uint8_t a_hi1 = a >> 8;
    uint16_t x1 = x;
    uint16_t y1 = 0x12;
    bool carry1 = carry;
    bool overflow1 = overflow;
    uint8_t data_bank = 0x7F;
    uint16_t direct_page = dp;
    for (;;) {
        RAM8(0x0000 + sp0 - 1) = y1 >> 8;
        RAM8(0x0000 + sp0 - 2) = (uint8_t)y1;
        r->a = (a_hi1 << 8) | 1;
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->z = 0;
        r->n = 0;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0x981B, 0x7EB6D0); GUARD_JSR(c, sp_call, 0x981B); } /* allocate_native_single_sprite_record_prefix */
        r->sp += 3;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        bool overflow_ret = r->v;
        uint8_t value = BUS8_RDP(c, (uint16_t)(dp_ret + 0x22));
        BUS8_SET(c, (db_ret << 0x10) + 6 + x_ret, (uint8_t)(value - 1));
        uint8_t a1;
        if ((uint8_t)(value - 1) != 0xF0) {
            a1 = (uint8_t)(value - 1);
        } else {
            a1 = 0xC0;
        }
        BUS8_SET(c, (uint16_t)(dp_ret + 0x22), a1);
        BUS8_SET(c, (db_ret << 0x10) + 1 + x_ret, 7);
        uint8_t value2 = RAM8(0x0000 + sp0 - 2);
        uint8_t value3 = RAM8(0x0000 + sp0 - 1);
        BUS16_SET(c, (uint16_t)(dp_ret + 0x0C + (uint16_t)(((value3 << 8) | value2) - 2)), x_ret);
        uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x20));
        BUS8_SET(c, (uint16_t)(dp_ret + 0x20), (uint8_t)(value4 - 1));
        a_hi1 = a_all >> 8;
        x1 = x_ret;
        y1 = (uint16_t)(((value3 << 8) | value2) - 2);
        carry1 = (uint8_t)(value - 1) >= 0xF0;
        overflow1 = overflow_ret;
        data_bank = db_ret;
        direct_page = dp_ret;
        if (!((uint8_t)(value4 - 1) != 0)) break;
    }
    BUS8_SET(c, (uint16_t)(direct_page + 6), 0);
    BUS8_SET(c, (uint16_t)(direct_page + 9), 0);
    BUS8_SET(c, direct_page, 0);
    BUS8_SET(c, (uint16_t)(direct_page + 1), 0);
    r->a = (a_hi1 << 8) | 0x80;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = 0;
    r->n = 1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank;
    r->dp = direct_page;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9844, 0x7EC288); GUARD_JSR(c, sp_call, 0x9844); } /* draw_native_random_byte_below_low_byte_limit */
    r->sp += 1;
    if (r->mf != 1) { c->fail = 3; return; }
    uint16_t a_all2 = r->a;
    BUS8_SET(c, (uint16_t)(direct_page + 2), (uint8_t)a_all2 | 0x80);
    BUS8_SET(c, (uint16_t)(direct_page + 3), 0xFF);
    r->a = (a_all2 >> 8 << 8) | 0;
    r->z = 1;
    r->n = 0;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9851, 0x7EC288); GUARD_JSR(c, sp_call, 0x9851); } /* draw_native_random_byte_below_low_byte_limit */
    r->sp += 1;
    if (r->mf != 1) { c->fail = 3; return; }
    uint16_t a_all3 = r->a;
    BUS8_SET(c, (uint16_t)(direct_page + 4), (uint8_t)a_all3);
    r->a = (a_all3 >> 8 << 8) | 2;
    r->z = 0;
    r->n = 0;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9858, 0x7EC288); GUARD_JSR(c, sp_call, 0x9858); } /* draw_native_random_byte_below_low_byte_limit */
    r->sp += 1;
    if (r->mf != 1) { c->fail = 3; return; }
    uint16_t a_all4 = r->a;
    BUS8_SET(c, (uint16_t)(direct_page + 5), (uint8_t)((uint8_t)a_all4 + 0xFC));
    r->a = (a_all4 >> 8 << 8) | 0x40;
    r->c = (uint8_t)a_all4 + 0xFC > 0xFF;
    r->z = 0;
    r->n = 0;
    r->v = (((uint8_t)a_all4 ^ (uint8_t)((uint8_t)a_all4 + 0xFC)) & ((uint8_t)((uint8_t)a_all4 + 0xFC) ^ 0xFC) & 0x80) != 0;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9862, 0x7EC288); GUARD_JSR(c, sp_call, 0x9862); } /* draw_native_random_byte_below_low_byte_limit */
    r->sp += 1;
    uint16_t a_all5 = r->a;
    BUS16_SET(c, (uint16_t)(direct_page + 7), (a_all5 & 0xFF) + 0x20);
    BUS16_SET(c, (uint16_t)(direct_page + 0x0A), 0x0100);
    uint8_t value5 = RAM8(0x0000 + sp0);
    r->c = value5 & 0x01;
    r->z = value5 & 0x02;
    r->n = value5 & 0x80;
    r->v = value5 & 0x40;
    r->mf = value5 & 0x20;
    r->xf = value5 & 0x10;
    r->i = value5 & 0x04;
    r->d = value5 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E9808, SOM_RTS, "gen", initialize_nine_native_title_particle_sprites_and_random_velocity, 0, L_Y | L_C | L_Z | L_N | L_V, 3, 0, 0, 109, 54)
