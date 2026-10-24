#include "som_c.h"

static void select_pending_map_row_edges(SomCtx *c);

/* C0C7C3 prepare_pending_map_rows   [class C, 150 bytes, 78 instructions]
 * Source: src/rom/prepare_pending_map_rows.s
 * Documented in docs/maps.md
 * Entry: M=any X=8 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void prepare_pending_map_rows(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, -1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t sp_in = r->sp;
    const uint16_t a = r->a;
    uint8_t value = RAM8(0x002E);
    if (value == 0) {
        uint8_t value2 = RAM8(0x0082);
        if (value2 == 0) {
            SET_A8(r, value2);
            r->mf = 1;
            RETURN_RTS(c);
        }
        RAM8(0x0000 + sp0) = 0;
        RAM8(0x0000 + sp0 - 1) = 0x7F;
        uint16_t value3 = RAM16(0x0083);
        RAM16_SET(0x0000, value3 & 0xFF);
        RAM8(0x0083) = (uint8_t)((value3 & 0xFF) - 0x10);
        uint8_t value4 = RAM8(0x0082);
        bool negative1;
        if (!(value4 & 0x40)) {
            RAM8(0x0082) = 0;
            negative1 = value4 & 0x80;
        } else {
            RAM8(0x0082) = value4 ^ 0x40;
            negative1 = (value4 ^ 0x40) & 0x80;
        }
        uint8_t a1;
        uint8_t a_hi1;
        uint16_t x1;
        uint16_t y1;
        bool carry1;
        bool overflow1;
        if (negative1) {
            RAM8(0x002E) = 0x40;
            r->mf = 1;
            r->db = 0x7F;
            r->sp -= 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0xC854, 0xC0D0C2); GUARD_JSR(c, sp_call, 0xC854); } /* build_second_layer_tile_row */
            r->sp += 1;
            uint16_t a_all = r->a;
            uint16_t x_ret = r->x;
            uint16_t y_ret = r->y;
            bool carry_ret = r->c;
            bool overflow_ret = r->v;
            a1 = (uint8_t)a_all;
            a_hi1 = a_all >> 8;
            x1 = x_ret;
            y1 = y_ret;
            carry1 = carry_ret;
            overflow1 = overflow_ret;
        } else {
            RAM8(0x002E) = 0x80;
            r->mf = 1;
            r->db = 0x7F;
            r->sp -= 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0xC84B, 0xC0C859); GUARD_JSR(c, sp_call, 0xC84B); } /* build_first_layer_tile_row */
            r->sp += 1;
            uint16_t a_all2 = r->a;
            uint16_t x_ret2 = r->x;
            uint16_t y_ret2 = r->y;
            bool carry_ret2 = r->c;
            bool overflow_ret2 = r->v;
            a1 = (uint8_t)a_all2;
            a_hi1 = a_all2 >> 8;
            x1 = x_ret2;
            y1 = y_ret2;
            carry1 = carry_ret2;
            overflow1 = overflow_ret2;
        }
        uint8_t value5 = RAM8(0x0000 + sp0);
        r->a = (a_hi1 << 8) | a1;
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = value5;
        RETURN_RTS(c);
    }
    if (value < 0xC0) {
        RAM8(0x0000 + sp0) = 0;
        RAM8(0x0000 + sp0 - 1) = 0x7F;
        r->a = (a >> 8 << 8) | value;
        r->x = (uint8_t)((a >> 8 << 8) | value);
        r->mf = 1;
        r->db = 0x7F;
        r->sp -= 1;
        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xC7DE, select_pending_map_row_edges, sp_in, 2); GUARD_JSR(c, sp_call, 0xC7DE); }
        r->sp += 1;
        uint8_t value6 = RAM8(0x0000 + sp0);
        r->mf = 1;
        r->db = value6;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    SET_A8(r, value);
    r->c = value >= 0xC0;
    r->mf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0C7C3, SOM_RTS, "gen", prepare_pending_map_rows, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 6, -1, 1, 150, 78)

/* C0C7E3 select_pending_map_row_edges   [class A, 62 bytes, 30 instructions]
 * Source: src/rom/prepare_pending_map_rows.s
 * Subroutine of prepare_pending_map_rows, translated in place.
 * Entry: M=8 bit X=8 bit DB=$7F D=$0000.  Callers read: ABXYCZNV.
 */
static void select_pending_map_row_edges(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint8_t x = r->x;
    const uint8_t y = r->y;
    const bool overflow = r->v;
    bool x_flag;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool overflow1;
    if ((a & 3) == 0) {
        x_flag = 1;
        a_hi1 = a_hi;
        x1 = x;
        y1 = y;
        overflow1 = overflow;
    } else {
        uint8_t a1;
        if ((a & 3) >= 2) {
            a1 = 0;
        } else {
            a1 = 0xF0;
        }
        RAM16_SET(0x0000, a1);
        r->mf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0xC7F7, 0xC0C859); GUARD_JSR(c, sp_call, 0xC7F7); } /* build_first_layer_tile_row */
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        uint16_t y_ret = r->y;
        bool overflow_ret = r->v;
        RAM8(0x002E) |= 0x80;
        x_flag = 0;
        a_hi1 = a_all >> 8;
        x1 = x_ret;
        y1 = y_ret;
        overflow1 = overflow_ret;
    }
    uint8_t value2 = RAM8(0x002E);
    if (((value2 >> 2) & 3) == 0) {
        r->a = a_hi1 << 8 | ((value2 >> 2) & 3);
        r->x = (uint8_t)x1;
        r->y = (uint8_t)y1;
        r->c = value2 >> 1 & 0x01;
        r->z = ((value2 >> 2) & 3) == 0;
        r->n = (value2 >> 2) & 3 & 0x80;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 1;
        RETURN_RTS(c);
    }
    uint8_t a2;
    if (((value2 >> 2) & 3) >= 2) {
        a2 = 0;
    } else {
        a2 = 0xF0;
    }
    RAM16_SET(0x0000, a2);
    r->mf = 0;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC818, 0xC0D0C2); GUARD_JSR(c, sp_call, 0xC818); } /* build_second_layer_tile_row */
    uint8_t value3 = RAM8(0x002E);
    RAM8(0x002E) |= 0x40;
    SET_A8(r, 0x40);
    r->z = (value3 & 0x40) == 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
