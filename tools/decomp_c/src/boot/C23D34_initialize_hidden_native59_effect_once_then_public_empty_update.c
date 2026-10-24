#include "som_c.h"

/* C23D34 initialize_hidden_native59_effect_once_then_public_empty_update   [class A, 20 bytes, 9 instructions]
 * Source: src/rom/initialize_hidden_native59_effect_once_then_public_empty_update.s
 * Documented in docs/boss-native59-hidden-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_hidden_native59_effect_once_then_public_empty_update(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(OBJECT_PHASE + x);
    if (value != 0) {
        JSL(c, 0x3D45, 0xC000A2); /* jump_public_hidden_effect_empty_update */
        r->a = value;
        r->c = 0;
        r->z = value == 0;
        r->n = value & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    RAM16_SET(OBJECT_PHASE + x, (uint16_t)(RAM16(OBJECT_PHASE + x) + 1));
    uint16_t value2 = RAM16(OBJECT_PHASE + x);
    r->a = value;
    r->z = value2 == 0;
    r->n = value2 & 0x8000;
    JSL(c, 0x3D3F, 0xC0009F); /* jump_public_hidden_effect_initializer */
    r->c = 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23D34, SOM_RTS, "gen", initialize_hidden_native59_effect_once_then_public_empty_update, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 20, 9)
