#include "som_c.h"

/* C7592E unpack_saved_menu_word_and_advance_sram_cursor   [class A, 14 bytes, 7 instructions]
 * Source: src/rom/unpack_saved_menu_word_and_advance_sram_cursor.s
 * Documented in docs/ui-native-loaded-game-save-load.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: BXYCV.
 */
static void unpack_saved_menu_word_and_advance_sram_cursor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t x = r->x;
    const uint8_t db = r->db;
    uint16_t value = BUS16(c, 0x306000 + x);
    BUS16_SET(c, (db << 0x10) + 0xA25A, value);
    r->a = (r->a & 0x00FF) | ((value >> 8) << 8);
    r->x = (uint16_t)(x + 2);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC7592E, SOM_RTS, "gen", unpack_saved_menu_word_and_advance_sram_cursor, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 14, 7)
