#include "som_c.h"

/* C76619 append_native_spell_percentage_from_actor_skill_field   [class B, 53 bytes, 25 instructions]
 * Source: src/rom/append_native_spell_percentage_from_actor_skill_field.s
 * Documented in docs/ui-native-spell-item-labels.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXCV.
 */
static void append_native_spell_percentage_from_actor_skill_field(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0xA171, 0x50);
    r->sp -= 2;
    JSR(c, 0x6622, 0xC766BF); /* derive_native_selected_actor_field_offset */
    r->sp += 2;
    uint16_t x_ret = r->x;
    uint8_t value = RAM8(0xE180 + x_ret);
    uint16_t value2 = RAM16(0x19FE);
    uint16_t value3 = RAM16(0xA175);
    r->a = value;
    r->x = (uint16_t)((((value2 & 0xFF) << 8) | 0) << 1);
    r->y = value3 & 0xFF;
    r->c = (((value2 & 0xFF) << 8) | 0) & 0x8000;
    r->z = value == 0;
    r->n = value & 0x80;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 2;
    JSL(c, 0x6640, 0xC00063); /* jump_native_spell_skill_percentage_api */
    r->sp += 2;
    uint16_t a_all2 = r->a;
    r->a = a_all2 & 0xFF;
    r->x = x;
    r->y = a_all2 & 0xFF;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x664C, 0xC75AFC); /* format_and_append_native_saved_slot_decimal_pair */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC76619, SOM_RTS, "gen", append_native_spell_percentage_from_actor_skill_field, 0, L_A | L_B | L_X | L_C | L_V, 3, 1, 0, 53, 25)
