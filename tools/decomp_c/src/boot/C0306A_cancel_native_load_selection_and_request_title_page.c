#include "som_c.h"

/* C0306A cancel_native_load_selection_and_request_title_page   [class A, 14 bytes, 6 instructions]
 * Source: src/rom/cancel_native_load_selection_and_request_title_page.s
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void cancel_native_load_selection_and_request_title_page(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint8_t a_hi = r->a >> 8;
    const uint8_t db = r->db;
    BUS8_SET(c, (db << 0x10) + 0xA210, 0);
    r->a = (a_hi << 8) | 0;
    r->z = 1;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x3071, 0xC01BAF); GUARD_JSR(c, sp_call, 0x3071); } /* external */
    uint8_t db_ret = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    uint8_t value = BUS8_RDP(c, (db_ret << 0x10) + 0xA20A);
    BUS8_SET(c, (db_ret << 0x10) + 0xA20A, value | 1);
    SET_A8(r, 1);
    r->z = (value & 1) == 0;
    r->n = 0;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0306A, SOM_RTS, "gen", cancel_native_load_selection_and_request_title_page, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 14, 6)
