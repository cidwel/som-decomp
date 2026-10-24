#include "som_c.h"

/* C75AED append_native_saved_slot_level_label   [class C, 42 bytes, 18 instructions]
 * Source: src/rom/append_native_saved_slot_level_label.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZV.
 */
static void append_native_saved_slot_level_label(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5AEF, 0xC75389); GUARD_JSR(c, sp_call, 0x5AEF); } /* append_native_saved_slot_text_space_token */
    uint8_t db_ret = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t x_ret2 = r->x;
    BUS8_SET(c, (db_ret << 0x10) + 0x9C00 + x_ret2, 0xA6);
    BUS8_SET(c, (db_ret << 0x10) + 0xA177, 0);
    if (x_ret) {
        r->a = (a_all >> 8 << 8) | 0xA6;
        r->x = (uint8_t)((uint8_t)x_ret2 + 1);
        r->y = (uint8_t)y;
        r->z = (uint8_t)((uint8_t)x_ret2 + 1) == 0;
        r->n = (uint8_t)((uint8_t)x_ret2 + 1) & 0x80;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x5AFB, 0xC75B25); GUARD_JSR(c, sp_call, 0x5AFB); } /* read_native_saved_slot_character_level */
        r->mf = 1;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x5AFE, 0xC75D17); GUARD_JSR(c, sp_call, 0x5AFE); } /* format_five_native_saved_slot_decimal_digits_via_hardware_division */
        uint8_t db_ret2 = r->db;
        uint8_t x_ret4 = r->x;
        uint8_t value = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA238);
        if (value != 0) {
            BUS8_SET(c, (db_ret2 << 0x10) + 0x9C00 + x_ret4, value);
        } else {
            BUS8_SET(c, (db_ret2 << 0x10) + 0x9C00 + x_ret4, 0x80);
        }
        uint8_t value2 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA239);
        BUS8_SET(c, (db_ret2 << 0x10) + 0x9C00 + (uint8_t)(x_ret4 + 1), value2);
        SET_A8(r, value2);
        r->x = (uint8_t)(x_ret4 + 2);
        r->z = (uint8_t)(x_ret4 + 2) == 0;
        r->mf = 1;
        r->xf = 1;
        RETURN_RTS(c);
    } else {
        r->a = (a_all >> 8 << 8) | 0xA6;
        r->x = (uint16_t)(x_ret2 + 1);
        r->z = (uint16_t)(x_ret2 + 1) == 0;
        r->n = (uint16_t)(x_ret2 + 1) & 0x8000;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x5AFB, 0xC75B25); GUARD_JSR(c, sp_call, 0x5AFB); } /* read_native_saved_slot_character_level */
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x5AFE, 0xC75D17); GUARD_JSR(c, sp_call, 0x5AFE); } /* format_five_native_saved_slot_decimal_digits_via_hardware_division */
        uint8_t db_ret3 = r->db;
        uint16_t x_ret6 = r->x;
        uint8_t value3 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xA238);
        if (value3 != 0) {
            BUS8_SET(c, (db_ret3 << 0x10) + 0x9C00 + x_ret6, value3);
        } else {
            BUS8_SET(c, (db_ret3 << 0x10) + 0x9C00 + x_ret6, 0x80);
        }
        uint8_t value4 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xA239);
        BUS8_SET(c, (db_ret3 << 0x10) + 0x9C00 + (uint16_t)(x_ret6 + 1), value4);
        SET_A8(r, value4);
        r->x = (uint16_t)(x_ret6 + 2);
        r->z = (uint16_t)(x_ret6 + 2) == 0;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC75AED, SOM_RTS, "gen", append_native_saved_slot_level_label, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 1, 0, 42, 18)
