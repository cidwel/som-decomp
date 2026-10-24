#include "som_c.h"

/* C7583C select_save_slot_copy_and_reject_invalid_pair   [class B, 62 bytes, 32 instructions]
 * Source: src/rom/select_save_slot_copy_and_reject_invalid_pair.s
 * Documented in docs/ui-native-loaded-game-save-load.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void select_save_slot_copy_and_reject_invalid_pair(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    RAM8(0xA216) = RAM8(0xA215);
    uint8_t value2 = RAM8(0xA211);
    uint8_t a_hi2;
    bool carry2;
    if (value2 == 0) {
        a_hi2 = (uint16_t)((((((a_hi << 8) | value2) & 0xFF) << 8) | 0) << 2) >> 8;
        carry2 = (uint16_t)((((((a_hi << 8) | value2) & 0xFF) << 8) | 0) << 1) & 0x8000;
    } else {
        uint8_t a1 = value2;
        uint8_t a_hi1 = (uint16_t)((((((a_hi << 8) | value2) & 0xFF) << 8) | 0) << 2) >> 8;
        bool carry1 = (uint16_t)((((((a_hi << 8) | value2) & 0xFF) << 8) | 0) << 1) & 0x8000;
        for (;;) {
            RAM8(0xA216) >>= 1;
            uint8_t value4 = RAM8(0xA216);
            RAM8(0xA216) >>= 1;
            a1 = (uint8_t)(a1 - 1);
            carry1 = value4 & 0x01;
            if (!(a1 != 0)) break;
        }
        a_hi2 = a_hi1;
        carry2 = carry1;
    }
    uint8_t value5 = RAM8(0xA216);
    uint8_t a_hi4;
    uint16_t x2;
    bool carry4;
    bool overflow2;
    if ((value5 & 1) == 0) {
        a_hi4 = a_hi2;
        x2 = (uint16_t)((((((a_hi << 8) | value2) & 0xFF) << 8) | 0) << 2);
        carry4 = carry2;
        overflow2 = overflow;
    } else {
        uint8_t a_hi3;
        uint16_t x1;
        bool carry3;
        bool overflow1;
        if ((value5 & 2) != 0) {
            RAM8(0xA212) |= 4;
            a_hi3 = a_hi2;
            x1 = (uint16_t)((((a_hi << 8) | value2) & 0xFF) << 8 << 2);
            carry3 = carry2;
            overflow1 = overflow;
        } else {
            a_hi3 = (uint16_t)((uint16_t)((((((a_hi << 8) | value2) & 0xFF) << 8) | 0) << 2) + 0x1000) >> 8;
            x1 = (uint16_t)((uint16_t)((((((a_hi << 8) | value2) & 0xFF) << 8) | 0) << 2) + 0x1000);
            carry3 = (uint16_t)((((((a_hi << 8) | value2) & 0xFF) << 8) | 0) << 2) + 0x1000 > 0xFFFF;
            overflow1 = (((uint16_t)((((((a_hi << 8) | value2) & 0xFF) << 8) | 0) << 2) ^ (uint16_t)((uint16_t)((((((a_hi << 8) | value2) & 0xFF) << 8) | 0) << 2) + 0x1000)) & ((uint16_t)((uint16_t)((((((a_hi << 8) | value2) & 0xFF) << 8) | 0) << 2) + 0x1000) ^ 0x1000) & 0x8000) != 0;
        }
        a_hi4 = a_hi3;
        x2 = x1;
        carry4 = carry3;
        overflow2 = overflow1;
    }
    r->a = (a_hi4 << 8) | a;
    r->x = x2;
    r->y = y;
    r->c = carry4;
    r->v = overflow2;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC7583C, SOM_RTS, "gen", select_save_slot_copy_and_reject_invalid_pair, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 62, 32)
