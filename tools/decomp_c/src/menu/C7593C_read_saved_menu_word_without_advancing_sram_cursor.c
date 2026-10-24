#include "som_c.h"

/* C7593C read_saved_menu_word_without_advancing_sram_cursor   [class A, 12 bytes, 5 instructions]
 * Source: src/rom/read_saved_menu_word_without_advancing_sram_cursor.s
 * Documented in docs/ui-native-loaded-game-save-load.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: BV.
 */
static void read_saved_menu_word_without_advancing_sram_cursor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t x = r->x;
    const uint8_t db = r->db;
    uint16_t value = BUS16(c, 0x306000 + x);
    BUS16_SET(c, (db << 0x10) + 0xA23C, value);
    r->a = (r->a & 0x00FF) | ((value >> 8) << 8);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC7593C, SOM_RTS, "gen", read_saved_menu_word_without_advancing_sram_cursor, 0, L_B | L_V, 1, 1, 0, 12, 5)
