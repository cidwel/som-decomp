#include "som_c.h"

/* C759EC append_valid_native_saved_slot_level   [class A, 16 bytes, 7 instructions]
 * Source: src/rom/append_valid_native_saved_slot_level.s
 * Documented in docs/ui-native-loaded-game-slot-descriptions.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void append_valid_native_saved_slot_level(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t value = RAM8(0xA216);
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool overflow1;
    if ((value & 3) == 3) {
        a_hi1 = a_hi;
        x1 = 0;
        y1 = y;
        carry1 = (value & 3) >= 3;
        overflow1 = overflow;
    } else {
        r->a = a_hi << 8 | (value & 3);
        r->x = 0;
        r->c = (value & 3) >= 3;
        JSR(c, 0x59FA, 0xC75AED); /* append_native_saved_slot_level_label */
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        uint16_t y_ret = r->y;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        a_hi1 = a_all >> 8;
        x1 = x_ret;
        y1 = y_ret;
        carry1 = carry_ret;
        overflow1 = overflow_ret;
    }
    r->a = (a_hi1 << 8) | a;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC759EC, SOM_RTS, "gen", append_valid_native_saved_slot_level, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 16, 7)
