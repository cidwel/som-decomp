#include "som_c.h"

/* C75408 append_native_confirmation_hero_extra_statistics   [class B, 22 bytes, 9 instructions]
 * Source: src/rom/append_native_confirmation_hero_extra_statistics.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: BXYCV.
 */
static void append_native_confirmation_hero_extra_statistics(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    { const uint16_t sp_call = r->sp; JSR(c, 0x540A, 0xC75B86); GUARD_JSR(c, sp_call, 0x540A); } /* read_first_native_saved_hero_confirmation_statistic */
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x540D, 0xC75AFC); GUARD_JSR(c, sp_call, 0x540D); } /* format_and_append_native_saved_slot_decimal_pair */
    uint8_t db_ret = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret2 = r->xf;
    uint16_t a_all2 = r->a;
    uint16_t x_ret3 = r->x;
    uint16_t y_ret2 = r->y;
    BUS8_SET(c, (db_ret << 0x10) + 0x9C00 + x_ret3, 0xC1);
    if (x_ret2) {
        r->a = (a_all2 >> 8 << 8) | 0xC1;
        r->x = (uint8_t)((uint8_t)x_ret3 + 1);
        r->y = (uint8_t)y_ret2;
        r->z = (uint8_t)((uint8_t)x_ret3 + 1) == 0;
        r->n = (uint8_t)((uint8_t)x_ret3 + 1) & 0x80;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x5416, 0xC75389); GUARD_JSR(c, sp_call, 0x5416); } /* append_native_saved_slot_text_space_token */
        { const uint16_t sp_call = r->sp; JSR(c, 0x5419, 0xC75BA8); GUARD_JSR(c, sp_call, 0x5419); } /* read_second_native_saved_hero_confirmation_statistic */
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x541C, 0xC75AFC); GUARD_JSR(c, sp_call, 0x541C); } /* format_and_append_native_saved_slot_decimal_pair */
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        r->a = (a_all2 >> 8 << 8) | 0xC1;
        r->x = (uint16_t)(x_ret3 + 1);
        r->z = (uint16_t)(x_ret3 + 1) == 0;
        r->n = (uint16_t)(x_ret3 + 1) & 0x8000;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x5416, 0xC75389); GUARD_JSR(c, sp_call, 0x5416); } /* append_native_saved_slot_text_space_token */
        { const uint16_t sp_call = r->sp; JSR(c, 0x5419, 0xC75BA8); GUARD_JSR(c, sp_call, 0x5419); } /* read_second_native_saved_hero_confirmation_statistic */
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x541C, 0xC75AFC); GUARD_JSR(c, sp_call, 0x541C); } /* format_and_append_native_saved_slot_decimal_pair */
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC75408, SOM_RTS, "gen", append_native_confirmation_hero_extra_statistics, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 22, 9)
