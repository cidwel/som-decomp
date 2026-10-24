#include "som_c.h"

static void select_pending_map_column_edges(SomCtx *c);

/* C0C8EF prepare_pending_map_columns   [class B, 86 bytes, 45 instructions]
 * Source: src/rom/prepare_pending_map_columns.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void prepare_pending_map_columns(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t sp_in = r->sp;
    const uint8_t a_hi = r->a >> 8;
    uint8_t value = RAM8(0x002F);
    if (value == 0) {
        SET_A8(r, value);
        RETURN_RTS(c);
    }
    if (value < 0xC0) {
        RAM8(0x0000 + sp0) = 0;
        RAM8(0x0000 + sp0 - 1) = 0x7F;
        r->a = (a_hi << 8) | value;
        r->x = (uint8_t)((a_hi << 8) | value);
        r->db = 0x7F;
        r->sp -= 1;
        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xC903, select_pending_map_column_edges, sp_in, 2); GUARD_JSR(c, sp_call, 0xC903); }
        r->sp += 1;
        uint8_t value2 = RAM8(0x0000 + sp0);
        r->mf = 1;
        r->db = value2;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    SET_A8(r, value);
    r->c = value >= 0xC0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0C8EF, SOM_RTS, "gen", prepare_pending_map_columns, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 6, 1, 1, 86, 45)

/* C0C908 select_pending_map_column_edges   [class A, 62 bytes, 30 instructions]
 * Source: src/rom/prepare_pending_map_columns.s
 * Subroutine of prepare_pending_map_columns, translated in place.
 * Entry: M=8 bit X=8 bit DB=$7F D=$0000.  Callers read: ABXYCZNV.
 */
static void select_pending_map_column_edges(SomCtx *c)
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
    uint8_t a_hi2;
    uint16_t x1;
    uint16_t y1;
    bool overflow1;
    if ((a & 3) == 0) {
        x_flag = 1;
        a_hi2 = a_hi;
        x1 = x;
        y1 = y;
        overflow1 = overflow;
    } else {
        uint8_t a_hi1;
        if ((a & 3) >= 2) {
            a_hi1 = 0;
        } else {
            a_hi1 = 1;
        }
        RAM16_SET(0x0000, (a_hi1 << 8) | 0);
        r->mf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0xC91C, 0xC0C945); GUARD_JSR(c, sp_call, 0xC91C); } /* build_first_layer_tile_column */
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        uint16_t y_ret = r->y;
        bool overflow_ret = r->v;
        RAM8(0x002F) |= 0x80;
        x_flag = 0;
        a_hi2 = a_all >> 8;
        x1 = x_ret;
        y1 = y_ret;
        overflow1 = overflow_ret;
    }
    uint8_t value2 = RAM8(0x002F);
    if (((value2 >> 2) & 3) == 0) {
        r->a = a_hi2 << 8 | ((value2 >> 2) & 3);
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
    uint8_t a_hi3;
    if (((value2 >> 2) & 3) >= 2) {
        a_hi3 = 0;
    } else {
        a_hi3 = 1;
    }
    RAM16_SET(0x0000, (a_hi3 << 8) | 0);
    r->mf = 0;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC93D, 0xC0D158); GUARD_JSR(c, sp_call, 0xC93D); } /* build_second_layer_tile_column */
    uint8_t value3 = RAM8(0x002F);
    RAM8(0x002F) |= 0x40;
    SET_A8(r, 0x40);
    r->z = (value3 & 0x40) == 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
