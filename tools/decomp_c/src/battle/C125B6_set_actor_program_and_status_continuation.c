#include "som_c.h"

/* C125B6 set_actor_program_and_status_continuation   [class B, 134 bytes, 69 instructions]
 * Source: src/rom/set_actor_program_and_status_continuation.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCV.
 */
static void set_actor_program_and_status_continuation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    if ((uint32_t)(uint16_t)(sp0 - 7) + 0x4 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a_hi;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)((a_hi << 8) | a);
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    RAM8(0x0000 + sp0 - 7) = db;
    RAM8(0x0000 + sp0 - 8) = (uint8_t)value;
    RAM8(0x0000 + sp0 - 9) = 0x7E;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 7), value);
    RAM16_SET(0x0003 + (uint16_t)(sp0 - 7), (x & 0x1FFF) | 0xE000);
    RAM16_SET(0x01AC + ((x & 0x1FFF) | 0xE000), 0xFFFF);
    uint16_t value2 = RAM16(0x0001 + (uint16_t)(sp0 - 7));
    BUS16_SET(c, 0x004202, ((uint8_t)value2 << 8) | 0x10);
    RAM8(0x0000 + sp0 - 8) = (uint8_t)value2;
    RAM8(0x0000 + sp0 - 9) = (uint8_t)(((uint8_t)value2 << 8) | 0x10);
    uint16_t value3 = BUS16(c, 0x004216);
    uint16_t value4 = BUS16(c, 0xD00009 + value3);
    RAM16_SET(0x0144 + ((x & 0x1FFF) | 0xE000), value4);
    RAM16_SET(0x0146 + ((x & 0x1FFF) | 0xE000), 0);
    RAM16_SET(0x014C + ((x & 0x1FFF) | 0xE000), 0);
    RAM8(0x014E + ((x & 0x1FFF) | 0xE000)) = 0;
    RAM8(0x014F + ((x & 0x1FFF) | 0xE000)) = 0;
    uint16_t value5 = RAM16(0x0001 + (uint16_t)(sp0 - 7));
    bool m_flag2;
    bool x_flag2;
    uint8_t a_hi2;
    uint16_t x2;
    bool carry2;
    bool overflow2;
    if ((uint16_t)(value5 - 0x80) >= 3) {
        m_flag2 = 0;
        x_flag2 = 0;
        a_hi2 = (uint16_t)(value5 - 0x80) >> 8;
        x2 = value3;
        carry2 = (uint16_t)(value5 - 0x80) >= 3;
        overflow2 = ((value5 ^ 0x80) & (value5 ^ (uint16_t)(value5 - 0x80)) & 0x8000) != 0;
    } else {
        uint16_t value6 = RAM16(0x0190 + ((x & 0x1FFF) | 0xE000));
        bool m_flag;
        bool x_flag;
        uint8_t a_hi1;
        uint16_t x1;
        bool carry1;
        bool overflow1;
        if ((value6 & 0x5760) == 0) {
            m_flag = 0;
            x_flag = 0;
            a_hi1 = (value6 & 0x5760) >> 8;
            x1 = value3;
            carry1 = (uint16_t)(value5 - 0x80) >= 3;
            overflow1 = ((value5 ^ 0x80) & (value5 ^ (uint16_t)(value5 - 0x80)) & 0x8000) != 0;
        } else {
            r->a = 1;
            r->x = (x & 0x1FFF) | 0xE000;
            r->c = (uint16_t)(value5 - 0x80) >= 3;
            r->z = 0;
            r->n = 0;
            r->v = ((value5 ^ 0x80) & (value5 ^ (uint16_t)(value5 - 0x80)) & 0x8000) != 0;
            r->mf = 0;
            r->db = 0x7E;
            r->dp = (uint16_t)(sp0 - 7);
            r->sp -= 8;
            { const uint16_t sp_call = r->sp; JSR(c, 0x2628, 0xC12698); GUARD_JSR(c, sp_call, 0x2628); } /* call_actor_status_program */
            r->sp += 8;
            bool m_ret = r->mf;
            bool x_ret = r->xf;
            uint16_t a_all = r->a;
            uint16_t x_ret2 = r->x;
            bool carry_ret = r->c;
            bool overflow_ret = r->v;
            m_flag = m_ret;
            x_flag = x_ret;
            a_hi1 = a_all >> 8;
            x1 = x_ret2;
            carry1 = carry_ret;
            overflow1 = overflow_ret;
        }
        m_flag2 = m_flag;
        x_flag2 = x_flag;
        a_hi2 = a_hi1;
        x2 = x1;
        carry2 = carry1;
        overflow2 = overflow1;
    }
    if (m_flag2) {
        uint8_t value7 = RAM8(0x0001 + (uint16_t)(sp0 - 7));
        if (x_flag2) {
            uint8_t value8 = RAM8(0x0003 + (uint16_t)(sp0 - 7));
            r->a = (a_hi2 << 8) | value7;
            r->x = (uint8_t)x2;
            r->y = value8;
            r->c = carry2;
            r->z = value8 == 0;
            r->n = value8 & 0x80;
            r->v = overflow2;
            r->mf = 1;
            r->xf = 1;
            r->db = 0x7E;
            r->dp = (uint16_t)(sp0 - 7);
            r->sp -= 8;
            { const uint16_t sp_call = r->sp; JSR(c, 0x262F, 0xC12599); GUARD_JSR(c, sp_call, 0x262F); } /* rebuild_hero_for_actor_program */
            r->sp += 8;
            uint16_t a_all2 = r->a;
            uint8_t value9 = RAM8(0x0000 + sp0 - 7);
            RAM8(0x0000 + sp0 - 3) = (uint8_t)a_all2;
            uint8_t value13 = RAM8(0x0000 + sp0 - 3);
            uint8_t value14 = RAM8(0x0000 + sp0 - 2);
            uint8_t value15 = RAM8(0x0000 + sp0 - 1);
            uint8_t value16 = RAM8(0x0000 + sp0);
            r->a = (a_all2 >> 8 << 8) | value13;
            r->c = value14 & 0x01;
            r->v = value14 & 0x40;
            r->mf = value14 & 0x20;
            r->xf = value14 & 0x10;
            r->db = value9;
            r->dp = (value16 << 8) | value15;
            r->i = value14 & 0x04;
            r->d = value14 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            uint16_t value17 = RAM16(0x0003 + (uint16_t)(sp0 - 7));
            r->a = (a_hi2 << 8) | value7;
            r->x = x2;
            r->y = value17;
            r->c = carry2;
            r->z = value17 == 0;
            r->n = value17 & 0x8000;
            r->v = overflow2;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = (uint16_t)(sp0 - 7);
            r->sp -= 8;
            { const uint16_t sp_call = r->sp; JSR(c, 0x262F, 0xC12599); GUARD_JSR(c, sp_call, 0x262F); } /* rebuild_hero_for_actor_program */
            r->sp += 8;
            uint16_t a_all3 = r->a;
            uint8_t value18 = RAM8(0x0000 + sp0 - 7);
            RAM8(0x0000 + sp0 - 3) = (uint8_t)a_all3;
            uint8_t value22 = RAM8(0x0000 + sp0 - 3);
            uint8_t value23 = RAM8(0x0000 + sp0 - 2);
            uint8_t value24 = RAM8(0x0000 + sp0 - 1);
            uint8_t value25 = RAM8(0x0000 + sp0);
            r->a = (a_all3 >> 8 << 8) | value22;
            r->c = value23 & 0x01;
            r->v = value23 & 0x40;
            r->mf = value23 & 0x20;
            r->xf = value23 & 0x10;
            r->db = value18;
            r->dp = (value25 << 8) | value24;
            r->i = value23 & 0x04;
            r->d = value23 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    } else {
        uint16_t value26 = RAM16(0x0001 + (uint16_t)(sp0 - 7));
        if (x_flag2) {
            uint8_t value27 = RAM8(0x0003 + (uint16_t)(sp0 - 7));
            r->a = value26;
            r->x = (uint8_t)x2;
            r->y = value27;
            r->c = carry2;
            r->z = value27 == 0;
            r->n = value27 & 0x80;
            r->v = overflow2;
            r->mf = 0;
            r->xf = 1;
            r->db = 0x7E;
            r->dp = (uint16_t)(sp0 - 7);
            r->sp -= 8;
            { const uint16_t sp_call = r->sp; JSR(c, 0x262F, 0xC12599); GUARD_JSR(c, sp_call, 0x262F); } /* rebuild_hero_for_actor_program */
            r->sp += 8;
            uint16_t a_all4 = r->a;
            uint8_t value28 = RAM8(0x0000 + sp0 - 7);
            RAM8(0x0000 + sp0 - 3) = (uint8_t)a_all4;
            uint8_t value32 = RAM8(0x0000 + sp0 - 3);
            uint8_t value33 = RAM8(0x0000 + sp0 - 2);
            uint8_t value34 = RAM8(0x0000 + sp0 - 1);
            uint8_t value35 = RAM8(0x0000 + sp0);
            r->a = (a_all4 >> 8 << 8) | value32;
            r->c = value33 & 0x01;
            r->v = value33 & 0x40;
            r->mf = value33 & 0x20;
            r->xf = value33 & 0x10;
            r->db = value28;
            r->dp = (value35 << 8) | value34;
            r->i = value33 & 0x04;
            r->d = value33 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            uint16_t value36 = RAM16(0x0003 + (uint16_t)(sp0 - 7));
            r->a = value26;
            r->x = x2;
            r->y = value36;
            r->c = carry2;
            r->z = value36 == 0;
            r->n = value36 & 0x8000;
            r->v = overflow2;
            r->mf = 0;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = (uint16_t)(sp0 - 7);
            r->sp -= 8;
            { const uint16_t sp_call = r->sp; JSR(c, 0x262F, 0xC12599); GUARD_JSR(c, sp_call, 0x262F); } /* rebuild_hero_for_actor_program */
            r->sp += 8;
            uint16_t a_all5 = r->a;
            uint8_t value37 = RAM8(0x0000 + sp0 - 7);
            RAM8(0x0000 + sp0 - 3) = (uint8_t)a_all5;
            uint8_t value41 = RAM8(0x0000 + sp0 - 3);
            uint8_t value42 = RAM8(0x0000 + sp0 - 2);
            uint8_t value43 = RAM8(0x0000 + sp0 - 1);
            uint8_t value44 = RAM8(0x0000 + sp0);
            r->a = (a_all5 >> 8 << 8) | value41;
            r->c = value42 & 0x01;
            r->v = value42 & 0x40;
            r->mf = value42 & 0x20;
            r->xf = value42 & 0x10;
            r->db = value37;
            r->dp = (value44 << 8) | value43;
            r->i = value42 & 0x04;
            r->d = value42 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    }
}
SOM_REGISTER(0xC125B6, SOM_RTS, "gen", set_actor_program_and_status_continuation, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 10, 1, 0, 134, 69)
