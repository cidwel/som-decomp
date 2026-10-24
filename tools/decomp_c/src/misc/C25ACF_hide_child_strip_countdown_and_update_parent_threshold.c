#include "som_c.h"

/* C25ACF hide_child_strip_countdown_and_update_parent_threshold   [class B, 45 bytes, 18 instructions]
 * Source: src/rom/hide_child_strip_countdown_and_update_parent_threshold.s
 * Documented in docs/boss-native-linked-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void hide_child_strip_countdown_and_update_parent_threshold(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x0289);
    RAM16_SET(0x0000 + value, 0);
    RAM16_SET(0x0015 + x, (uint16_t)(RAM16(0x0015 + x) - 1));
    uint8_t a_hi1;
    uint16_t x1;
    bool overflow1;
    if (RAM16(0x0015 + x) != 0) {
        a_hi1 = 0;
        x1 = x;
        overflow1 = overflow;
    } else {
        RAM16_SET(0x008E + x, 0x59F7);
        RAM16_SET(0x0083 + x, 0);
        uint16_t value2 = RAM16(0x00B0 + x);
        r->x = value2;
        r->y = value;
        JSR(c, 0x5AEB, 0xC25920); /* derive_boss_threshold_from_hardware_division_and_clamp */
        uint16_t a_all = r->a;
        bool overflow_ret = r->v;
        a_hi1 = a_all >> 8;
        x1 = value2;
        overflow1 = overflow_ret;
    }
    uint16_t value3 = RAM16(0x0081 + x1);
    uint8_t a1;
    uint8_t a_hi2;
    uint16_t x2;
    uint16_t y1;
    bool zero1;
    bool negative1;
    bool overflow2;
    if (value3 != 4) {
        a1 = (uint8_t)value3;
        a_hi2 = value3 >> 8;
        x2 = x1;
        y1 = value;
        zero1 = value3 == 4;
        negative1 = (uint16_t)(value3 - 4) & 0x8000;
        overflow2 = overflow1;
    } else {
        r->a = value3;
        r->x = x1;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x5AF6, 0xC25E9D); /* consume_linked_child_request_and_select_native_definition */
        uint16_t a_all2 = r->a;
        uint16_t x_ret = r->x;
        uint16_t y_ret = r->y;
        bool zero_ret2 = r->z;
        bool negative_ret2 = r->n;
        bool overflow_ret2 = r->v;
        a1 = (uint8_t)a_all2;
        a_hi2 = a_all2 >> 8;
        x2 = x_ret;
        y1 = y_ret;
        zero1 = zero_ret2;
        negative1 = negative_ret2;
        overflow2 = overflow_ret2;
    }
    RAM16_SET(0x0081 + x2, 0);
    r->a = (a_hi2 << 8) | a1;
    r->x = x2;
    r->y = y1;
    r->c = 0;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow2;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC25ACF, SOM_RTS, "gen", hide_child_strip_countdown_and_update_parent_threshold, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 45, 18)
