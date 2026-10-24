#include "som_c.h"

/* C767E6 divide_native_status_bar_and_publish_selected_actor_vram   [class D, 57 bytes, 29 instructions]
 * Source: src/rom/divide_native_status_bar_and_publish_selected_actor_vram.s
 * Documented in docs/ui-native-party-status-page.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BCV.
 */
static void divide_native_status_bar_and_publish_selected_actor_vram(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    r->a = (a_hi << 8) | 0x10;
    r->db = 0;
    r->sp -= 1;
    JSR(c, 0x67EF, 0xC76BA5); /* divide_native_status_field_and_return_hardware_quotient */
    r->sp += 1;
    uint16_t value = RAM16(0xA1C7);
    BUS16_SET(c, 0x002116, value);
    uint16_t value2 = RAM16(0x19FE);
    uint16_t value3 = BUS16(c, 0x004216);
    r->a = value3;
    r->x = (uint16_t)((uint16_t)((((uint8_t)((value2 & 0xFF) + 3) << 8) | ((value2 & 0xFF) + 3 >> 8)) << 2) + 0x204E);
    r->mf = 0;
    r->xf = 0;
    r->sp -= 3;
    JSR(c, 0x6811, 0xC7681F); /* publish_native_status_bar_full_tiles_and_fractional_tail */
    r->sp += 3;
    RAM16_SET(0xA1C7, (uint16_t)(value + 0x40));
    r->a = (r->a & 0x00FF) | (((uint16_t)(value + 0x40) >> 8) << 8);
    r->c = value + 0x40 > 0xFFFF;
    r->v = ((value ^ (uint16_t)(value + 0x40)) & ((uint16_t)(value + 0x40) ^ 0x40) & 0x8000) != 0;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC767E6, SOM_RTS, "gen", divide_native_status_bar_and_publish_selected_actor_vram, 0, L_B | L_C | L_V, 3, 1, 0, 57, 29)
