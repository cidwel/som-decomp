#include "som_c.h"

/* D0DA60 build_native_three_actor_menu_target_list_and_count   [class B, 65 bytes, 28 instructions]
 * Source: src/rom/build_native_three_actor_menu_target_list_and_count.s
 * Documented in docs/event-menu-target-eligibility.md
 * Entry: M=8 bit X=any DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void build_native_three_actor_menu_target_list_and_count(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint8_t value = RAM8(0x1842);
    uint16_t x1;
    if ((value & 1) != 0) {
        x1 = 0xFFFF;
    } else {
        x1 = 0xFFFE;
    }
    RAM16_SET(0x1818, x1);
    uint16_t x2;
    if (!(value & 0x80)) {
        x2 = 0xE000;
    } else {
        x2 = 0xE600;
    }
    RAM16_SET(0x1834, 0);
    r->x = x2;
    r->y = 0x1812;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0xDA87, 0xD0DAA1); /* test_one_native_menu_target_actor_and_advance_target_cursor */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0xDA8A, 0xD0DAA1); /* test_one_native_menu_target_actor_and_advance_target_cursor */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0xDA8D, 0xD0DAA1); /* test_one_native_menu_target_actor_and_advance_target_cursor */
    uint16_t value2 = RAM16(0x1834);
    if ((uint16_t)((value2 & 0xFF) - 1) == 0) {
        RAM16_SET(0x1818, 0xFFFE);
    }
    r->a = (uint16_t)((uint16_t)((value2 & 0xFF) - 1) + 1);
    r->z = (uint16_t)((uint16_t)((value2 & 0xFF) - 1) + 1) == 0;
    r->n = (uint16_t)((uint16_t)((value2 & 0xFF) - 1) + 1) & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xD0DA60, SOM_RTL, "gen", build_native_three_actor_menu_target_list_and_count, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 1, -1, 65, 28)
