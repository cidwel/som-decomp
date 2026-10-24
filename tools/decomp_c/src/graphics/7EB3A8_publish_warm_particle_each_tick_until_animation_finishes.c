#include "som_c.h"

/* 7EB3A8 publish_warm_particle_each_tick_until_animation_finishes   [class B, 43 bytes, 24 instructions]
 * Source: src/boot/publish_warm_particle_each_tick_until_animation_finishes.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BCV.
 */
static void publish_warm_particle_each_tick_until_animation_finishes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 5) + 0x2 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), x);
    uint8_t a_hi1 = (uint16_t)(sp0 - 5) >> 8;
    uint16_t x1 = x;
    bool carry1 = carry;
    bool overflow1 = overflow;
    uint8_t data_bank = 0x7E;
    uint16_t direct_page = (uint16_t)(sp0 - 5);
    for (;;) {
        uint16_t value = BUS16_RDP(c, (data_bank << 0x10) + x1);
        r->a = (a_hi1 << 8) | a;
        r->x = value;
        r->y = value;
        r->c = carry1;
        r->z = value == 0;
        r->n = value & 0x8000;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0xB3B9, 0x7EB7B9); GUARD_JSR(c, sp_call, 0xB3B9); } /* publish_native_sprite_record_with_data_bank_7f */
        r->sp += 5;
        if (r->xf != 0) { c->fail = 3; return; }
        r->x = 1;
        r->z = 0;
        r->n = 0;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0xB3BF, 0x7EABE7); GUARD_JSR(c, sp_call, 0xB3BF); } /* receive_with_supplied_delay */
        r->sp += 5;
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret2 = r->db;
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t value2 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 1));
        r->x = value2;
        r->z = value2 == 0;
        r->n = value2 & 0x8000;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0xB3C4, 0x7EB3D3); GUARD_JSR(c, sp_call, 0xB3C4); } /* advance_warm_particle_sprite_and_random_hold_phase */
        r->sp += 5;
        uint16_t dp_ret3 = r->dp;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all3 = r->a;
        bool overflow_ret3 = r->v;
        uint16_t value3 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 1));
        uint8_t value4 = BUS8_RDP(c, (db_ret2 << 0x10) + 2 + value3);
        a_hi1 = a_all3 >> 8;
        x1 = value3;
        carry1 = value4 >= 0x0F;
        overflow1 = overflow_ret3;
        data_bank = db_ret2;
        direct_page = dp_ret3;
        if (!(value4 < 0x0F)) break;
    }
    uint8_t value6 = RAM8(0x0000 + sp0 - 3);
    uint8_t value7 = RAM8(0x0000 + sp0 - 2);
    uint8_t value8 = RAM8(0x0000 + sp0 - 1);
    uint8_t value9 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | value6;
    r->c = value7 & 0x01;
    r->v = value7 & 0x40;
    r->mf = value7 & 0x20;
    r->xf = value7 & 0x10;
    r->db = data_bank;
    r->dp = (value9 << 8) | value8;
    r->i = value7 & 0x04;
    r->d = value7 & 0x08;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EB3A8, SOM_RTS, "gen", publish_warm_particle_each_tick_until_animation_finishes, 0, L_B | L_C | L_V, 5, 1, 0, 43, 24)
