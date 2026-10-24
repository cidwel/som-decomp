#include "som_c.h"

/* C137AD send_spell_entity_actor_positional_sound   [class B, 58 bytes, 38 instructions]
 * Source: src/rom/send_spell_entity_actor_positional_sound.s
 * Documented in docs/actor-cast-entity-graphics-audio.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: CV.
 */
static void send_spell_entity_actor_positional_sound(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp + 4;
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
    RAM8(0x0000 + sp0 - 4) = dp >> 8;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 6) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 7) = a_hi;
    RAM8(0x0000 + sp0 - 8) = (uint8_t)((a_hi << 8) | a);
    uint16_t value = RAM16(0x0000 + sp0 - 8);
    bool m_flag;
    bool x_flag;
    uint8_t data_bank;
    uint16_t direct_page;
    if ((uint8_t)value == 0) {
        m_flag = 1;
        x_flag = 0;
        data_bank = 0x7E;
        direct_page = (uint16_t)(sp0 - 0x0B);
    } else {
        uint8_t a_hi1;
        uint16_t x1;
        bool carry1;
        if (value >> 8 == 0) {
            a_hi1 = RAM8(0x0022 + x);
            x1 = x;
            carry1 = value >> 8 >= 0;
        } else {
            RAM8(0x0000 + sp0 - 0x0B) = (uint8_t)value;
            uint8_t value3 = RAM8(0x0000 + x);
            a_hi1 = RAM8(0x0020 + ((((uint8_t)(value3 << 1) | 0xE0) << 8) | 0));
            x1 = (((uint8_t)(value3 << 1) | 0xE0) << 8) | 0;
            carry1 = value3 & 0x80;
        }
        r->a = (a_hi1 << 8) | (uint8_t)value;
        r->x = x1;
        r->c = carry1;
        r->z = (uint8_t)value == 0;
        r->n = (uint8_t)value & 0x80;
        r->v = (((uint16_t)(sp0 - 9) ^ 2) & ((uint16_t)(sp0 - 9) ^ (uint16_t)(sp0 - 0x0B)) & 0x8000) != 0;
        r->dp = (uint16_t)(sp0 - 0x0B);
        r->sp -= 7;
        { const uint16_t sp_call = r->sp; JSR(c, 0x37DF, 0xC1376A); GUARD_JSR(c, sp_call, 0x37DF); } /* send_spell_entity_positional_sound */
        r->sp += 7;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        bool m_ret = r->mf;
        bool x_ret = r->xf;
        m_flag = m_ret;
        x_flag = x_ret;
        data_bank = db_ret;
        direct_page = dp_ret;
    }
    if (m_flag) {
        uint8_t value9 = RAM8(0x0000 + sp0 - 6);
        uint8_t value10 = RAM8(0x0000 + sp0 - 5);
        uint8_t value11 = RAM8(0x0000 + sp0 - 4);
        r->c = value9 & 0x01;
        r->v = value9 & 0x40;
        r->mf = value9 & 0x20;
        r->xf = value9 & 0x10;
        r->db = data_bank;
        r->dp = (value11 << 8) | value10;
        r->i = value9 & 0x04;
        r->d = value9 & 0x08;
        RETURN_RTS(c);
    } else {
        uint8_t value20 = RAM8(0x0000 + sp0 - 2);
        uint8_t value21 = RAM8(0x0000 + sp0 - 1);
        uint8_t value22 = RAM8(0x0000 + sp0);
        r->c = value20 & 0x01;
        r->v = value20 & 0x40;
        r->mf = value20 & 0x20;
        r->xf = value20 & 0x10;
        r->db = data_bank;
        r->dp = (value22 << 8) | value21;
        r->i = value20 & 0x04;
        r->d = value20 & 0x08;
        r->sp += 4;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC137AD, SOM_RTS, "gen", send_spell_entity_actor_positional_sound, SOM_UNWINDS, L_C | L_V, 12, 1, 0, 58, 38)
