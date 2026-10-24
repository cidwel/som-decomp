#include "som_c.h"

/* C27DE7 move_native58_and_clear_party_hp_at_lower_boundary   [class B, 33 bytes, 13 instructions]
 * Source: src/rom/move_native58_and_clear_party_hp_at_lower_boundary.s
 * Documented in docs/boss-native58-setup.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BYV.
 */
static void move_native58_and_clear_party_hp_at_lower_boundary(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x003E + x);
    uint8_t a_hi2;
    uint16_t y1;
    bool overflow1;
    if (value == 0) {
        a_hi2 = value >> 8;
        y1 = y;
        overflow1 = overflow;
    } else {
        r->a = value;
        JSR(c, 0x7DEE, 0xC27E08); /* advance_native58_fractional_vertical_axis_and_rollback_on_collision */
        uint16_t y_ret = r->y;
        bool overflow_ret = r->v;
        uint16_t value2 = RAM16(0x0287);
        uint16_t value3 = RAM16(0x0032 + value2);
        uint8_t a_hi1;
        if (value3 < 0x0118) {
            a_hi1 = value3 >> 8;
        } else {
            uint16_t value4 = RAM16(0x0190 + value2);
            if (!(value4 & 0x8000)) {
                RAM16_SET(0xE182, 0);
                RAM16_SET(0xE382, 0);
                RAM16_SET(0xE582, 0);
            }
            a_hi1 = value4 >> 8;
        }
        a_hi2 = a_hi1;
        y1 = y_ret;
        overflow1 = overflow_ret;
    }
    r->a = (a_hi2 << 8) | (uint8_t)a;
    r->y = y1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC27DE7, SOM_RTS, "gen", move_native58_and_clear_party_hp_at_lower_boundary, 0, L_B | L_Y | L_V, 1, 0, 0, 33, 13)
