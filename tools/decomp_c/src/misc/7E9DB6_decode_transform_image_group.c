#include "som_c.h"

/* 7E9DB6 decode_transform_image_group   [class B, 63 bytes, 27 instructions]
 * Source: src/boot/decode_transform_image_group.s
 * Entry: M=16 bit X=16 bit DB=$7F D=$0300.  Callers read: XYCZNV.
 */
static void decode_transform_image_group(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    uint16_t value = RAM16(0x10110);
    r->a = 0x1600;
    r->x = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    r->dp = 0x1600;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9DC0, 0x7E9D0E); GUARD_JSR(c, sp_call, 0x9DC0); } /* decode_scale_transform_image_block */
    r->sp += 2;
    r->a = 0x1700;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->dp = 0x1700;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9DC7, 0x7E9D0E); GUARD_JSR(c, sp_call, 0x9DC7); } /* decode_scale_transform_image_block */
    r->sp += 2;
    r->a = 0x1800;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->dp = 0x1800;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9DCE, 0x7E9D0E); GUARD_JSR(c, sp_call, 0x9DCE); } /* decode_scale_transform_image_block */
    r->sp += 2;
    r->a = 0x1900;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->dp = 0x1900;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9DD5, 0x7E9D0E); GUARD_JSR(c, sp_call, 0x9DD5); } /* decode_scale_transform_image_block */
    r->sp += 2;
    uint8_t db_ret4 = r->db;
    bool x_ret7 = r->xf;
    uint16_t x_ret8 = r->x;
    uint16_t y_ret4 = r->y;
    if (x_ret7) {
        BUS8_SET(c, (db_ret4 << 0x10) + 0x0110, (uint8_t)x_ret8);
        uint8_t value2 = BUS8_RDP(c, (db_ret4 << 0x10) + 0x0112);
        r->a = 0x1A00;
        r->x = value2;
        r->y = (uint8_t)y_ret4;
        r->z = value2 == 0;
        r->n = value2 & 0x80;
        r->mf = 0;
        r->xf = 1;
        r->dp = 0x1A00;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9DE2, 0x7E9D0E); GUARD_JSR(c, sp_call, 0x9DE2); } /* decode_scale_transform_image_block */
        r->sp += 2;
        uint8_t db_ret5 = r->db;
        bool x_ret9 = r->xf;
        uint16_t x_ret10 = r->x;
        uint16_t y_ret5 = r->y;
        if (x_ret9) {
            BUS8_SET(c, (db_ret5 << 0x10) + 0x0112, (uint8_t)x_ret10);
            uint8_t value3 = BUS8_RDP(c, (db_ret5 << 0x10) + 0x0114);
            r->a = 0x1B00;
            r->x = value3;
            r->y = (uint8_t)y_ret5;
            r->z = value3 == 0;
            r->n = value3 & 0x80;
            r->mf = 0;
            r->xf = 1;
            r->dp = 0x1B00;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9DEF, 0x7E9D0E); GUARD_JSR(c, sp_call, 0x9DEF); } /* decode_scale_transform_image_block */
            r->sp += 2;
            uint8_t db_ret6 = r->db;
            bool x_ret11 = r->xf;
            uint16_t x_ret12 = r->x;
            uint16_t y_ret6 = r->y;
            if (x_ret11) {
                BUS8_SET(c, (db_ret6 << 0x10) + 0x0114, (uint8_t)x_ret12);
                uint8_t value4 = RAM8(0x0000 + sp0 - 1);
                uint8_t value5 = RAM8(0x0000 + sp0);
                r->x = (uint8_t)x_ret12;
                r->y = (uint8_t)y_ret6;
                r->z = ((value5 << 8) | value4) == 0;
                r->n = ((value5 << 8) | value4) & 0x8000;
                r->mf = 0;
                r->xf = 1;
                r->dp = (value5 << 8) | value4;
                RETURN_RTS(c);
            } else {
                BUS16_SET(c, (db_ret6 << 0x10) + 0x0114, x_ret12);
                uint8_t value6 = RAM8(0x0000 + sp0 - 1);
                uint8_t value7 = RAM8(0x0000 + sp0);
                r->z = ((value7 << 8) | value6) == 0;
                r->n = ((value7 << 8) | value6) & 0x8000;
                r->mf = 0;
                r->xf = 0;
                r->dp = (value7 << 8) | value6;
                RETURN_RTS(c);
            }
        } else {
            BUS16_SET(c, (db_ret5 << 0x10) + 0x0112, x_ret10);
            uint16_t value8 = BUS16_RDP(c, (db_ret5 << 0x10) + 0x0114);
            r->a = 0x1B00;
            r->x = value8;
            r->z = value8 == 0;
            r->n = value8 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            r->dp = 0x1B00;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9DEF, 0x7E9D0E); GUARD_JSR(c, sp_call, 0x9DEF); } /* decode_scale_transform_image_block */
            r->sp += 2;
            uint8_t db_ret7 = r->db;
            bool x_ret13 = r->xf;
            uint16_t x_ret14 = r->x;
            uint16_t y_ret7 = r->y;
            if (x_ret13) {
                BUS8_SET(c, (db_ret7 << 0x10) + 0x0114, (uint8_t)x_ret14);
                uint8_t value9 = RAM8(0x0000 + sp0 - 1);
                uint8_t value10 = RAM8(0x0000 + sp0);
                r->x = (uint8_t)x_ret14;
                r->y = (uint8_t)y_ret7;
                r->z = ((value10 << 8) | value9) == 0;
                r->n = ((value10 << 8) | value9) & 0x8000;
                r->mf = 0;
                r->xf = 1;
                r->dp = (value10 << 8) | value9;
                RETURN_RTS(c);
            } else {
                BUS16_SET(c, (db_ret7 << 0x10) + 0x0114, x_ret14);
                uint8_t value11 = RAM8(0x0000 + sp0 - 1);
                uint8_t value12 = RAM8(0x0000 + sp0);
                r->z = ((value12 << 8) | value11) == 0;
                r->n = ((value12 << 8) | value11) & 0x8000;
                r->mf = 0;
                r->xf = 0;
                r->dp = (value12 << 8) | value11;
                RETURN_RTS(c);
            }
        }
    } else {
        BUS16_SET(c, (db_ret4 << 0x10) + 0x0110, x_ret8);
        uint16_t value13 = BUS16_RDP(c, (db_ret4 << 0x10) + 0x0112);
        r->a = 0x1A00;
        r->x = value13;
        r->z = value13 == 0;
        r->n = value13 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        r->dp = 0x1A00;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9DE2, 0x7E9D0E); GUARD_JSR(c, sp_call, 0x9DE2); } /* decode_scale_transform_image_block */
        r->sp += 2;
        uint8_t db_ret8 = r->db;
        bool x_ret15 = r->xf;
        uint16_t x_ret16 = r->x;
        uint16_t y_ret8 = r->y;
        if (x_ret15) {
            BUS8_SET(c, (db_ret8 << 0x10) + 0x0112, (uint8_t)x_ret16);
            uint8_t value14 = BUS8_RDP(c, (db_ret8 << 0x10) + 0x0114);
            r->a = 0x1B00;
            r->x = value14;
            r->y = (uint8_t)y_ret8;
            r->z = value14 == 0;
            r->n = value14 & 0x80;
            r->mf = 0;
            r->xf = 1;
            r->dp = 0x1B00;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9DEF, 0x7E9D0E); GUARD_JSR(c, sp_call, 0x9DEF); } /* decode_scale_transform_image_block */
            r->sp += 2;
            uint8_t db_ret9 = r->db;
            bool x_ret17 = r->xf;
            uint16_t x_ret18 = r->x;
            uint16_t y_ret9 = r->y;
            if (x_ret17) {
                BUS8_SET(c, (db_ret9 << 0x10) + 0x0114, (uint8_t)x_ret18);
                uint8_t value15 = RAM8(0x0000 + sp0 - 1);
                uint8_t value16 = RAM8(0x0000 + sp0);
                r->x = (uint8_t)x_ret18;
                r->y = (uint8_t)y_ret9;
                r->z = ((value16 << 8) | value15) == 0;
                r->n = ((value16 << 8) | value15) & 0x8000;
                r->mf = 0;
                r->xf = 1;
                r->dp = (value16 << 8) | value15;
                RETURN_RTS(c);
            } else {
                BUS16_SET(c, (db_ret9 << 0x10) + 0x0114, x_ret18);
                uint8_t value17 = RAM8(0x0000 + sp0 - 1);
                uint8_t value18 = RAM8(0x0000 + sp0);
                r->z = ((value18 << 8) | value17) == 0;
                r->n = ((value18 << 8) | value17) & 0x8000;
                r->mf = 0;
                r->xf = 0;
                r->dp = (value18 << 8) | value17;
                RETURN_RTS(c);
            }
        } else {
            BUS16_SET(c, (db_ret8 << 0x10) + 0x0112, x_ret16);
            uint16_t value19 = BUS16_RDP(c, (db_ret8 << 0x10) + 0x0114);
            r->a = 0x1B00;
            r->x = value19;
            r->z = value19 == 0;
            r->n = value19 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            r->dp = 0x1B00;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9DEF, 0x7E9D0E); GUARD_JSR(c, sp_call, 0x9DEF); } /* decode_scale_transform_image_block */
            r->sp += 2;
            uint8_t db_ret10 = r->db;
            bool x_ret19 = r->xf;
            uint16_t x_ret20 = r->x;
            uint16_t y_ret10 = r->y;
            if (x_ret19) {
                BUS8_SET(c, (db_ret10 << 0x10) + 0x0114, (uint8_t)x_ret20);
                uint8_t value20 = RAM8(0x0000 + sp0 - 1);
                uint8_t value21 = RAM8(0x0000 + sp0);
                r->x = (uint8_t)x_ret20;
                r->y = (uint8_t)y_ret10;
                r->z = ((value21 << 8) | value20) == 0;
                r->n = ((value21 << 8) | value20) & 0x8000;
                r->mf = 0;
                r->xf = 1;
                r->dp = (value21 << 8) | value20;
                RETURN_RTS(c);
            } else {
                BUS16_SET(c, (db_ret10 << 0x10) + 0x0114, x_ret20);
                uint8_t value22 = RAM8(0x0000 + sp0 - 1);
                uint8_t value23 = RAM8(0x0000 + sp0);
                r->z = ((value23 << 8) | value22) == 0;
                r->n = ((value23 << 8) | value22) & 0x8000;
                r->mf = 0;
                r->xf = 0;
                r->dp = (value23 << 8) | value22;
                RETURN_RTS(c);
            }
        }
    }
}
SOM_REGISTER(0x7E9DB6, SOM_RTS, "gen", decode_transform_image_group, 0, L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 0, 0, 63, 27)
