#include "som_c.h"

/* C1286C allocate_spell_entity_actor_group   [class B, 42 bytes, 26 instructions]
 * Source: src/rom/allocate_spell_entity_actor_group.s
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void allocate_spell_entity_actor_group(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = db;
    RAM8(0x0000 + sp0 - 4) = 0x7E;
    uint16_t value = RAM16(0x8216);
    uint8_t a_hi1 = a_hi;
    uint16_t y1 = 0x20;
    for (;;) {
        uint8_t value2 = RAM8(0x0000 + value);
        uint16_t y2;
        if (value2 == 0) {
            y2 = y1;
        } else {
            if ((uint16_t)(y1 - 1) != 0) {
                y1 = (uint16_t)(y1 - 1);
                continue;
            }
            y2 = (uint16_t)(y1 - 1);
        }
        y1 = y2;
        break;
    }
    if ((uint8_t)y1 != 0) {
        RAM8(0x0000 + value)++;
    }
    uint8_t value3 = RAM8(0x0000 + sp0 - 3);
    uint8_t value4 = RAM8(0x0000 + sp0 - 2);
    uint8_t value5 = RAM8(0x0000 + sp0 - 1);
    uint8_t value6 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | (uint8_t)(((uint8_t)((uint8_t)y1 - 0x20) ^ 0xFF) + 2);
    r->x = value;
    r->y = y1;
    r->c = value4 & 0x01;
    r->z = ((value6 << 8) | value5) == 0;
    r->n = ((value6 << 8) | value5) & 0x8000;
    r->v = value4 & 0x40;
    r->mf = value4 & 0x20;
    r->xf = value4 & 0x10;
    r->db = value3;
    r->dp = (value6 << 8) | value5;
    r->i = value4 & 0x04;
    r->d = value4 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1286C, SOM_RTS, "gen", allocate_spell_entity_actor_group, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 1, 0, 42, 26)
