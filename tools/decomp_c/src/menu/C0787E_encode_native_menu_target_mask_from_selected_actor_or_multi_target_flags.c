#include "som_c.h"

/* C0787E encode_native_menu_target_mask_from_selected_actor_or_multi_target_flags   [class B, 69 bytes, 33 instructions]
 * Source: src/rom/encode_native_menu_target_mask_from_selected_actor_or_multi_target_flags.s
 * Documented in docs/event-menu-action-rows.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: YCV.
 */
static void encode_native_menu_target_mask_from_selected_actor_or_multi_target_flags(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value2 = BUS16(c, (uint16_t)(0x0000 + RAM16(0x1822)));
    if (value2 == 0xFFFF) {
        uint16_t value3 = RAM16(0x1812);
        uint8_t a1;
        if (value3 == 0) {
            a1 = 0;
        } else {
            a1 = 1;
        }
        uint16_t value4 = RAM16(0x1814);
        uint8_t a2;
        if (value4 == 0) {
            a2 = a1;
        } else {
            a2 = a1 | 2;
        }
        uint16_t value5 = RAM16(0x1816);
        uint8_t a3;
        if (value5 == 0) {
            a3 = a2;
        } else {
            a3 = a2 | 4;
        }
        uint8_t value6 = RAM8(0x1842);
        uint8_t a4;
        if (!(value6 & 0x80)) {
            a4 = value6;
        } else {
            a4 = ((uint8_t)((value2 >> 8 << 8) | (a3 | 0x20)) & 7) | 0x40;
        }
        RAM8(0x19F3) = a4;
        r->c = value2 >= 0xFFFF;
        r->mf = 0;
        RETURN_RTS(c);
    }
    RAM8(0x19F3) = (uint8_t)((((uint8_t)(value2 & 0x0E00) << 8) | ((value2 & 0x0E00) >> 8)) >> 1);
    r->c = (((uint8_t)(value2 & 0x0E00) << 8) | ((value2 & 0x0E00) >> 8)) & 0x01;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0787E, SOM_RTS, "hand", encode_native_menu_target_mask_from_selected_actor_or_multi_target_flags, 0, L_Y | L_C | L_V, 1, 1, 0, 69, 33)
