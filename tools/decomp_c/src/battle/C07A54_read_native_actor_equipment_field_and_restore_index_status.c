#include "som_c.h"

/* C07A54 read_native_actor_equipment_field_and_restore_index_status   [class C, 41 bytes, 20 instructions]
 * Source: src/rom/read_native_actor_equipment_field_and_restore_index_status.s
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void read_native_actor_equipment_field_and_restore_index_status(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = x >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    uint8_t a2;
    if ((uint8_t)(x & 0x067F) != 0x63) {
        a2 = RAM8(0xE180 + (x & 0x067F));
    } else {
        uint8_t value2 = RAM8(0xE180 + (x & 0x067F));
        uint8_t a1;
        if (value2 < 0xF1) {
            a1 = value2;
        } else {
            a1 = RAM8(0xE185 + (x & 0x067F));
        }
        a2 = a1;
    }
    r->a = (((x & 0x067F) >> 8 << 8) | a2) & 0xFF;
    r->z = x == 0;
    r->n = x & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC07A54, SOM_RTS, "gen", read_native_actor_equipment_field_and_restore_index_status, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 3, 1, 0, 41, 20)
