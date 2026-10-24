#include "som_c.h"

/* C1397D classify_spell_entity_facing   [class B, 36 bytes, 20 instructions]
 * Source: src/rom/classify_spell_entity_facing.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: AXY.
 */
static void classify_spell_entity_facing(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    uint8_t value = RAM8(0x0010 + y);
    uint8_t a3;
    if (value == 0) {
        a3 = 0xC0;
    } else {
        uint8_t a2;
        if (value == 1) {
            a2 = 0x40;
        } else {
            uint8_t a1;
            if (value == 2) {
                a1 = 0;
            } else {
                a1 = 0x80;
            }
            a2 = a1;
        }
        a3 = a2;
    }
    SET_A8(r, a3);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1397D, SOM_RTS, "gen", classify_spell_entity_facing, 0, L_A | L_X | L_Y, 3, 1, 0, 36, 20)
