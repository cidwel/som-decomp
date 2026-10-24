#include "som_c.h"

/* C76BCF initialize_six_native_blank_detail_rows   [class A, 14 bytes, 8 instructions]
 * Source: src/rom/initialize_six_native_blank_detail_rows.s
 * Documented in docs/ui-native-spell-item-detail.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void initialize_six_native_blank_detail_rows(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a1 = 6;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 0;
    uint16_t y1 = y;
    bool carry1 = carry;
    bool overflow1 = overflow;
    for (;;) {
        r->a = (a1 << 8) | a_hi1;
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        JSR(c, 0x6BD7, 0xC7538D); /* append_native_saved_slot_text_line_token */
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        a1 = (uint8_t)((a_all >> 8) - 1);
        a_hi1 = (uint8_t)a_all;
        x1 = x_ret;
        if (!(a1 != 0)) break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC76BCF, SOM_RTS, "gen", initialize_six_native_blank_detail_rows, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 14, 8)
