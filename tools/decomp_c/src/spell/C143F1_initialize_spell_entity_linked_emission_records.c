#include "som_c.h"

/* C143F1 initialize_spell_entity_linked_emission_records   [class B, 108 bytes, 53 instructions]
 * Source: src/rom/initialize_spell_entity_linked_emission_records.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$01CC.  Callers read: BXYCZNV.
 */
static void initialize_spell_entity_linked_emission_records(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x01CC) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 1;
    RAM8(0x0000 + sp0 - 1) = 0xCC;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 5) = 0x7E;
    RAM8(0x0000 + sp0 - 6) = 0x7E;
    r->a = 0;
    r->x = 0x60;
    r->z = 0;
    r->n = 0;
    r->dp = (uint16_t)(sp0 - 5);
    r->sp -= 6;
    { const uint16_t sp_call = r->sp; JSR(c, 0x4409, 0xC13D48); GUARD_JSR(c, sp_call, 0x4409); } /* allocate_and_fill_spell_entity_heap_bytes */
    r->sp += 6;
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t x_ret2 = r->x;
    if (x_ret) {
        RAM8(0x8432) = (uint8_t)x_ret2;
        RAM8(0x0000 + (uint8_t)x_ret2) = 0x0F;
        RAM8(0x0030 + (uint8_t)x_ret2) = 0x30;
        RAM8(0x0032 + (uint8_t)x_ret2) = 0xE0;
        c->fail = 3; /* operand size does not fit the register width on this path */
        return;
    } else {
        RAM16_SET(0x8432, x_ret2);
        RAM8(0x0000 + x_ret2) = 0x0F;
        RAM8(0x0030 + x_ret2) = 0x30;
        RAM8(0x0032 + x_ret2) = 0xE0;
        r->a = (a_all >> 8 << 8) | 0xE0;
        r->x = 0x0100;
        r->z = 0;
        r->n = 0;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 6;
        { const uint16_t sp_call = r->sp; JSR(c, 0x4423, 0xC13D29); GUARD_JSR(c, sp_call, 0x4423); } /* allocate_spell_entity_heap_bytes */
        r->sp += 6;
        uint8_t db_ret = r->db;
        bool x_ret3 = r->xf;
        uint16_t x_ret4 = r->x;
        if (x_ret3) {
            BUS8_SET(c, (db_ret << 0x10) + 0x8426, (uint8_t)x_ret4);
            BUS16_SET(c, (db_ret << 0x10) + 0x8428, (uint8_t)x_ret4 + 4);
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        } else {
            BUS16_SET(c, (db_ret << 0x10) + 0x8426, x_ret4);
            BUS16_SET(c, (db_ret << 0x10) + 0x8428, (uint16_t)(x_ret4 + 4));
            uint8_t a1 = (uint8_t)(x_ret4 + 4);
            uint8_t a_hi1 = (uint16_t)(x_ret4 + 4) >> 8;
            uint16_t x1 = (uint16_t)(x_ret4 + 4);
            uint16_t y1 = 0x3E;
            for (;;) {
                BUS16_SET(c, (db_ret << 0x10) + x1, (uint16_t)(((a_hi1 << 8) | a1) + 4));
                uint8_t a1_next = (uint8_t)(((a_hi1 << 8) | a1) + 4);
                uint8_t a_hi1_next = (uint16_t)(((a_hi1 << 8) | a1) + 4) >> 8;
                uint16_t x1_next = (uint16_t)(((a_hi1 << 8) | a1) + 4);
                uint16_t y1_next = (uint16_t)(y1 - 1);
                a1 = a1_next;
                a_hi1 = a_hi1_next;
                x1 = x1_next;
                y1 = y1_next;
                if (!(y1 != 0)) break;
            }
            BUS16_SET(c, (db_ret << 0x10) + x1, 0);
            BUS16_SET(c, (db_ret << 0x10) + 0x842E, 0);
            BUS16_SET(c, (db_ret << 0x10) + 0x8430, 0x842E);
            BUS16_SET(c, (db_ret << 0x10) + 0x842A, 0);
            BUS16_SET(c, (db_ret << 0x10) + 0x842C, 0x842A);
            uint8_t value = RAM8(0x0000 + sp0 - 5);
            uint8_t value3 = RAM8(0x0000 + sp0 - 3);
            uint8_t value4 = RAM8(0x0000 + sp0 - 2);
            uint8_t value5 = RAM8(0x0000 + sp0 - 1);
            uint8_t value6 = RAM8(0x0000 + sp0);
            r->a = (0x84 << 8) | value3;
            r->x = x1;
            r->y = y1;
            r->c = value4 & 0x01;
            r->z = ((value6 << 8) | value5) == 0;
            r->n = ((value6 << 8) | value5) & 0x8000;
            r->v = value4 & 0x40;
            r->mf = value4 & 0x20;
            r->xf = value4 & 0x10;
            r->db = value;
            r->dp = (value6 << 8) | value5;
            r->i = value4 & 0x04;
            r->d = value4 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    }
}
SOM_REGISTER(0xC143F1, SOM_RTS, "gen", initialize_spell_entity_linked_emission_records, 0, L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 7, 0, 0, 108, 53)
