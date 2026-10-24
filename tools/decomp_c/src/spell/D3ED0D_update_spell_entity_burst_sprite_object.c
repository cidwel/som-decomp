#include "som_c.h"

/* D3ED0D update_spell_entity_burst_sprite_object   [class B, 82 bytes, 49 instructions]
 * Source: src/rom/update_spell_entity_burst_sprite_object.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void update_spell_entity_burst_sprite_object(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 0x0A) + 0x7 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 0x0A) = 0x7E;
    RAM8(0x0000 + sp0 - 0x0B) = 0x7E;
    RAM16_SET(0x0004 + (uint16_t)(sp0 - 0x0A), x);
    RAM8(0x0001 + (uint16_t)(sp0 - 0x0A)) = 5;
    RAM8(0x0002 + (uint16_t)(sp0 - 0x0A)) = 0;
    uint8_t a1 = 5;
    uint8_t a_hi1 = (uint16_t)(sp0 - 0x0A) >> 8;
    uint16_t y1 = x;
    bool carry1 = (uint16_t)(sp0 - 3) >= 7;
    bool overflow1 = (((uint16_t)(sp0 - 3) ^ 7) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 0x0A)) & 0x8000) != 0;
    uint8_t data_bank = 0x7E;
    for (;;) {
        RAM16_SET(0x0006 + (uint16_t)(sp0 - 0x0A), y1);
        uint16_t value = RAM16(0x0004 + (uint16_t)(sp0 - 0x0A));
        r->a = (a_hi1 << 8) | a1;
        r->x = value;
        r->y = y1;
        r->c = carry1;
        r->z = value == 0;
        r->n = value & 0x8000;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank;
        r->dp = (uint16_t)(sp0 - 0x0A);
        r->sp -= 11;
        { const uint16_t sp_call = r->sp; JSR(c, 0xED2E, 0xD3EC44); GUARD_JSR(c, sp_call, 0xED2E); } /* advance_spell_entity_burst_child */
        r->sp += 11;
        uint8_t db_ret = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all = r->a;
        if ((uint8_t)a_all == 0) {
            uint16_t value2 = RAM16(0x0006 + (uint16_t)(sp0 - 0x0A));
            RAM8(0x0001 + (uint16_t)(sp0 - 0x0A))--;
            if (RAM8(0x0001 + (uint16_t)(sp0 - 0x0A)) != 0) {
                a1 = (uint8_t)(value2 + 0x10);
                a_hi1 = (uint16_t)(value2 + 0x10) >> 8;
                y1 = (uint16_t)(value2 + 0x10);
                carry1 = value2 + 0x10 > 0xFFFF;
                overflow1 = ((value2 ^ (uint16_t)(value2 + 0x10)) & ((uint16_t)(value2 + 0x10) ^ 0x10) & 0x8000) != 0;
                data_bank = db_ret;
                continue;
            }
            a1 = (uint8_t)(value2 + 0x10);
            a_hi1 = (uint16_t)(value2 + 0x10) >> 8;
            y1 = (uint16_t)(value2 + 0x10);
            carry1 = value2 + 0x10 > 0xFFFF;
            overflow1 = ((value2 ^ (uint16_t)(value2 + 0x10)) & ((uint16_t)(value2 + 0x10) ^ 0x10) & 0x8000) != 0;
            data_bank = db_ret;
            break;
        }
        RAM8(0x0002 + (uint16_t)(sp0 - 0x0A))++;
        uint16_t value3 = RAM16(0x0006 + (uint16_t)(sp0 - 0x0A));
        RAM8(0x0001 + (uint16_t)(sp0 - 0x0A))--;
        if (RAM8(0x0001 + (uint16_t)(sp0 - 0x0A)) != 0) {
            a1 = (uint8_t)(value3 + 0x10);
            a_hi1 = (uint16_t)(value3 + 0x10) >> 8;
            y1 = (uint16_t)(value3 + 0x10);
            carry1 = value3 + 0x10 > 0xFFFF;
            overflow1 = ((value3 ^ (uint16_t)(value3 + 0x10)) & ((uint16_t)(value3 + 0x10) ^ 0x10) & 0x8000) != 0;
            data_bank = db_ret;
            continue;
        }
        a1 = (uint8_t)(value3 + 0x10);
        a_hi1 = (uint16_t)(value3 + 0x10) >> 8;
        y1 = (uint16_t)(value3 + 0x10);
        carry1 = value3 + 0x10 > 0xFFFF;
        overflow1 = ((value3 ^ (uint16_t)(value3 + 0x10)) & ((uint16_t)(value3 + 0x10) ^ 0x10) & 0x8000) != 0;
        data_bank = db_ret;
        break;
    }
    uint8_t value5 = BUS8_RDP(c, (data_bank << 0x10) + 0x54 + RAM16(0x0004 + (uint16_t)(sp0 - 0x0A)));
    uint8_t value6 = RAM8(0x0002 + (uint16_t)(sp0 - 0x0A));
    uint8_t a2;
    if ((value5 | value6) == 0) {
        a2 = value5 | value6;
    } else {
        a2 = 0xFF;
    }
    uint8_t value7 = RAM8(0x0000 + sp0 - 0x0A);
    RAM16_SET(0x0000 + sp0 - 4, (a_hi1 << 8) | a2);
    uint8_t value10 = RAM8(0x0000 + sp0 - 2);
    uint8_t value11 = RAM8(0x0000 + sp0 - 1);
    uint8_t value12 = RAM8(0x0000 + sp0);
    r->mf = value10 & 0x20;
    r->xf = value10 & 0x10;
    r->db = value7;
    r->dp = (value12 << 8) | value11;
    r->i = value10 & 0x04;
    r->d = value10 & 0x08;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD3ED0D, SOM_RTS, "gen", update_spell_entity_burst_sprite_object, 0, 0, 12, 1, 0, 82, 49)
