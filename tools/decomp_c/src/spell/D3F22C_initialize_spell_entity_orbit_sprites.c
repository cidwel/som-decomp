#include "som_c.h"

/* D3F22C initialize_spell_entity_orbit_sprites   [class B, 91 bytes, 46 instructions]
 * Source: src/rom/initialize_spell_entity_orbit_sprites.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void initialize_spell_entity_orbit_sprites(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 7) + 0x4 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 7) = 0x7E;
    RAM8(0x0000 + sp0 - 8) = 0x7E;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 7), y);
    r->a = ((uint16_t)(sp0 - 7) >> 8 << 8) | 0x7E;
    r->x = 0xFC32;
    r->c = (uint16_t)(sp0 - 3) >= 4;
    r->z = 0;
    r->n = 1;
    r->v = (((uint16_t)(sp0 - 3) ^ 4) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 7)) & 0x8000) != 0;
    r->mf = 0;
    r->dp = (uint16_t)(sp0 - 7);
    r->sp -= 8;
    { const uint16_t sp_call = r->sp; JSL(c, 0xF248, 0xC12E90); GUARD_JSL(c, sp_call, 0xF248); } /* construct_spell_graphics_audio_resources_long */
    r->sp += 8;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret = r->y;
    if (x_ret) {
        RAM8(0x0003 + (uint16_t)(sp0 - 7)) = (uint8_t)x_ret2;
        uint8_t value = RAM8(0x0001 + (uint16_t)(sp0 - 7));
        RAM16_SET(0x001A + value, (uint8_t)x_ret2);
        RAM16_SET(0x002A + value, 0xEB);
        RAM16_SET(0x001C + value, 0x3711);
        RAM16_SET(0x001E + value, 0x345A);
        uint16_t value2 = RAM16(0x0000 + value);
        uint8_t value3 = RAM8(0x0003 + (uint16_t)(sp0 - 7));
        r->a = value2;
        r->x = value3;
        r->y = (uint8_t)y_ret;
        r->z = value3 == 0;
        r->n = value3 & 0x80;
        r->xf = 1;
        r->sp -= 8;
        { const uint16_t sp_call = r->sp; JSR(c, 0xF26A, 0xD3F287); GUARD_JSR(c, sp_call, 0xF26A); } /* construct_spell_entity_orbit_sprite_object */
        r->sp += 8;
        uint8_t db_ret = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        bool x_ret3 = r->xf;
        uint16_t x_ret4 = r->x;
        if (x_ret3) {
            uint8_t value4 = RAM8(0x0001 + (uint16_t)(sp0 - 7));
            BUS16_SET(c, (db_ret << 0x10) + 2 + value4, (uint8_t)x_ret4);
            BUS16_SET(c, (db_ret << 0x10) + 4 + value4, 0x2EE7);
            BUS16_SET(c, (db_ret << 0x10) + 6 + value4, 0x2EE2);
            uint8_t value5 = RAM8(0x0000 + sp0 - 7);
            uint8_t value10 = RAM8(0x0000 + sp0 - 2);
            uint8_t value11 = RAM8(0x0000 + sp0 - 1);
            uint8_t value12 = RAM8(0x0000 + sp0);
            r->mf = value10 & 0x20;
            r->xf = value10 & 0x10;
            r->db = value5;
            r->dp = (value12 << 8) | value11;
            r->i = value10 & 0x04;
            r->d = value10 & 0x08;
            RETURN_RTS(c);
        } else {
            uint16_t value13 = RAM16(0x0001 + (uint16_t)(sp0 - 7));
            BUS16_SET(c, (db_ret << 0x10) + 2 + value13, x_ret4);
            BUS16_SET(c, (db_ret << 0x10) + 4 + value13, 0x2EE7);
            BUS16_SET(c, (db_ret << 0x10) + 6 + value13, 0x2EE2);
            uint8_t value14 = RAM8(0x0000 + sp0 - 7);
            uint8_t value19 = RAM8(0x0000 + sp0 - 2);
            uint8_t value20 = RAM8(0x0000 + sp0 - 1);
            uint8_t value21 = RAM8(0x0000 + sp0);
            r->mf = value19 & 0x20;
            r->xf = value19 & 0x10;
            r->db = value14;
            r->dp = (value21 << 8) | value20;
            r->i = value19 & 0x04;
            r->d = value19 & 0x08;
            RETURN_RTS(c);
        }
    } else {
        RAM16_SET(0x0003 + (uint16_t)(sp0 - 7), x_ret2);
        uint16_t value22 = RAM16(0x0001 + (uint16_t)(sp0 - 7));
        RAM16_SET(0x001A + value22, x_ret2);
        RAM16_SET(0x002A + value22, 0xEB);
        RAM16_SET(0x001C + value22, 0x3711);
        RAM16_SET(0x001E + value22, 0x345A);
        uint16_t value23 = RAM16(0x0000 + value22);
        uint16_t value24 = RAM16(0x0003 + (uint16_t)(sp0 - 7));
        r->a = value23;
        r->x = value24;
        r->z = value24 == 0;
        r->n = value24 & 0x8000;
        r->xf = 0;
        r->sp -= 8;
        { const uint16_t sp_call = r->sp; JSR(c, 0xF26A, 0xD3F287); GUARD_JSR(c, sp_call, 0xF26A); } /* construct_spell_entity_orbit_sprite_object */
        r->sp += 8;
        uint8_t db_ret2 = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        bool x_ret5 = r->xf;
        uint16_t x_ret6 = r->x;
        if (x_ret5) {
            uint8_t value25 = RAM8(0x0001 + (uint16_t)(sp0 - 7));
            BUS16_SET(c, (db_ret2 << 0x10) + 2 + value25, (uint8_t)x_ret6);
            BUS16_SET(c, (db_ret2 << 0x10) + 4 + value25, 0x2EE7);
            BUS16_SET(c, (db_ret2 << 0x10) + 6 + value25, 0x2EE2);
            uint8_t value26 = RAM8(0x0000 + sp0 - 7);
            uint8_t value31 = RAM8(0x0000 + sp0 - 2);
            uint8_t value32 = RAM8(0x0000 + sp0 - 1);
            uint8_t value33 = RAM8(0x0000 + sp0);
            r->mf = value31 & 0x20;
            r->xf = value31 & 0x10;
            r->db = value26;
            r->dp = (value33 << 8) | value32;
            r->i = value31 & 0x04;
            r->d = value31 & 0x08;
            RETURN_RTS(c);
        } else {
            uint16_t value34 = RAM16(0x0001 + (uint16_t)(sp0 - 7));
            BUS16_SET(c, (db_ret2 << 0x10) + 2 + value34, x_ret6);
            BUS16_SET(c, (db_ret2 << 0x10) + 4 + value34, 0x2EE7);
            BUS16_SET(c, (db_ret2 << 0x10) + 6 + value34, 0x2EE2);
            uint8_t value35 = RAM8(0x0000 + sp0 - 7);
            uint8_t value40 = RAM8(0x0000 + sp0 - 2);
            uint8_t value41 = RAM8(0x0000 + sp0 - 1);
            uint8_t value42 = RAM8(0x0000 + sp0);
            r->mf = value40 & 0x20;
            r->xf = value40 & 0x10;
            r->db = value35;
            r->dp = (value42 << 8) | value41;
            r->i = value40 & 0x04;
            r->d = value40 & 0x08;
            RETURN_RTS(c);
        }
    }
}
SOM_REGISTER(0xD3F22C, SOM_RTS, "gen", initialize_spell_entity_orbit_sprites, 0, 0, 9, 1, 0, 91, 46)
