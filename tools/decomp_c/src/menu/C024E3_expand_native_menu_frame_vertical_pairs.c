#include "som_c.h"

/* C024E3 expand_native_menu_frame_vertical_pairs   [class B, 64 bytes, 28 instructions]
 * Source: src/rom/expand_native_menu_frame_vertical_pairs.s
 * Documented in docs/event-menu-page-records.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: X.
 */
static void expand_native_menu_frame_vertical_pairs(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = x;
    do {
        RAM8(0x0000 + sp0) = x1 >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)x1;
        RAM16_SET(0x9000 + x1, 0x2022);
        RAM16_SET(0x9040 + x1, 0x2022);
        uint16_t value = RAM16(0xA20A);
        bool m_flag;
        uint8_t a_hi2;
        uint16_t x2;
        if ((value & 8) != 0) {
            r->a = value & 8;
            r->x = (uint16_t)(x1 + 2);
            r->mf = 0;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSR(c, 0x2500, 0xC02523); GUARD_JSR(c, sp_call, 0x2500); } /* skip_native_menu_interior_tile_columns */
            r->sp += 2;
            uint16_t a_all = r->a;
            uint16_t x_ret = r->x;
            m_flag = 0;
            a_hi2 = a_all >> 8;
            x2 = x_ret;
        } else {
            r->a = value & 8;
            r->x = (uint16_t)(x1 + 2);
            r->mf = 0;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSR(c, 0x24FB, 0xC02533); GUARD_JSR(c, sp_call, 0x24FB); } /* expand_native_menu_interior_sequential_tiles */
            r->sp += 2;
            uint16_t a_all2 = r->a;
            uint16_t x_ret2 = r->x;
            m_flag = 1;
            a_hi2 = a_all2 >> 8;
            x2 = x_ret2;
        }
        if (m_flag) {
            RAM8(0xA164) = RAM8(0xA16C);
            RAM16_SET(0x9000 + x2, 0x6022);
            RAM16_SET(0x9040 + x2, 0x6022);
            uint8_t value3 = RAM8(0x0000 + sp0 - 1);
            uint8_t value4 = RAM8(0x0000 + sp0);
            RAM8(0xA163)--;
            RAM8(0xA163)--;
            a_hi1 = (uint16_t)(((value4 << 8) | value3) + 0x80) >> 8;
            x1 = (uint16_t)(((value4 << 8) | value3) + 0x80);
        } else {
            RAM16_SET(0xA164, RAM16(0xA16C));
            RAM16_SET(0x9000 + x2, 0x6022);
            RAM16_SET(0x9040 + x2, 0x6022);
            uint8_t value6 = RAM8(0x0000 + sp0 - 1);
            uint8_t value7 = RAM8(0x0000 + sp0);
            RAM8(0xA163)--;
            RAM8(0xA163)--;
            a_hi1 = (uint16_t)(((value7 << 8) | value6) + 0x80) >> 8;
            x1 = (uint16_t)(((value7 << 8) | value6) + 0x80);
        }
    } while (RAM8(0xA163) != 0);
    r->x = x1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC024E3, SOM_RTS, "gen", expand_native_menu_frame_vertical_pairs, 0, L_X, 2, 1, 0, 64, 28)
