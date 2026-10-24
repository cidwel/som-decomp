#include "som_c.h"

/* C0DD8B scan_initial_map_object_slots   [class B, 51 bytes, 28 instructions]
 * Source: src/rom/scan_initial_map_object_slots.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void scan_initial_map_object_slots(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a_hi = r->a >> 8;
    const bool overflow = r->v;
    uint8_t value = RAM8(0x00ED);
    uint8_t a1;
    if (!(value & 0x80)) {
        a1 = 9;
    } else {
        a1 = 3;
    }
    uint8_t a2 = a1;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 0x0600;
    uint16_t y1 = 0;
    bool carry1 = value & 0x80;
    bool overflow1 = overflow;
    uint8_t data_bank = 0x7E;
    uint16_t direct_page = 0;
    for (;;) {
        RAM8(0x0000 + sp0) = a2;
        uint8_t value2 = BUS8_RDP(c, (uint16_t)(direct_page + 0xBC));
        BUS8_SET(c, (uint16_t)(direct_page + 0x0C), value2);
        RAM8(0x0000 + sp0 - 1) = y1 >> 8;
        RAM8(0x0000 + sp0 - 2) = (uint8_t)y1;
        r->a = (a_hi1 << 8) | value2;
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->z = value2 == 0;
        r->n = value2 & 0x80;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xDDA6, 0xC0E0EB); GUARD_JSR(c, sp_call, 0xDDA6); } /* prepare_map_object_load_window */
        r->sp += 3;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xDDA9, 0xC0DDBE); GUARD_JSR(c, sp_call, 0xDDA9); } /* scan_map_object_cache_for_creation */
        r->sp += 3;
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret2 = r->db;
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t x_ret2 = r->x;
        uint8_t value3 = RAM8(0x0000 + sp0 - 2);
        uint8_t value4 = RAM8(0x0000 + sp0 - 1);
        uint8_t value5 = RAM8(0x0000 + sp0);
        uint8_t value6 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 0x5C));
        uint8_t a3;
        if (value6 & 0x80) {
            a3 = value5;
        } else {
            if ((uint8_t)(value5 - 1) != 0) {
                a2 = (uint8_t)(value5 - 1);
                a_hi1 = (uint16_t)(x_ret2 + 0x0200) >> 8;
                x1 = (uint16_t)(x_ret2 + 0x0200);
                y1 = (value4 << 8) | value3;
                carry1 = x_ret2 + 0x0200 > 0xFFFF;
                overflow1 = value6 & 0x40;
                data_bank = db_ret2;
                direct_page = dp_ret2;
                continue;
            }
            a3 = (uint8_t)(value5 - 1);
        }
        a2 = a3;
        a_hi1 = (uint16_t)(x_ret2 + 0x0200) >> 8;
        x1 = (uint16_t)(x_ret2 + 0x0200);
        y1 = (value4 << 8) | value3;
        carry1 = x_ret2 + 0x0200 > 0xFFFF;
        overflow1 = value6 & 0x40;
        data_bank = db_ret2;
        direct_page = dp_ret2;
        break;
    }
    r->a = (a_hi1 << 8) | a2;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank;
    r->dp = direct_page;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0DD8B, SOM_RTS, "gen", scan_initial_map_object_slots, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 3, 1, 0, 51, 28)
