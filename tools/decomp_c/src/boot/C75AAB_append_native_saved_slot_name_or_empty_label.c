#include "som_c.h"

/* C75AAB append_native_saved_slot_name_or_empty_label   [class B, 66 bytes, 36 instructions]
 * Source: src/rom/append_native_saved_slot_name_or_empty_label.s
 * Documented in docs/ui-native-loaded-game-slot-descriptions.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void append_native_saved_slot_name_or_empty_label(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const bool overflow = r->v;
    r->a = (a_hi << 8) | 5;
    JSR(c, 0x5AAF, 0xC759E0); /* append_native_saved_slot_format_pair */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    uint8_t value = RAM8(0xA216);
    uint8_t a_hi4;
    uint16_t x3;
    uint16_t y4;
    bool carry1;
    bool overflow1;
    if ((value & 3) != 3) {
        r->a = a_all >> 8 << 8 | (value & 3);
        r->mf = 0;
        r->xf = 0;
        r->sp -= 2;
        JSR(c, 0x5AD5, 0xC75D00); /* derive_selected_save_slot_primary_or_backup_offset */
        r->sp += 2;
        uint16_t a_all2 = r->a;
        uint16_t x_ret2 = r->x;
        bool carry_ret2 = r->c;
        bool overflow_ret = r->v;
        uint8_t a1 = 0x0C;
        uint8_t a_hi1 = a_all2 >> 8;
        uint16_t x1 = x_ret2;
        uint16_t y1 = x_ret;
        for (;;) {
            uint8_t value2 = BUS8(c, 0x306003 + x1);
            uint8_t a_hi2;
            uint16_t y2;
            if (value2 == 0) {
                a_hi2 = a1;
                y2 = y1;
            } else {
                RAM8(0x9C00 + y1) = value2;
                if ((uint8_t)(a1 - 1) != 0) {
                    a1 = (uint8_t)(a1 - 1);
                    a_hi1 = value2;
                    x1 = (uint16_t)(x1 + 1);
                    y1 = (uint16_t)(y1 + 1);
                    continue;
                }
                a_hi2 = value2;
                y2 = (uint16_t)(y1 + 1);
            }
            a_hi1 = a_hi2;
            y1 = y2;
            break;
        }
        a_hi4 = a_hi1;
        x3 = y1;
        y4 = y1;
        carry1 = carry_ret2;
        overflow1 = overflow_ret;
    } else {
        uint8_t a2 = 5;
        uint8_t a_hi3 = a_all >> 8;
        uint16_t x2 = 0;
        uint16_t y3 = x_ret;
        for (;;) {
            uint8_t value3 = BUS8(c, 0xC77805 + x2);
            RAM8(0x9C00 + y3) = value3;
            a2 = (uint8_t)(a2 - 1);
            a_hi3 = value3;
            x2 = (uint16_t)(x2 + 1);
            y3 = (uint16_t)(y3 + 1);
            if (!(a2 != 0)) break;
        }
        a_hi4 = a_hi3;
        x3 = y3;
        y4 = y3;
        carry1 = (value & 3) >= 3;
        overflow1 = overflow;
    }
    r->a = (a_hi4 << 8) | a;
    r->x = x3;
    r->y = y4;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC75AAB, SOM_RTS, "gen", append_native_saved_slot_name_or_empty_label, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 66, 36)
