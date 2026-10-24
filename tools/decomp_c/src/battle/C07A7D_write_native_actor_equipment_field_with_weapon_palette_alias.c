#include "som_c.h"

/* C07A7D write_native_actor_equipment_field_with_weapon_palette_alias   [class C, 56 bytes, 27 instructions]
 * Source: src/rom/write_native_actor_equipment_field_with_weapon_palette_alias.s
 * Documented in docs/event-menu-equipment-fields.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void write_native_actor_equipment_field_with_weapon_palette_alias(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    if ((uint8_t)(x & 0x067F) != 0x63) {
        RAM8(0xE180 + (x & 0x067F)) = (uint8_t)((a_hi << 8) | a);
    } else {
        if (RAM8(0xE180 + (x & 0x067F)) < 0xF1) {
            RAM8(0xE180 + (x & 0x067F)) = (uint8_t)((a_hi << 8) | a);
            RAM8(0xE185 + (x & 0x067F)) = (uint8_t)((a_hi << 8) | a);
        } else {
            RAM8(0xE185 + (x & 0x067F)) = (uint8_t)((a_hi << 8) | a);
        }
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC07A7D, SOM_RTS, "gen", write_native_actor_equipment_field_with_weapon_palette_alias, 0, L_B | L_X | L_Y | L_C | L_V, 5, 1, 0, 56, 27)
