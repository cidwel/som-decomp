#include "som_c.h"

/* D3FD11 update_spell_entity_trail_sprite_object   [class C, 46 bytes, 23 instructions]
 * Source: src/rom/update_spell_entity_trail_sprite_object.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: nothing.
 */
static void update_spell_entity_trail_sprite_object(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM16_SET(0x0152 + x, (uint16_t)(RAM16(0x0152 + x) - 1));
    bool m_flag;
    uint8_t a_hi1;
    uint16_t x1;
    bool carry1;
    bool zero1;
    bool negative1;
    bool overflow1;
    uint8_t data_bank;
    uint16_t direct_page;
    if (RAM16(0x0152 + x) != 0) {
        m_flag = 0;
        a_hi1 = a_hi;
        x1 = x;
        carry1 = carry;
        zero1 = RAM16(0x0152 + x) == 0;
        negative1 = RAM16(0x0152 + x) & 0x8000;
        overflow1 = overflow;
        data_bank = 0x7E;
        direct_page = dp;
    } else {
        RAM16_SET(0x0152 + x, 2);
        uint16_t value = RAM16(0x0154 + x);
        r->a = (uint16_t)(value << 1);
        r->x = (uint16_t)(value << 1);
        r->y = x;
        r->c = value & 0x8000;
        r->z = (uint16_t)(value << 1) == 0;
        r->n = (uint16_t)(value << 1) & 0x8000;
        r->mf = 0;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp;
        switch ((uint16_t)(value << 1)) {
        case 0x0000: JSR(c, 0xFD28, 0xD3FC44); GUARD_JSR(c, sp_call, 0xFD28); break; /* advance_spell_entity_trail_target_motion */
        case 0x0002: JSR(c, 0xFD28, 0xD3FCA7); GUARD_JSR(c, sp_call, 0xFD28); break; /* publish_spell_entity_trail_arrival_sound_and_first_color */
        case 0x0004: JSR(c, 0xFD28, 0xD3FCD3); GUARD_JSR(c, sp_call, 0xFD28); break; /* publish_spell_entity_trail_second_arrival_color */
        case 0x0006: JSR(c, 0xFD28, 0xD3FCF5); GUARD_JSR(c, sp_call, 0xFD28); break; /* complete_spell_entity_trail_arrival_state */
        default: JSR(c, 0xFD28, 0xD30000 | BUS16(c, 0xD30000 + (uint16_t)(0xFD05 + ((uint16_t)(value << 1))))); GUARD_JSR(c, sp_call, 0xFD28);
        }
        }
        r->sp += 3;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        bool m_ret = r->mf;
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        bool carry_ret = r->c;
        bool zero_ret = r->z;
        bool negative_ret = r->n;
        bool overflow_ret = r->v;
        m_flag = m_ret;
        a_hi1 = a_all >> 8;
        x1 = x_ret;
        carry1 = carry_ret;
        zero1 = zero_ret;
        negative1 = negative_ret;
        overflow1 = overflow_ret;
        data_bank = db_ret;
        direct_page = dp_ret;
    }
    RAM8(0x0000 + sp0 - 3) = x1 >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x1;
    r->x = x1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = m_flag;
    r->db = data_bank;
    r->dp = direct_page;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xFD2C, 0xD3F9B8); GUARD_JSR(c, sp_call, 0xFD2C); } /* project_spell_entity_trail_sprite_frames */
    r->sp += 5;
    uint8_t db_ret2 = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t value4 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x0154 + ((RAM8(0x0000 + sp0 - 3) << 8) | RAM8(0x0000 + sp0 - 4)));
    uint8_t a1;
    uint8_t a_hi2;
    if ((value4 & 4) == 0) {
        a1 = value4 & 4;
        a_hi2 = 0;
    } else {
        a1 = 0xFF;
        a_hi2 = 0xFF;
    }
    uint8_t value5 = RAM8(0x0000 + sp0 - 2);
    uint8_t value6 = RAM8(0x0000 + sp0 - 1);
    uint8_t value7 = RAM8(0x0000 + sp0);
    r->mf = value5 & 0x20;
    r->xf = value5 & 0x10;
    r->dp = (value7 << 8) | value6;
    r->i = value5 & 0x04;
    r->d = value5 & 0x08;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD3FD11, SOM_RTS, "gen", update_spell_entity_trail_sprite_object, 0, 0, 5, 1, 0, 46, 23)
