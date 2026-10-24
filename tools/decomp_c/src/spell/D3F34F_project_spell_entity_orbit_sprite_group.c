#include "som_c.h"

/* D3F34F project_spell_entity_orbit_sprite_group   [class B, 73 bytes, 47 instructions]
 * Source: src/rom/project_spell_entity_orbit_sprite_group.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: nothing.
 */
static void project_spell_entity_orbit_sprite_group(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
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
    if ((uint32_t)(uint16_t)(sp0 - 6) + 0x3 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7E;
    RAM8(0x0000 + sp0 - 4) = a_hi;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)((a_hi << 8) | a);
    RAM8(0x0000 + sp0 - 4) = x >> 8;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)x;
    uint8_t data_bank2;
    uint16_t direct_page2;
    if ((((a_hi << 8) | a) & 0xFF) >= 5) {
        data_bank2 = 0x7E;
        direct_page2 = (uint16_t)(sp0 - 6);
    } else {
        RAM8(0x0000 + sp0 - 6) = x >> 8;
        RAM8(0x0000 + sp0 - 7) = (uint8_t)x;
        uint16_t value = RAM16(0x0008 + x);
        RAM8(0x0000 + sp0 - 8) = value >> 8;
        RAM8(0x0000 + sp0 - 9) = (uint8_t)value;
        uint16_t value2 = RAM16(0x000A + x);
        RAM8(0x0000 + sp0 - 0x0A) = value2 >> 8;
        RAM8(0x0000 + sp0 - 0x0B) = (uint8_t)value2;
        RAM8(0x0001 + (uint16_t)(sp0 - 6)) = 4;
        uint8_t a1 = 4;
        uint8_t a_hi1 = value2 >> 8;
        uint16_t x1 = ((((a_hi << 8) | a) & 0xFF) << 1 << 1 << 1) + 0x0442;
        uint16_t y1 = x;
        bool carry1 = (uint16_t)(((((a_hi << 8) | a) & 0xFF) << 1 << 1 << 1) + 0xFC42) >= 0xF800;
        bool zero1 = 0;
        bool negative1 = 0;
        bool overflow1 = (((uint16_t)(((((a_hi << 8) | a) & 0xFF) << 1 << 1 << 1) + 0xFC42) ^ 0xF800) & ((uint16_t)(((((a_hi << 8) | a) & 0xFF) << 1 << 1 << 1) + 0xFC42) ^ ((((a_hi << 8) | a) & 0xFF) << 1 << 1 << 1) + 0x0442) & 0x8000) != 0;
        uint8_t data_bank = 0x7E;
        uint16_t direct_page = (uint16_t)(sp0 - 6);
        for (;;) {
            BUS16_SET(c, (uint16_t)(direct_page + 2), y1);
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
            r->sp -= 12;
            { const uint16_t sp_call = r->sp; JSL(c, 0xF382, 0xC12E94); GUARD_JSL(c, sp_call, 0xF382); } /* project_packed_spell_entity_sprite_record_long */
            r->sp += 12;
            uint16_t dp_ret = r->dp;
            uint8_t db_ret = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all = r->a;
            uint16_t x_ret = r->x;
            bool carry_ret = r->c;
            bool overflow_ret = r->v;
            uint16_t value3 = BUS16_RDP(c, (uint16_t)(dp_ret + 2));
            uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
            BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value4 - 1));
            a1 = (uint8_t)a_all;
            a_hi1 = a_all >> 8;
            x1 = x_ret;
            y1 = (uint16_t)(value3 + 2);
            carry1 = carry_ret;
            zero1 = (uint8_t)(value4 - 1) == 0;
            negative1 = (uint8_t)(value4 - 1) & 0x80;
            overflow1 = overflow_ret;
            data_bank = db_ret;
            direct_page = dp_ret;
            if (!((uint8_t)(value4 - 1) != 0)) break;
        }
        data_bank2 = data_bank;
        direct_page2 = direct_page;
    }
    uint8_t value14 = RAM8(0x0000 + sp0 - 2);
    uint8_t value15 = RAM8(0x0000 + sp0 - 1);
    uint8_t value16 = RAM8(0x0000 + sp0);
    r->mf = value14 & 0x20;
    r->xf = value14 & 0x10;
    r->db = data_bank2;
    r->dp = (value16 << 8) | value15;
    r->i = value14 & 0x04;
    r->d = value14 & 0x08;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD3F34F, SOM_RTS, "gen", project_spell_entity_orbit_sprite_group, 0, 0, 12, 1, 0, 73, 47)
