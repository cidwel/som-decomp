#include "som_c.h"

/* 7E93F4 enter_warm_graphics_resource_constructor   [class B, 105 bytes, 49 instructions]
 * Source: src/boot/enter_warm_graphics_resource_constructor.s
 * Entry: M=16 bit X=16 bit DB=$7F D=$02E4.  Callers read: XYCZNV.
 */
static void enter_warm_graphics_resource_constructor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    if (r->dp != 0x02E4) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 7) + 0x4 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 2;
    RAM8(0x0000 + sp0 - 1) = 0xE4;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    r->a = 0x82;
    r->x = 0x2E;
    r->c = (uint16_t)(sp0 - 3) >= 4;
    r->z = 0;
    r->n = 0;
    r->v = (((uint16_t)(sp0 - 3) ^ 4) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 7)) & 0x8000) != 0;
    r->dp = (uint16_t)(sp0 - 7);
    r->sp -= 7;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9407, 0x7E809B); GUARD_JSR(c, sp_call, 0x9407); } /* create_graphics_buffer */
    r->sp += 7;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret = r->y;
    if (x_ret) {
        RAM8(0x0003 + (uint16_t)(sp0 - 7)) = (uint8_t)x_ret2;
        r->a = 1;
        r->x = (uint8_t)x_ret2;
        r->y = (uint8_t)y_ret;
        r->z = 0;
        r->n = 0;
        r->xf = 1;
        r->sp -= 7;
        { const uint16_t sp_call = r->sp; JSR(c, 0x940F, 0x7E8FC7); GUARD_JSR(c, sp_call, 0x940F); } /* allocate_transfer_descriptor */
        r->sp += 7;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        uint16_t x_ret4 = r->x;
        uint16_t value = BUS16_RDP(c, (uint16_t)(dp_ret + 3));
        BUS16_SET(c, (db_ret << 0x10) + 0x0A + x_ret4, value);
        BUS16_SET(c, (db_ret << 0x10) + 2 + x_ret4, 0x5200);
        BUS16_SET(c, (db_ret << 0x10) + 5 + x_ret4, 0x05C0);
        BUS8_SET(c, (db_ret << 0x10) + 4 + x_ret4, 0x7E);
        r->a = 0x057E;
        r->z = 0;
        r->n = 0;
        r->mf = 1;
        r->sp -= 7;
        { const uint16_t sp_call = r->sp; JSR(c, 0x942A, 0x7E90DA); GUARD_JSR(c, sp_call, 0x942A); } /* submit_transfer_or_program_hdma */
        r->sp += 7;
        if (r->mf != 1) { c->fail = 3; return; }
        uint16_t a_all3 = r->a;
        r->a = (a_all3 >> 8 << 8) | 8;
        r->z = 0;
        r->n = 0;
        r->sp -= 7;
        { const uint16_t sp_call = r->sp; JSR(c, 0x942F, 0x7EBBAB); GUARD_JSR(c, sp_call, 0x942F); } /* allocate_palette_slot */
        r->sp += 7;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t x_ret7 = r->x;
        RAM8(0x0000 + sp0 - 7) = x_ret7 >> 8;
        RAM8(0x0000 + sp0 - 8) = (uint8_t)x_ret7;
        r->a = 0x7E1E;
        r->y = 0x5160;
        r->z = 0;
        r->n = 0;
        r->sp -= 9;
        { const uint16_t sp_call = r->sp; JSR(c, 0x943B, 0x7EBC9A); GUARD_JSR(c, sp_call, 0x943B); } /* copy_palette_colours */
        r->sp += 9;
        bool x_ret8 = r->xf;
        if (x_ret8) {
            c->fail = 3;
            return;
        } else {
            uint8_t value33 = RAM8(0x0000 + sp0 - 8);
            uint8_t value34 = RAM8(0x0000 + sp0 - 7);
            r->x = (value34 << 8) | value33;
            r->z = ((value34 << 8) | value33) == 0;
            r->n = ((value34 << 8) | value33) & 0x8000;
            r->xf = 0;
            r->sp -= 7;
            { const uint16_t sp_call = r->sp; JSR(c, 0x943F, 0x7EBBFE); GUARD_JSR(c, sp_call, 0x943F); } /* queue_palette_upload */
            r->sp += 7;
            uint8_t db_ret5 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all9 = r->a;
            r->a = (a_all9 >> 8 << 8) | 0;
            r->x = 0x20;
            r->z = 1;
            r->n = 0;
            r->sp -= 7;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9447, 0x7EB0A1); GUARD_JSR(c, sp_call, 0x9447); } /* allocate_and_fill_bytes */
            r->sp += 7;
            if (r->mf != 1) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all10 = r->a;
            uint16_t x_ret15 = r->x;
            BUS16_SET(c, (db_ret5 << 0x10) + 0x7C, x_ret15);
            r->a = (a_all10 >> 8 << 8) | 0;
            r->x = 8;
            r->z = 1;
            r->n = 0;
            r->sp -= 7;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9452, 0x7EB0A1); GUARD_JSR(c, sp_call, 0x9452); } /* allocate_and_fill_bytes */
            r->sp += 7;
            bool m_ret3 = r->mf;
            bool x_ret16 = r->xf;
            uint16_t x_ret17 = r->x;
            uint16_t y_ret11 = r->y;
            if (x_ret16) {
                BUS8_SET(c, (db_ret5 << 0x10) + 0x7E, (uint8_t)x_ret17);
                if (m_ret3) {
                    uint8_t value39 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value40 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value41 = RAM8(0x0000 + sp0);
                    r->x = (uint8_t)x_ret17;
                    r->y = (uint8_t)y_ret11;
                    r->c = value39 & 0x01;
                    r->z = ((value41 << 8) | value40) == 0;
                    r->n = ((value41 << 8) | value40) & 0x8000;
                    r->v = value39 & 0x40;
                    r->mf = value39 & 0x20;
                    r->xf = value39 & 0x10;
                    r->dp = (value41 << 8) | value40;
                    r->i = value39 & 0x04;
                    r->d = value39 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    c->fail = 3;
                    return;
                }
            } else {
                BUS16_SET(c, (db_ret5 << 0x10) + 0x7E, x_ret17);
                if (m_ret3) {
                    uint8_t value52 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value53 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value54 = RAM8(0x0000 + sp0);
                    r->c = value52 & 0x01;
                    r->z = ((value54 << 8) | value53) == 0;
                    r->n = ((value54 << 8) | value53) & 0x8000;
                    r->v = value52 & 0x40;
                    r->mf = value52 & 0x20;
                    r->xf = value52 & 0x10;
                    r->dp = (value54 << 8) | value53;
                    r->i = value52 & 0x04;
                    r->d = value52 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    c->fail = 3;
                    return;
                }
            }
        }
    } else {
        RAM16_SET(0x0003 + (uint16_t)(sp0 - 7), x_ret2);
        r->a = 1;
        r->z = 0;
        r->n = 0;
        r->xf = 0;
        r->sp -= 7;
        { const uint16_t sp_call = r->sp; JSR(c, 0x940F, 0x7E8FC7); GUARD_JSR(c, sp_call, 0x940F); } /* allocate_transfer_descriptor */
        r->sp += 7;
        uint16_t dp_ret6 = r->dp;
        uint8_t db_ret6 = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        uint16_t x_ret19 = r->x;
        uint16_t value61 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 3));
        BUS16_SET(c, (db_ret6 << 0x10) + 0x0A + x_ret19, value61);
        BUS16_SET(c, (db_ret6 << 0x10) + 2 + x_ret19, 0x5200);
        BUS16_SET(c, (db_ret6 << 0x10) + 5 + x_ret19, 0x05C0);
        BUS8_SET(c, (db_ret6 << 0x10) + 4 + x_ret19, 0x7E);
        r->a = 0x057E;
        r->z = 0;
        r->n = 0;
        r->mf = 1;
        r->sp -= 7;
        { const uint16_t sp_call = r->sp; JSR(c, 0x942A, 0x7E90DA); GUARD_JSR(c, sp_call, 0x942A); } /* submit_transfer_or_program_hdma */
        r->sp += 7;
        if (r->mf != 1) { c->fail = 3; return; }
        uint16_t a_all13 = r->a;
        r->a = (a_all13 >> 8 << 8) | 8;
        r->z = 0;
        r->n = 0;
        r->sp -= 7;
        { const uint16_t sp_call = r->sp; JSR(c, 0x942F, 0x7EBBAB); GUARD_JSR(c, sp_call, 0x942F); } /* allocate_palette_slot */
        r->sp += 7;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t x_ret22 = r->x;
        RAM8(0x0000 + sp0 - 7) = x_ret22 >> 8;
        RAM8(0x0000 + sp0 - 8) = (uint8_t)x_ret22;
        r->a = 0x7E1E;
        r->y = 0x5160;
        r->z = 0;
        r->n = 0;
        r->sp -= 9;
        { const uint16_t sp_call = r->sp; JSR(c, 0x943B, 0x7EBC9A); GUARD_JSR(c, sp_call, 0x943B); } /* copy_palette_colours */
        r->sp += 9;
        bool x_ret23 = r->xf;
        if (x_ret23) {
            c->fail = 3;
            return;
        } else {
            uint8_t value93 = RAM8(0x0000 + sp0 - 8);
            uint8_t value94 = RAM8(0x0000 + sp0 - 7);
            r->x = (value94 << 8) | value93;
            r->z = ((value94 << 8) | value93) == 0;
            r->n = ((value94 << 8) | value93) & 0x8000;
            r->xf = 0;
            r->sp -= 7;
            { const uint16_t sp_call = r->sp; JSR(c, 0x943F, 0x7EBBFE); GUARD_JSR(c, sp_call, 0x943F); } /* queue_palette_upload */
            r->sp += 7;
            uint8_t db_ret10 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all19 = r->a;
            r->a = (a_all19 >> 8 << 8) | 0;
            r->x = 0x20;
            r->z = 1;
            r->n = 0;
            r->sp -= 7;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9447, 0x7EB0A1); GUARD_JSR(c, sp_call, 0x9447); } /* allocate_and_fill_bytes */
            r->sp += 7;
            if (r->mf != 1) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all20 = r->a;
            uint16_t x_ret30 = r->x;
            BUS16_SET(c, (db_ret10 << 0x10) + 0x7C, x_ret30);
            r->a = (a_all20 >> 8 << 8) | 0;
            r->x = 8;
            r->z = 1;
            r->n = 0;
            r->sp -= 7;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9452, 0x7EB0A1); GUARD_JSR(c, sp_call, 0x9452); } /* allocate_and_fill_bytes */
            r->sp += 7;
            bool m_ret6 = r->mf;
            bool x_ret31 = r->xf;
            uint16_t x_ret32 = r->x;
            uint16_t y_ret21 = r->y;
            if (x_ret31) {
                BUS8_SET(c, (db_ret10 << 0x10) + 0x7E, (uint8_t)x_ret32);
                if (m_ret6) {
                    uint8_t value99 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value100 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value101 = RAM8(0x0000 + sp0);
                    r->x = (uint8_t)x_ret32;
                    r->y = (uint8_t)y_ret21;
                    r->c = value99 & 0x01;
                    r->z = ((value101 << 8) | value100) == 0;
                    r->n = ((value101 << 8) | value100) & 0x8000;
                    r->v = value99 & 0x40;
                    r->mf = value99 & 0x20;
                    r->xf = value99 & 0x10;
                    r->dp = (value101 << 8) | value100;
                    r->i = value99 & 0x04;
                    r->d = value99 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    c->fail = 3;
                    return;
                }
            } else {
                BUS16_SET(c, (db_ret10 << 0x10) + 0x7E, x_ret32);
                if (m_ret6) {
                    uint8_t value112 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value113 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value114 = RAM8(0x0000 + sp0);
                    r->c = value112 & 0x01;
                    r->z = ((value114 << 8) | value113) == 0;
                    r->n = ((value114 << 8) | value113) & 0x8000;
                    r->v = value112 & 0x40;
                    r->mf = value112 & 0x20;
                    r->xf = value112 & 0x10;
                    r->dp = (value114 << 8) | value113;
                    r->i = value112 & 0x04;
                    r->d = value112 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    c->fail = 3;
                    return;
                }
            }
        }
    }
}
SOM_REGISTER(0x7E93F4, SOM_RTS, "gen", enter_warm_graphics_resource_constructor, 0, L_X | L_Y | L_C | L_Z | L_N | L_V, 9, 0, 0, 105, 49)
