#include "som_c.h"

/* C75A32 append_native_saved_slot_location_name   [class B, 85 bytes, 47 instructions]
 * Source: src/rom/append_native_saved_slot_location_name.s
 * Documented in docs/ui-native-loaded-game-slot-descriptions.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void append_native_saved_slot_location_name(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t value = RAM8(0xA216);
    uint8_t a_hi2;
    uint16_t x2;
    uint16_t y2;
    bool carry1;
    bool overflow1;
    if ((value & 3) == 3) {
        a_hi2 = a_hi;
        x2 = x;
        y2 = y;
        carry1 = (value & 3) >= 3;
        overflow1 = overflow;
    } else {
        r->a = a_hi << 8 | (value & 3);
        r->mf = 0;
        r->sp -= 2;
        JSR(c, 0x5A40, 0xC75D00); /* derive_selected_save_slot_primary_or_backup_offset */
        r->sp += 2;
        uint16_t x_ret = r->x;
        uint8_t value2 = BUS8(c, 0x306101 + x_ret);
        RAM8(0xA173) = (value2 & 0x0F) << 1 << 1 << 1 << 1;
        uint8_t value3 = BUS8(c, 0x306102 + x_ret);
        uint8_t value4 = RAM8(0xA173);
        uint16_t value5 = BUS16(c, 0xCA0B82 + (uint8_t)((uint8_t)(((value3 & 0xF0) >> 4) + value4) << 1));
        RAM8(0x9C00 + x) = 0x80;
        uint8_t a_hi1 = value5 >> 8;
        uint16_t x1 = (uint16_t)(x + 1);
        uint16_t y1 = value5;
        for (;;) {
            uint8_t value6 = BUS8(c, 0xCA0000 + y1);
            if (value6 != 0) {
                RAM8(0x9C00 + x1) = value6;
                x1 = (uint16_t)(x1 + 1);
                y1 = (uint16_t)(y1 + 1);
                continue;
            }
            break;
        }
        a_hi2 = a_hi1;
        x2 = x1;
        y2 = y1;
        carry1 = (uint8_t)(((value3 & 0xF0) >> 4) + value4) & 0x80;
        overflow1 = ((((value3 & 0xF0) >> 4) ^ (uint8_t)(((value3 & 0xF0) >> 4) + value4)) & (value4 ^ (uint8_t)(((value3 & 0xF0) >> 4) + value4)) & 0x80) != 0;
    }
    r->a = (a_hi2 << 8) | a;
    r->x = x2;
    r->y = y2;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC75A32, SOM_RTS, "gen", append_native_saved_slot_location_name, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 85, 47)
