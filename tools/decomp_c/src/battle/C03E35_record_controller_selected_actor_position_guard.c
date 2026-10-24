#include "som_c.h"

/* C03E35 record_controller_selected_actor_position_guard   [class B, 75 bytes, 41 instructions]
 * Source: src/rom/record_controller_selected_actor_position_guard.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=any D=$0000.  Callers read: nothing.
 */
static void record_controller_selected_actor_position_guard(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t db = r->db;
    uint8_t value = BUS8(c, (db << 0x10) + 0xD9);
    if (value & 0x80) {
        uint8_t a1;
        if ((uint8_t)((value & 0x0F) - 1) != 3) {
            a1 = (uint8_t)((value & 0x0F) - 1);
        } else {
            a1 = (uint8_t)((value & 0x0F) - 2);
        }
        RAM8(BATTLE_TEMP_A4) = a1;
        uint8_t value2 = BUS8(c, (db << 0x10) + 0xE1B1 + (((uint8_t)(a1 << 1) << 8) | 0));
        BUS8_SET(c, (db << 0x10) + 0xE1B1 + (((uint8_t)(a1 << 1) << 8) | 0), value2 | 0x20);
        uint8_t battle_temp_a4 = RAM8(BATTLE_TEMP_A4);
        uint16_t value3 = BUS16(c, (db << 0x10) + 0xE002 + (((uint8_t)(a1 << 1) << 8) | 0));
        BUS16_SET(c, (db << 0x10) + 0xFF86 + (uint8_t)(battle_temp_a4 << 2), value3);
        uint16_t value4 = BUS16(c, (db << 0x10) + 0xE004 + (((uint8_t)(a1 << 1) << 8) | 0));
        BUS16_SET(c, (db << 0x10) + 0xFF88 + (uint8_t)(battle_temp_a4 << 2), value4);
    } else {
        uint8_t value5 = BUS8(c, (db << 0x10) + 0xDA);
        if (value5 & 0x80) {
            uint8_t a2;
            if ((uint8_t)((value5 & 0x0F) - 1) != 3) {
                a2 = (uint8_t)((value5 & 0x0F) - 1);
            } else {
                a2 = (uint8_t)((value5 & 0x0F) - 2);
            }
            RAM8(BATTLE_TEMP_A4) = a2;
            uint8_t value6 = BUS8(c, (db << 0x10) + 0xE1B1 + (((uint8_t)(a2 << 1) << 8) | 0));
            BUS8_SET(c, (db << 0x10) + 0xE1B1 + (((uint8_t)(a2 << 1) << 8) | 0), value6 | 0x20);
            uint8_t battle_temp_a42 = RAM8(BATTLE_TEMP_A4);
            uint16_t value7 = BUS16(c, (db << 0x10) + 0xE002 + (((uint8_t)(a2 << 1) << 8) | 0));
            BUS16_SET(c, (db << 0x10) + 0xFF86 + (uint8_t)(battle_temp_a42 << 2), value7);
            uint16_t value8 = BUS16(c, (db << 0x10) + 0xE004 + (((uint8_t)(a2 << 1) << 8) | 0));
            BUS16_SET(c, (db << 0x10) + 0xFF88 + (uint8_t)(battle_temp_a42 << 2), value8);
        } else {
            uint8_t value9 = BUS8(c, (db << 0x10) + 0xDB);
            if (value9 & 0x80) {
                uint8_t a3;
                if ((uint8_t)((value9 & 0x0F) - 1) != 3) {
                    a3 = (uint8_t)((value9 & 0x0F) - 1);
                } else {
                    a3 = (uint8_t)((value9 & 0x0F) - 2);
                }
                RAM8(BATTLE_TEMP_A4) = a3;
                uint8_t value10 = BUS8(c, (db << 0x10) + 0xE1B1 + (((uint8_t)(a3 << 1) << 8) | 0));
                BUS8_SET(c, (db << 0x10) + 0xE1B1 + (((uint8_t)(a3 << 1) << 8) | 0), value10 | 0x20);
                uint8_t battle_temp_a43 = RAM8(BATTLE_TEMP_A4);
                uint16_t value11 = BUS16(c, (db << 0x10) + 0xE002 + (((uint8_t)(a3 << 1) << 8) | 0));
                BUS16_SET(c, (db << 0x10) + 0xFF86 + (uint8_t)(battle_temp_a43 << 2), value11);
                uint16_t value12 = BUS16(c, (db << 0x10) + 0xE004 + (((uint8_t)(a3 << 1) << 8) | 0));
                BUS16_SET(c, (db << 0x10) + 0xFF88 + (uint8_t)(battle_temp_a43 << 2), value12);
            }
        }
    }
    RETURN_RTL(c);
}
SOM_REGISTER(0xC03E35, SOM_RTL, "gen", record_controller_selected_actor_position_guard, 0, 0, 4, 0, 0, 75, 41)
