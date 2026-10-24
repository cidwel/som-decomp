#include "som_c.h"

/* C116F4 actor_script_random_bounded_nibble   [class B, 41 bytes, 24 instructions]
 * Source: src/rom/actor_script_random_bounded_nibble.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: AYCZNV.
 */
static void actor_script_random_bounded_nibble(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 4) + 0x1 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7E;
    RAM8(0x0000 + sp0 - 4) = y >> 8;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)y;
    uint16_t value = RAM16(0x0144 + y);
    uint8_t value2 = BUS8(c, 0xD04F16 + value);
    if ((value2 & 0x0F) == 0) {
        RAM8(0x0000 + sp0 - 3) = value2 & 0x0F;
        SET_A8(r, RAM8(0x0000 + sp0 - 3));
        r->z = dp == 0;
        r->n = dp & 0x8000;
        RETURN_RTS(c);
    }
    RAM8(0x0001 + (uint16_t)(sp0 - 4)) = value2 & 0x0F;
    uint8_t a1 = value2 & 0x0F;
    uint8_t a_hi1 = (uint16_t)(sp0 - 4) >> 8;
    uint16_t x1 = value;
    uint16_t y1 = y;
    bool carry1 = carry;
    bool zero1 = (value2 & 0x0F) == 0;
    bool negative1 = value2 & 0x0F & 0x80;
    bool overflow1 = overflow;
    uint8_t data_bank = 0x7E;
    uint16_t direct_page = (uint16_t)(sp0 - 4);
    for (;;) {
        r->a = (a_hi1 << 8) | a1;
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->z = zero1;
        r->n = negative1;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        r->sp -= 6;
        { const uint16_t sp_call = r->sp; JSR(c, 0x170D, 0xC126FB); GUARD_JSR(c, sp_call, 0x170D); } /* actor_random_byte_with_preserved_bank */
        r->sp += 6;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        uint16_t y_ret = r->y;
        bool overflow_ret = r->v;
        uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
        if (((uint8_t)a_all & 0x0F) == value4) {
            a1 = (uint8_t)a_all & 0x0F;
            a_hi1 = a_all >> 8;
            x1 = x_ret;
            y1 = y_ret;
            carry1 = ((uint8_t)a_all & 0x0F) >= value4;
            zero1 = ((uint8_t)a_all & 0x0F) == value4;
            negative1 = (uint8_t)(((uint8_t)a_all & 0x0F) - value4) & 0x80;
            overflow1 = overflow_ret;
            data_bank = db_ret;
            direct_page = dp_ret;
            break;
        }
        if (((uint8_t)a_all & 0x0F) >= value4) {
            a1 = (uint8_t)a_all & 0x0F;
            a_hi1 = a_all >> 8;
            x1 = x_ret;
            y1 = y_ret;
            carry1 = ((uint8_t)a_all & 0x0F) >= value4;
            zero1 = ((uint8_t)a_all & 0x0F) == value4;
            negative1 = (uint8_t)(((uint8_t)a_all & 0x0F) - value4) & 0x80;
            overflow1 = overflow_ret;
            data_bank = db_ret;
            direct_page = dp_ret;
            continue;
        }
        a1 = (uint8_t)a_all & 0x0F;
        a_hi1 = a_all >> 8;
        x1 = x_ret;
        y1 = y_ret;
        carry1 = ((uint8_t)a_all & 0x0F) >= value4;
        zero1 = ((uint8_t)a_all & 0x0F) == value4;
        negative1 = (uint8_t)(((uint8_t)a_all & 0x0F) - value4) & 0x80;
        overflow1 = overflow_ret;
        data_bank = db_ret;
        direct_page = dp_ret;
        break;
    }
    uint8_t value5 = RAM8(0x0000 + sp0 - 5);
    uint8_t value6 = RAM8(0x0000 + sp0 - 4);
    RAM8(0x0000 + sp0 - 3) = a1;
    uint8_t value7 = RAM8(0x0000 + sp0 - 3);
    uint8_t value8 = RAM8(0x0000 + sp0 - 2);
    uint8_t value9 = RAM8(0x0000 + sp0 - 1);
    uint8_t value10 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | value7;
    r->y = (value6 << 8) | value5;
    r->c = value8 & 0x01;
    r->z = ((value10 << 8) | value9) == 0;
    r->n = ((value10 << 8) | value9) & 0x8000;
    r->v = value8 & 0x40;
    r->mf = value8 & 0x20;
    r->xf = value8 & 0x10;
    r->db = data_bank;
    r->dp = (value10 << 8) | value9;
    r->i = value8 & 0x04;
    r->d = value8 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC116F4, SOM_RTS, "gen", actor_script_random_bounded_nibble, 0, L_A | L_Y | L_C | L_Z | L_N | L_V, 6, 1, 0, 41, 24)
