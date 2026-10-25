#include "som_c.h"

/* D3F835 initialize_spell_entity_trail_sprites   [class B, 141 bytes, 70 instructions]
 * Source: src/rom/initialize_spell_entity_trail_sprites.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$01CC.  Callers read: nothing.
 */
static void initialize_spell_entity_trail_sprites(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x01CC) { c->fail = 3; return; }
    if (r->d) { c->fail = 3; return; } /* binary ADC/SBC: entered with the decimal flag clear */
    const uint16_t sp0 = r->sp;
    uint64_t loop_guard = 0;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 0x0D) + 0xA > 0x1FFF) { c->fail = 3; return; }
    uint8_t a_hi_f882 = 0;
    uint8_t x_f882 = 0;
    uint16_t direct_page_f882 = 0;
    uint8_t data_bank_f882 = 0;
    uint8_t a_hi_f8822 = 0;
    uint16_t x_f8822 = 0;
    uint16_t direct_page_f8822 = 0;
    uint8_t data_bank_f8822 = 0;
    RAM8(0x0000 + sp0) = 1;
    RAM8(0x0000 + sp0 - 1) = 0xCC;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 0x0D) = 0x7E;
    RAM8(0x0000 + sp0 - 0x0E) = 0x7E;
    RAM16_SET(0x0002 + (uint16_t)(sp0 - 0x0D), y);
    r->a = ((uint16_t)(sp0 - 0x0D) >> 8 << 8) | 0x7E;
    r->x = 0xFD4A;
    r->c = (uint16_t)(sp0 - 3) >= 0x0A;
    r->z = 0;
    r->n = 1;
    r->v = (((uint16_t)(sp0 - 3) ^ 0x0A) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 0x0D)) & 0x8000) != 0;
    r->dp = (uint16_t)(sp0 - 0x0D);
    r->sp -= 14;
    { const uint16_t sp_call = r->sp; JSL(c, 0xF851, 0xC12E90); GUARD_JSL(c, sp_call, 0xF851); } /* construct_spell_graphics_audio_resources_long */
    r->sp += 14;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t x_ret2 = r->x;
    if (x_ret) {
        RAM8(0x0007 + (uint16_t)(sp0 - 0x0D)) = (uint8_t)x_ret2;
        uint8_t value = RAM8(0x0002 + (uint16_t)(sp0 - 0x0D));
        RAM16_SET(0x001A + value, (uint8_t)x_ret2);
        RAM16_SET(0x002A + value, 0);
        RAM16_SET(0x001C + value, 0x3711);
        RAM16_SET(0x001E + value, 0x345A);
        RAM8(0x0001 + (uint16_t)(sp0 - 0x0D)) = RAM8(0x0027 + value);
        RAM8(0x0006 + (uint16_t)(sp0 - 0x0D)) = RAM8(0x0024 + value);
        RAM8(0x0009 + (uint16_t)(sp0 - 0x0D)) = RAM8(0x0022 + value);
        RAM8(0x000A + (uint16_t)(sp0 - 0x0D)) = RAM8(0x0020 + value);
        a_hi_f882 = 0x34;
        x_f882 = value;
        direct_page_f882 = (uint16_t)(sp0 - 0x0D);
        data_bank_f882 = 0x7E;
        goto shared_F882;
    } else {
        RAM16_SET(0x0007 + (uint16_t)(sp0 - 0x0D), x_ret2);
        uint16_t value6 = RAM16(0x0002 + (uint16_t)(sp0 - 0x0D));
        RAM16_SET(0x001A + value6, x_ret2);
        RAM16_SET(0x002A + value6, 0);
        RAM16_SET(0x001C + value6, 0x3711);
        RAM16_SET(0x001E + value6, 0x345A);
        RAM8(0x0001 + (uint16_t)(sp0 - 0x0D)) = RAM8(0x0027 + value6);
        RAM8(0x0006 + (uint16_t)(sp0 - 0x0D)) = RAM8(0x0024 + value6);
        RAM8(0x0009 + (uint16_t)(sp0 - 0x0D)) = RAM8(0x0022 + value6);
        RAM8(0x000A + (uint16_t)(sp0 - 0x0D)) = RAM8(0x0020 + value6);
        a_hi_f8822 = 0x34;
        x_f8822 = value6;
        direct_page_f8822 = (uint16_t)(sp0 - 0x0D);
        data_bank_f8822 = 0x7E;
        goto shared_F882_1;
    }
    shared_F882:;
    LOOP_GUARD(loop_guard);
    BUS8_SET(c, (uint16_t)(direct_page_f882 + 4), x_f882);
    uint8_t value11 = BUS8_RDP(c, (uint16_t)(direct_page_f882 + 6));
    BUS8_SET(c, (uint16_t)(direct_page_f882 + 6), (uint8_t)(value11 + 0x40));
    uint8_t value12 = BUS8_RDP(c, (data_bank_f882 << 0x10) + x_f882);
    uint8_t value13 = BUS8_RDP(c, (uint16_t)(direct_page_f882 + 7));
    uint8_t value14 = BUS8_RDP(c, (uint16_t)(direct_page_f882 + 9));
    r->a = ((uint8_t)(value11 + 0x40) << 8) | value12;
    r->x = value13;
    r->y = value14;
    r->c = value11 + 0x40 > 0xFF;
    r->z = value14 == 0;
    r->n = value14 & 0x80;
    r->v = ((value11 ^ (uint8_t)(value11 + 0x40)) & ((uint8_t)(value11 + 0x40) ^ 0x40) & 0x80) != 0;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_f882;
    r->dp = direct_page_f882;
    r->sp -= 14;
    { const uint16_t sp_call = r->sp; JSR(c, 0xF895, 0xD3F8C2); GUARD_JSR(c, sp_call, 0xF895); } /* construct_spell_entity_trail_sprite_object */
    r->sp += 14;
    uint8_t db_ret = r->db;
    bool x_ret3 = r->xf;
    uint16_t x_ret4 = r->x;
    if (x_ret3) {
        uint8_t value15 = BUS8_RDP(c, (uint16_t)(direct_page_f882 + 4));
        BUS16_SET(c, (db_ret << 0x10) + 2 + value15, (uint8_t)x_ret4);
        BUS16_SET(c, (db_ret << 0x10) + 4 + value15, 0x480B);
        BUS16_SET(c, (db_ret << 0x10) + 6 + value15, 0x4806);
        uint8_t value16 = BUS8_RDP(c, (uint16_t)(direct_page_f882 + 1));
        BUS8_SET(c, (uint16_t)(direct_page_f882 + 1), (uint8_t)(value16 - 1));
        if ((uint8_t)(value16 - 1) != 0) {
            a_hi_f882 = value15 + 8 >> 8;
            x_f882 = (uint8_t)(value15 + 8);
            data_bank_f882 = db_ret;
            goto shared_F882;
        }
        uint8_t value17 = RAM8(0x0000 + sp0 - 0x0D);
        uint8_t value18 = RAM8(0x0000 + sp0 - 2);
        uint8_t value19 = RAM8(0x0000 + sp0 - 1);
        uint8_t value20 = RAM8(0x0000 + sp0);
        r->mf = value18 & 0x20;
        r->xf = value18 & 0x10;
        r->db = value17;
        r->dp = (value20 << 8) | value19;
        r->i = value18 & 0x04;
        r->d = value18 & 0x08;
        RETURN_RTS(c);
    } else {
        uint16_t value21 = BUS16_RDP(c, (uint16_t)(direct_page_f882 + 4));
        BUS16_SET(c, (db_ret << 0x10) + 2 + value21, x_ret4);
        BUS16_SET(c, (db_ret << 0x10) + 4 + value21, 0x480B);
        BUS16_SET(c, (db_ret << 0x10) + 6 + value21, 0x4806);
        uint8_t value22 = BUS8_RDP(c, (uint16_t)(direct_page_f882 + 1));
        BUS8_SET(c, (uint16_t)(direct_page_f882 + 1), (uint8_t)(value22 - 1));
        if ((uint8_t)(value22 - 1) != 0) {
            a_hi_f8822 = (uint16_t)(value21 + 8) >> 8;
            x_f8822 = (uint16_t)(value21 + 8);
            direct_page_f8822 = direct_page_f882;
            data_bank_f8822 = db_ret;
            goto shared_F882_1;
        }
        uint8_t value23 = RAM8(0x0000 + sp0 - 0x0D);
        uint8_t value24 = RAM8(0x0000 + sp0 - 2);
        uint8_t value25 = RAM8(0x0000 + sp0 - 1);
        uint8_t value26 = RAM8(0x0000 + sp0);
        r->mf = value24 & 0x20;
        r->xf = value24 & 0x10;
        r->db = value23;
        r->dp = (value26 << 8) | value25;
        r->i = value24 & 0x04;
        r->d = value24 & 0x08;
        RETURN_RTS(c);
    }
    shared_F882_1:;
    LOOP_GUARD(loop_guard);
    BUS16_SET(c, (uint16_t)(direct_page_f8822 + 4), x_f8822);
    uint8_t value27 = BUS8_RDP(c, (uint16_t)(direct_page_f8822 + 6));
    BUS8_SET(c, (uint16_t)(direct_page_f8822 + 6), (uint8_t)(value27 + 0x40));
    uint8_t value28 = BUS8_RDP(c, (data_bank_f8822 << 0x10) + x_f8822);
    uint16_t value29 = BUS16_RDP(c, (uint16_t)(direct_page_f8822 + 7));
    uint16_t value30 = BUS16_RDP(c, (uint16_t)(direct_page_f8822 + 9));
    r->a = ((uint8_t)(value27 + 0x40) << 8) | value28;
    r->x = value29;
    r->y = value30;
    r->c = value27 + 0x40 > 0xFF;
    r->z = value30 == 0;
    r->n = value30 & 0x8000;
    r->v = ((value27 ^ (uint8_t)(value27 + 0x40)) & ((uint8_t)(value27 + 0x40) ^ 0x40) & 0x80) != 0;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_f8822;
    r->dp = direct_page_f8822;
    r->sp -= 14;
    { const uint16_t sp_call = r->sp; JSR(c, 0xF895, 0xD3F8C2); GUARD_JSR(c, sp_call, 0xF895); } /* construct_spell_entity_trail_sprite_object */
    r->sp += 14;
    uint8_t db_ret2 = r->db;
    bool x_ret5 = r->xf;
    uint16_t x_ret6 = r->x;
    if (x_ret5) {
        uint8_t value31 = BUS8_RDP(c, (uint16_t)(direct_page_f8822 + 4));
        BUS16_SET(c, (db_ret2 << 0x10) + 2 + value31, (uint8_t)x_ret6);
        BUS16_SET(c, (db_ret2 << 0x10) + 4 + value31, 0x480B);
        BUS16_SET(c, (db_ret2 << 0x10) + 6 + value31, 0x4806);
        uint8_t value32 = BUS8_RDP(c, (uint16_t)(direct_page_f8822 + 1));
        BUS8_SET(c, (uint16_t)(direct_page_f8822 + 1), (uint8_t)(value32 - 1));
        if ((uint8_t)(value32 - 1) != 0) {
            a_hi_f882 = value31 + 8 >> 8;
            x_f882 = (uint8_t)(value31 + 8);
            direct_page_f882 = direct_page_f8822;
            data_bank_f882 = db_ret2;
            goto shared_F882;
        }
        uint8_t value33 = RAM8(0x0000 + sp0 - 0x0D);
        uint8_t value34 = RAM8(0x0000 + sp0 - 2);
        uint8_t value35 = RAM8(0x0000 + sp0 - 1);
        uint8_t value36 = RAM8(0x0000 + sp0);
        r->mf = value34 & 0x20;
        r->xf = value34 & 0x10;
        r->db = value33;
        r->dp = (value36 << 8) | value35;
        r->i = value34 & 0x04;
        r->d = value34 & 0x08;
        RETURN_RTS(c);
    } else {
        uint16_t value37 = BUS16_RDP(c, (uint16_t)(direct_page_f8822 + 4));
        BUS16_SET(c, (db_ret2 << 0x10) + 2 + value37, x_ret6);
        BUS16_SET(c, (db_ret2 << 0x10) + 4 + value37, 0x480B);
        BUS16_SET(c, (db_ret2 << 0x10) + 6 + value37, 0x4806);
        uint8_t value38 = BUS8_RDP(c, (uint16_t)(direct_page_f8822 + 1));
        BUS8_SET(c, (uint16_t)(direct_page_f8822 + 1), (uint8_t)(value38 - 1));
        if ((uint8_t)(value38 - 1) != 0) {
            a_hi_f8822 = (uint16_t)(value37 + 8) >> 8;
            x_f8822 = (uint16_t)(value37 + 8);
            data_bank_f8822 = db_ret2;
            goto shared_F882_1;
        }
        uint8_t value39 = RAM8(0x0000 + sp0 - 0x0D);
        uint8_t value40 = RAM8(0x0000 + sp0 - 2);
        uint8_t value41 = RAM8(0x0000 + sp0 - 1);
        uint8_t value42 = RAM8(0x0000 + sp0);
        r->mf = value40 & 0x20;
        r->xf = value40 & 0x10;
        r->db = value39;
        r->dp = (value42 << 8) | value41;
        r->i = value40 & 0x04;
        r->d = value40 & 0x08;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xD3F835, SOM_RTS, "gen", initialize_spell_entity_trail_sprites, 0, 0, 15, 0, 0, 141, 70)
