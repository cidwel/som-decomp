#include "som_c.h"

/* C0C9EA load_map_tile_layers_and_camera   [class B, 220 bytes, 113 instructions]
 * Source: src/rom/load_map_tile_layers_and_camera.s
 * Entry: M=16 bit X=16 bit DB=any D=$0000.  Callers read: ABXYCV.
 */
static void load_map_tile_layers_and_camera(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t a = r->a;
    RAM8(0x009C) = 0;
    RAM8(0x00A0) = 0;
    RAM8(0x00B9) = 0;
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC9F4, 0xC0CB90); GUARD_JSR(c, sp_call, 0xC9F4); } /* load_map_piece_list */
    r->mf = 1;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC9F7, 0xC0D037); GUARD_JSR(c, sp_call, 0xC9F7); } /* allocate_map_trigger_tiles */
    uint8_t db_ret2 = r->db;
    uint8_t y_ret2 = r->y;
    bool carry_ret2 = r->c;
    bool overflow_ret2 = r->v;
    RAM16_SET(0x00C8, 0);
    RAM16_SET(0x00CA, 0x4000);
    uint8_t value = RAM8(0x00E8);
    bool m_flag;
    bool x_flag;
    uint8_t a_hi7;
    bool carry4;
    bool overflow4;
    if (!(value & 0x80)) {
        uint16_t value2 = RAM16(0x00DE);
        uint8_t a1;
        uint8_t a_hi1;
        if (!((uint16_t)(((value2 & 0x7F) << 1 << 1 << 1 << 1) - 0x78) & 0x8000)) {
            a1 = (uint8_t)(((value2 & 0x7F) << 1 << 1 << 1 << 1) - 0x78);
            a_hi1 = (uint16_t)(((value2 & 0x7F) << 1 << 1 << 1 << 1) - 0x78) >> 8;
        } else {
            uint16_t value3 = RAM16(0x00C0);
            a1 = (uint8_t)((uint16_t)(((value2 & 0x7F) << 1 << 1 << 1 << 1) - 0x78) + value3 + ((value2 & 0x7F) << 1 << 1 << 1 << 1 >= 0x78));
            a_hi1 = (uint16_t)((uint16_t)(((value2 & 0x7F) << 1 << 1 << 1 << 1) - 0x78) + value3 + ((value2 & 0x7F) << 1 << 1 << 1 << 1 >= 0x78)) >> 8;
        }
        RAM16_SET(0x00A8, (a_hi1 << 8) | a1);
        RAM8(0x0000 + sp0) = a_hi1;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)((a_hi1 << 8) | a1);
        RAM16_SET(0x0088, ((a_hi1 << 8) | a1) & 0xFFF0);
        uint8_t value4 = RAM8(0x00B9);
        uint8_t a_hi3;
        if (value4 == 0) {
            a_hi3 = a_hi1;
        } else {
            uint8_t a2 = (uint8_t)((a_hi1 << 8) | a1);
            uint8_t a_hi2 = a_hi1;
            for (;;) {
                uint16_t value5 = RAM16(0x00C4);
                if (((a_hi2 << 8) | a2) >= value5) {
                    uint8_t a2_next = (uint8_t)(((a_hi2 << 8) | a2) - value5 - (((a_hi2 << 8) | a2) >= value5 ^ 1));
                    uint8_t a_hi2_next = (uint16_t)(((a_hi2 << 8) | a2) - value5 - (((a_hi2 << 8) | a2) >= value5 ^ 1)) >> 8;
                    a2 = a2_next;
                    a_hi2 = a_hi2_next;
                    continue;
                }
                break;
            }
            RAM16_SET(0x00AC, (a_hi2 << 8) | a2);
            RAM16_SET(0x008C, ((a_hi2 << 8) | a2) & 0xFFF0);
            a_hi3 = (((a_hi2 << 8) | a2) & 0xFFF0) >> 8;
        }
        uint8_t value6 = RAM8(0x00DF);
        RAM8(0x00BF) = (RAM8(0x00BF) >> 1) | ((value6 & 1) << 7);
        uint8_t a3;
        uint8_t a_hi4;
        bool carry1;
        bool overflow1;
        if (!((uint16_t)(((((a_hi3 << 8) | (value6 >> 1)) & 0x7F) << 1 << 1 << 1 << 1) - 0x68) & 0x8000)) {
            a3 = (uint8_t)(((((a_hi3 << 8) | (value6 >> 1)) & 0x7F) << 1 << 1 << 1 << 1) - 0x68);
            a_hi4 = (uint16_t)(((((a_hi3 << 8) | (value6 >> 1)) & 0x7F) << 1 << 1 << 1 << 1) - 0x68) >> 8;
            carry1 = (((a_hi3 << 8) | (value6 >> 1)) & 0x7F) << 1 << 1 << 1 << 1 >= 0x68;
            overflow1 = ((((((a_hi3 << 8) | (value6 >> 1)) & 0x7F) << 1 << 1 << 1 << 1) ^ 0x68) & (((((a_hi3 << 8) | (value6 >> 1)) & 0x7F) << 1 << 1 << 1 << 1) ^ (uint16_t)(((((a_hi3 << 8) | (value6 >> 1)) & 0x7F) << 1 << 1 << 1 << 1) - 0x68)) & 0x8000) != 0;
        } else {
            uint16_t value8 = RAM16(0x00C2);
            a3 = (uint8_t)((uint16_t)(((((a_hi3 << 8) | (value6 >> 1)) & 0x7F) << 1 << 1 << 1 << 1) - 0x68) + value8 + ((((a_hi3 << 8) | (value6 >> 1)) & 0x7F) << 1 << 1 << 1 << 1 >= 0x68));
            a_hi4 = (uint16_t)((uint16_t)(((((a_hi3 << 8) | (value6 >> 1)) & 0x7F) << 1 << 1 << 1 << 1) - 0x68) + value8 + ((((a_hi3 << 8) | (value6 >> 1)) & 0x7F) << 1 << 1 << 1 << 1 >= 0x68)) >> 8;
            carry1 = (uint16_t)(((((a_hi3 << 8) | (value6 >> 1)) & 0x7F) << 1 << 1 << 1 << 1) - 0x68) + value8 + ((((a_hi3 << 8) | (value6 >> 1)) & 0x7F) << 1 << 1 << 1 << 1 >= 0x68) > 0xFFFF;
            overflow1 = (((uint16_t)(((((a_hi3 << 8) | (value6 >> 1)) & 0x7F) << 1 << 1 << 1 << 1) - 0x68) ^ (uint16_t)((uint16_t)(((((a_hi3 << 8) | (value6 >> 1)) & 0x7F) << 1 << 1 << 1 << 1) - 0x68) + value8 + ((((a_hi3 << 8) | (value6 >> 1)) & 0x7F) << 1 << 1 << 1 << 1 >= 0x68))) & (value8 ^ (uint16_t)((uint16_t)(((((a_hi3 << 8) | (value6 >> 1)) & 0x7F) << 1 << 1 << 1 << 1) - 0x68) + value8 + ((((a_hi3 << 8) | (value6 >> 1)) & 0x7F) << 1 << 1 << 1 << 1 >= 0x68))) & 0x8000) != 0;
        }
        RAM16_SET(0x00AA, (a_hi4 << 8) | a3);
        RAM8(0x0000 + sp0) = a_hi4;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)((a_hi4 << 8) | a3);
        RAM16_SET(0x008A, ((a_hi4 << 8) | a3) & 0xFFF0);
        uint8_t value9 = RAM8(0x00B9);
        uint8_t a_hi6;
        bool carry3;
        bool overflow3;
        if (value9 == 0) {
            a_hi6 = a_hi4;
            carry3 = carry1;
            overflow3 = overflow1;
        } else {
            uint8_t a4 = (uint8_t)((a_hi4 << 8) | a3);
            uint8_t a_hi5 = a_hi4;
            bool carry2 = carry1;
            bool overflow2 = overflow1;
            for (;;) {
                uint16_t value10 = RAM16(0x00C6);
                if (((a_hi5 << 8) | a4) >= value10) {
                    uint8_t a4_next = (uint8_t)(((a_hi5 << 8) | a4) - value10 - (((a_hi5 << 8) | a4) >= value10 ^ 1));
                    uint8_t a_hi5_next = (uint16_t)(((a_hi5 << 8) | a4) - value10 - (((a_hi5 << 8) | a4) >= value10 ^ 1)) >> 8;
                    bool carry2_next = ((a_hi5 << 8) | a4) - value10 >= (((a_hi5 << 8) | a4) >= value10 ^ 1);
                    bool overflow2_next = ((((a_hi5 << 8) | a4) ^ value10) & (((a_hi5 << 8) | a4) ^ (uint16_t)(((a_hi5 << 8) | a4) - value10 - (((a_hi5 << 8) | a4) >= value10 ^ 1))) & 0x8000) != 0;
                    a4 = a4_next;
                    a_hi5 = a_hi5_next;
                    carry2 = carry2_next;
                    overflow2 = overflow2_next;
                    continue;
                }
                carry2 = ((a_hi5 << 8) | a4) >= value10;
                break;
            }
            RAM16_SET(0x00AE, (a_hi5 << 8) | a4);
            RAM16_SET(0x008E, ((a_hi5 << 8) | a4) & 0xFFF0);
            a_hi6 = (((a_hi5 << 8) | a4) & 0xFFF0) >> 8;
            carry3 = carry2;
            overflow3 = overflow2;
        }
        m_flag = 0;
        x_flag = 1;
        a_hi7 = a_hi6;
        carry4 = carry3;
        overflow4 = overflow3;
    } else {
        r->a = 0x4000;
        r->x = value;
        r->z = value == 0;
        r->n = value & 0x80;
        r->mf = 0;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0xCA0D, 0x01CD17); GUARD_JSL(c, sp_call, 0xCA0D); } /* restore_saved_map_camera */
        uint16_t a_all3 = r->a;
        m_flag = 1;
        x_flag = 0;
        a_hi7 = a_all3 >> 8;
        carry4 = carry_ret2;
        overflow4 = overflow_ret2;
    }
    RAM16_SET(0x00B0, RAM16(0x00A8) & 0x0F);
    RAM16_SET(0x00B4, RAM16(0x00AC) & 0x0F);
    uint16_t value13 = RAM16(0x00AA);
    RAM8(0x0000 + sp0) = value13 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)value13;
    RAM16_SET(0x00B2, value13 & 0x0F);
    RAM8(0x0000 + sp0 - 2) = 0;
    RAM8(0x0000 + sp0 - 3) = value13 & 0x0F;
    uint16_t value14 = RAM16(0x00AE);
    RAM8(0x0000 + sp0 - 4) = value14 >> 8;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)value14;
    RAM16_SET(0x00B6, value14 & 0x0F);
    RAM8(0x0000 + sp0 - 6) = 0;
    RAM8(0x0000 + sp0 - 7) = value14 & 0x0F;
    uint8_t a_hi8 = 0;
    uint8_t x1 = 0x10;
    uint8_t y1 = y_ret2;
    bool carry5 = carry4;
    bool overflow5 = overflow4;
    uint8_t data_bank = db_ret2;
    for (;;) {
        RAM8(0x0000 + sp0 - 8) = x1;
        uint8_t value15 = RAM8(0x00B9);
        uint8_t x2;
        if (value15 == 0) {
            x2 = 2;
        } else {
            x2 = 0x0A;
        }
        RAM8(0x002E) = x2;
        RAM8(0x002F) = 0;
        r->a = (a_hi8 << 8) | (uint8_t)a;
        r->x = 0;
        r->y = value15;
        r->c = carry5;
        r->z = 1;
        r->n = 0;
        r->v = overflow5;
        r->mf = 0;
        r->xf = 1;
        r->db = data_bank;
        r->dp = 0;
        r->sp -= 9;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCAA8, 0xC0C7C3); GUARD_JSR(c, sp_call, 0xCAA8); } /* prepare_pending_map_rows */
        r->sp += 9;
        uint8_t db_ret3 = r->db;
        r->mf = 1;
        r->sp -= 9;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCAAB, 0xC0C692); GUARD_JSR(c, sp_call, 0xCAAB); } /* upload_pending_map_tile_rows_and_columns */
        r->sp += 9;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 9;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCAAE, 0xC0CAC6); GUARD_JSR(c, sp_call, 0xCAAE); } /* advance_map_tile_row_coordinates */
        r->sp += 9;
        bool m_ret = r->mf;
        uint16_t a_all6 = r->a;
        uint8_t y_ret4 = r->y;
        bool carry_ret4 = r->c;
        bool overflow_ret5 = r->v;
        uint8_t value16 = RAM8(0x0000 + sp0 - 8);
        if (m_ret != 0) { c->fail = 3; return; }
        a_hi8 = a_all6 >> 8;
        x1 = (uint8_t)(value16 - 1);
        y1 = y_ret4;
        carry5 = carry_ret4;
        overflow5 = overflow_ret5;
        data_bank = db_ret3;
        if (!(x1 != 0)) break;
    }
    RAM16_SET(0x00B6, (RAM8(0x0000 + sp0 - 6) << 8) | RAM8(0x0000 + sp0 - 7));
    RAM16_SET(0x00AE, (RAM8(0x0000 + sp0 - 4) << 8) | RAM8(0x0000 + sp0 - 5));
    RAM16_SET(0x00B2, (RAM8(0x0000 + sp0 - 2) << 8) | RAM8(0x0000 + sp0 - 3));
    uint8_t value23 = RAM8(0x0000 + sp0 - 1);
    uint8_t value24 = RAM8(0x0000 + sp0);
    RAM16_SET(0x00AA, (value24 << 8) | value23);
    r->a = (value24 << 8) | value23;
    r->x = x1;
    r->y = y1;
    r->c = carry5;
    r->v = overflow5;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0C9EA, SOM_RTS, "gen", load_map_tile_layers_and_camera, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 9, 0, 0, 220, 113)
