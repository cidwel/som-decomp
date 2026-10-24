#include "som_c.h"

/* C767D8 select_native_status_bar_conversion_for_first_ten_fields   [class A, 14 bytes, 6 instructions]
 * Source: src/rom/select_native_status_bar_conversion_for_first_ten_fields.s
 * Documented in docs/ui-native-party-status-page.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BCV.
 */
static void select_native_status_bar_conversion_for_first_ten_fields(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const bool overflow = r->v;
    uint8_t value = RAM8(0xA175);
    uint8_t a_hi1;
    bool carry1;
    bool overflow1;
    if (value >= 0x0A) {
        a_hi1 = a_hi;
        carry1 = value >= 0x0A;
        overflow1 = overflow;
    } else {
        r->a = (a_hi << 8) | value;
        JSR(c, 0x67E1, 0xC7684D); /* scale_native_status_bar_fields_with_shift_or_mode7_product */
        r->mf = 1;
        r->xf = 0;
        JSR(c, 0x67E4, 0xC767E6); /* divide_native_status_bar_and_publish_selected_actor_vram */
        uint16_t a_all2 = r->a;
        bool carry_ret2 = r->c;
        bool overflow_ret = r->v;
        a_hi1 = a_all2 >> 8;
        carry1 = carry_ret2;
        overflow1 = overflow_ret;
    }
    r->a = (a_hi1 << 8) | a;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC767D8, SOM_RTS, "gen", select_native_status_bar_conversion_for_first_ten_fields, 0, L_B | L_C | L_V, 1, 1, 0, 14, 6)
