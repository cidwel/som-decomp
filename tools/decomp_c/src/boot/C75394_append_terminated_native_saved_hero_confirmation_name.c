#include "som_c.h"

/* C75394 append_terminated_native_saved_hero_confirmation_name   [class B, 52 bytes, 28 instructions]
 * Source: src/rom/append_terminated_native_saved_hero_confirmation_name.s
 * Documented in docs/ui-native-saved-game-menu-request.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void append_terminated_native_saved_hero_confirmation_name(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    r->y = x;
    r->mf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5399, 0xC75D00); GUARD_JSR(c, sp_call, 0x5399); } /* derive_selected_save_slot_primary_or_backup_offset */
    uint16_t x_ret = r->x;
    RAM16_SET(0xA171, x_ret);
    uint16_t value = RAM16(0xA177);
    RAM16_SET(0xA173, (value & 0xFF) << 1 << 1);
    uint16_t value2 = RAM16(0xA173);
    uint16_t value3 = RAM16(0xA171);
    uint8_t a1 = 0x0C;
    uint8_t a_hi1 = (uint16_t)((uint16_t)(((value & 0xFF) << 1 << 1 << 1) + value2) + value3) >> 8;
    uint16_t x1 = (uint16_t)((uint16_t)(((value & 0xFF) << 1 << 1 << 1) + value2) + value3);
    uint16_t y1 = x;
    for (;;) {
        uint8_t value4 = BUS8(c, 0x306003 + x1);
        RAM8(0x9C00 + y1) = value4;
        uint8_t a_hi2;
        uint16_t y2;
        if (value4 == 0) {
            a_hi2 = a1;
            y2 = y1;
        } else {
            if ((uint8_t)(a1 - 1) != 0) {
                a1 = (uint8_t)(a1 - 1);
                a_hi1 = value4;
                x1 = (uint16_t)(x1 + 1);
                y1 = (uint16_t)(y1 + 1);
                continue;
            }
            a_hi2 = value4;
            y2 = (uint16_t)(y1 + 1);
        }
        a_hi1 = a_hi2;
        y1 = y2;
        break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = y1;
    r->y = y1;
    r->c = (uint16_t)(((value & 0xFF) << 1 << 1 << 1) + value2) + value3 > 0xFFFF;
    r->v = (((uint16_t)(((value & 0xFF) << 1 << 1 << 1) + value2) ^ (uint16_t)((uint16_t)(((value & 0xFF) << 1 << 1 << 1) + value2) + value3)) & (value3 ^ (uint16_t)((uint16_t)(((value & 0xFF) << 1 << 1 << 1) + value2) + value3)) & 0x8000) != 0;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC75394, SOM_RTS, "gen", append_terminated_native_saved_hero_confirmation_name, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 52, 28)
