#include "som_c.h"

/* C76A7B subtract_native_party_status_statistic_vectors_with_borrow   [class A, 26 bytes, 14 instructions]
 * Source: src/rom/subtract_native_party_status_statistic_vectors_with_borrow.s
 * Documented in docs/ui-native-party-status-page.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABYCV.
 */
static void subtract_native_party_status_statistic_vectors_with_borrow(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const bool overflow = r->v;
    JSR(c, 0x6A7D, 0xC76A95); /* derive_selected_native_party_status_record_offset */
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    uint8_t a1 = 3;
    uint8_t a_hi1 = a_all >> 8;
    uint16_t x1 = 0;
    uint16_t y1 = y_ret;
    bool carry1 = 1;
    bool overflow1 = overflow;
    for (;;) {
        uint8_t value = RAM8(0xE17D + y1);
        uint8_t value2 = RAM8(0xE18D + y1);
        RAM8(0xA136 + x1) = (uint8_t)(value - value2 - (carry1 ^ 1));
        uint8_t a1_next = (uint8_t)(a1 - 1);
        uint8_t a_hi1_next = (uint8_t)(value - value2 - (carry1 ^ 1));
        uint16_t x1_next = (uint16_t)(x1 + 1);
        uint16_t y1_next = (uint16_t)(y1 + 1);
        bool carry1_next = value - value2 >= (carry1 ^ 1);
        bool overflow1_next = ((value ^ value2) & (value ^ (uint8_t)(value - value2 - (carry1 ^ 1))) & 0x80) != 0;
        a1 = a1_next;
        a_hi1 = a_hi1_next;
        x1 = x1_next;
        y1 = y1_next;
        carry1 = carry1_next;
        overflow1 = overflow1_next;
        if (!(a1 != 0)) break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC76A7B, SOM_RTS, "gen", subtract_native_party_status_statistic_vectors_with_borrow, 0, L_A | L_B | L_Y | L_C | L_V, 1, 1, 0, 26, 14)
