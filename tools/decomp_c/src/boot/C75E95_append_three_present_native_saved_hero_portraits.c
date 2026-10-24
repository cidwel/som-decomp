#include "som_c.h"

/* C75E95 append_three_present_native_saved_hero_portraits   [class B, 51 bytes, 24 instructions]
 * Source: src/rom/append_three_present_native_saved_hero_portraits.s
 * Documented in docs/ui-native-saved-game-menu-request.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void append_three_present_native_saved_hero_portraits(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t value = RAM8(0xA216);
    uint8_t a_hi4;
    uint16_t x2;
    uint16_t y4;
    bool carry4;
    bool overflow4;
    if (((value & 3) ^ 3) == 0) {
        a_hi4 = a_hi;
        x2 = x;
        y4 = y;
        carry4 = carry;
        overflow4 = overflow;
    } else {
        r->a = (a_hi << 8) | ((value & 3) ^ 3);
        r->mf = false;
        JSR(c, 0x5EA2, 0xC75D00); /* derive_selected_save_slot_primary_or_backup_offset */
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        uint8_t value2 = BUS8(c, 0x306283 + x_ret);
        uint8_t a_hi1;
        uint16_t y1;
        bool carry1;
        bool overflow1;
        if ((uint8_t)(value2 - 1) != 0) {
            a_hi1 = a_all >> 8;
            y1 = y;
            carry1 = carry_ret;
            overflow1 = overflow_ret;
        } else {
            r->a = (a_all >> 8 << 8) | (uint8_t)(value2 - 1);
            r->mf = true;
            r->xf = false;
            r->sp -= 2;
            JSR(c, 0x5EAF, 0xC75ED8); /* external */
            r->sp += 2;
            uint16_t a_all2 = r->a;
            uint16_t y_ret = r->y;
            bool carry_ret2 = r->c;
            bool overflow_ret2 = r->v;
            a_hi1 = a_all2 >> 8;
            y1 = y_ret;
            carry1 = carry_ret2;
            overflow1 = overflow_ret2;
        }
        uint8_t value3 = BUS8(c, 0x306289 + x_ret);
        uint8_t a_hi2;
        uint16_t y2;
        bool carry2;
        bool overflow2;
        if ((uint8_t)(value3 - 1) != 0) {
            a_hi2 = a_hi1;
            y2 = y1;
            carry2 = carry1;
            overflow2 = overflow1;
        } else {
            r->a = (a_hi1 << 8) | (uint8_t)(value3 - 1);
            r->x = x_ret;
            r->y = y1;
            r->c = carry1;
            r->v = overflow1;
            r->mf = true;
            r->xf = false;
            r->db = 0x7E;
            r->dp = 0;
            r->sp -= 2;
            JSR(c, 0x5EBB, 0xC75EDC); /* external */
            r->sp += 2;
            uint16_t a_all3 = r->a;
            uint16_t y_ret2 = r->y;
            bool carry_ret3 = r->c;
            bool overflow_ret3 = r->v;
            a_hi2 = a_all3 >> 8;
            y2 = y_ret2;
            carry2 = carry_ret3;
            overflow2 = overflow_ret3;
        }
        uint8_t value4 = BUS8(c, 0x30628F + x_ret);
        uint8_t a_hi3;
        uint16_t x1;
        uint16_t y3;
        bool carry3;
        bool overflow3;
        if ((uint8_t)(value4 - 1) != 0) {
            a_hi3 = a_hi2;
            x1 = x_ret;
            y3 = y2;
            carry3 = carry2;
            overflow3 = overflow2;
        } else {
            r->a = (a_hi2 << 8) | (uint8_t)(value4 - 1);
            r->y = y2;
            r->c = carry2;
            r->v = overflow2;
            r->mf = true;
            r->xf = false;
            r->db = 0x7E;
            r->dp = 0;
            JSR(c, 0x5EC6, 0xC75EEB); /* external */
            uint16_t a_all4 = r->a;
            uint16_t x_ret4 = r->x;
            uint16_t y_ret3 = r->y;
            bool carry_ret4 = r->c;
            bool overflow_ret4 = r->v;
            a_hi3 = a_all4 >> 8;
            x1 = x_ret4;
            y3 = y_ret3;
            carry3 = carry_ret4;
            overflow3 = overflow_ret4;
        }
        a_hi4 = a_hi3;
        x2 = x1;
        y4 = y3;
        carry4 = carry3;
        overflow4 = overflow3;
    }
    r->a = (a_hi4 << 8) | a;
    r->x = x2;
    r->y = y4;
    r->c = carry4;
    r->v = overflow4;
    r->mf = true;
    r->xf = false;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC75E95, SOM_RTS, "hand", append_three_present_native_saved_hero_portraits, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 51, 24)
