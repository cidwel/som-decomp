#include "som_c.h"

/* C76CEB adjust_native_menu_icon_position_for_name_page   [class A, 44 bytes, 22 instructions]
 * Source: src/rom/adjust_native_menu_icon_position_for_name_page.s
 * Documented in docs/event-menu-page-sprites.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void adjust_native_menu_icon_position_for_name_page(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const bool overflow = r->v;
    uint8_t value = RAM8(0xA202);
    bool carry1;
    bool overflow1;
    if (value != 4) {
        carry1 = value >= 4;
        overflow1 = overflow;
    } else {
        uint8_t value2 = RAM8(0xA136);
        RAM8(0xA15A) = ((value2 & 3) << 1 << 1) + 6;
        RAM8(0xA159) = (uint8_t)((value2 & 0xFC) + 6);
        uint8_t value3 = RAM8(0xA22B);
        if (value3 == 2) {
            RAM8(0xA15A)--;
            RAM8(0xA159)++;
        }
        carry1 = value3 >= 2;
        overflow1 = (((value2 & 0xFC) ^ (uint8_t)((value2 & 0xFC) + 6)) & ((uint8_t)((value2 & 0xFC) + 6) ^ 6) & 0x80) != 0;
    }
    r->c = carry1;
    r->v = overflow1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC76CEB, SOM_RTS, "gen", adjust_native_menu_icon_position_for_name_page, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 44, 22)
