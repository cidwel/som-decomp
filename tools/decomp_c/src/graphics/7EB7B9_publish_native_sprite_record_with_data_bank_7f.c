#include "som_c.h"

/* 7EB7B9 publish_native_sprite_record_with_data_bank_7f   [class A, 18 bytes, 13 instructions]
 * Source: src/boot/publish_native_sprite_record_with_data_bank_7f.s
 * Documented in docs/boot-native-sprite-publish-wrapper.md
 * Entry: M=any X=16 bit DB=$7F D=any.  Callers read: BXYCV.
 */
static void publish_native_sprite_record_with_data_bank_7f(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7F, -1, 0)) return;
    const uint8_t m_entry = r->mf;
    const bool carry = r->c;
    const bool overflow = r->v;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->sp -= 4;
    JSR(c, 0xB7C6, 0x7EB53D); /* publish_native_sprite_record_to_shadow */
    r->sp += 4;
    r->c = carry;
    r->v = overflow;
    r->mf = m_entry;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EB7B9, SOM_RTS, "gen", publish_native_sprite_record_with_data_bank_7f, 0, L_B | L_X | L_Y | L_C | L_V, 5, -1, 0, 18, 13)
