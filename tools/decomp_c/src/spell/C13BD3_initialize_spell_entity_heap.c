#include "som_c.h"

/* C13BD3 initialize_spell_entity_heap   [class B, 49 bytes, 27 instructions]
 * Source: src/rom/initialize_spell_entity_heap.s
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: BXYCZNV.
 */
static void initialize_spell_entity_heap(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7E;
    RAM8(0x0000 + sp0 - 4) = 0x7E;
    RAM8(0x0000 + sp0 - 4) = x >> 8;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)x;
    r->a = (a >> 8 << 8) | 0;
    r->x = 0x8200;
    r->y = x;
    r->z = 1;
    r->n = 0;
    r->mf = 1;
    r->sp -= 6;
    { const uint16_t sp_call = r->sp; JSR(c, 0x3BE7, 0xC14738); GUARD_JSR(c, sp_call, 0x3BE7); } /* fill_native_entity_memory_bytes */
    r->sp += 6;
    bool x_ret = r->xf;
    uint16_t y_ret = r->y;
    if (x_ret) {
        uint8_t value = RAM8(0x0000 + sp0 - 5);
        r->x = value;
        r->y = (uint8_t)y_ret;
        r->z = value == 0;
        r->n = value & 0x80;
        r->xf = 1;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0x3BEB, 0xC13D29); GUARD_JSR(c, sp_call, 0x3BEB); } /* allocate_spell_entity_heap_bytes */
        r->sp += 5;
        uint8_t db_ret = r->db;
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t value2 = BUS16_RDP(c, (db_ret << 0x10) + 0x8238);
        RAM8(0x0000 + sp0 - 5) = value2 >> 8;
        RAM8(0x0000 + sp0 - 6) = (uint8_t)value2;
        BUS16_SET(c, (db_ret << 0x10) + 0x8238, 0x38);
        r->x = 0x125F;
        r->z = 0;
        r->n = 0;
        r->sp -= 7;
        { const uint16_t sp_call = r->sp; JSR(c, 0x3BFB, 0xC13D29); GUARD_JSR(c, sp_call, 0x3BFB); } /* allocate_spell_entity_heap_bytes */
        r->sp += 7;
        uint8_t db_ret2 = r->db;
        bool x_ret4 = r->xf;
        uint16_t y_ret3 = r->y;
        if (x_ret4) {
            uint8_t value3 = RAM8(0x0000 + sp0 - 6);
            BUS8_SET(c, (db_ret2 << 0x10) + 0x8238, value3);
            uint8_t value4 = RAM8(0x0000 + sp0 - 5);
            uint8_t value5 = RAM8(0x0000 + sp0 - 4);
            uint8_t value6 = RAM8(0x0000 + sp0 - 3);
            uint8_t value7 = RAM8(0x0000 + sp0 - 2);
            uint8_t value8 = RAM8(0x0000 + sp0 - 1);
            uint8_t value9 = RAM8(0x0000 + sp0);
            r->x = value3;
            r->y = (uint8_t)y_ret3;
            r->c = value5 & 0x01;
            r->z = ((value7 << 8) | value6) == 0;
            r->n = ((value7 << 8) | value6) & 0x8000;
            r->v = value5 & 0x40;
            r->mf = value5 & 0x20;
            r->xf = value5 & 0x10;
            r->db = value4;
            r->dp = (value7 << 8) | value6;
            r->i = value5 & 0x04;
            r->d = value5 & 0x08;
            TAIL_CALL_DYN(c, 0xC10000 | (uint16_t)(((value9 << 8) | value8) + 1), SOM_RTS); /* jump through a pushed address */
        } else {
            c->fail = 3;
            return;
        }
    } else {
        uint8_t value16 = RAM8(0x0000 + sp0 - 5);
        uint8_t value17 = RAM8(0x0000 + sp0 - 4);
        r->x = (value17 << 8) | value16;
        r->z = ((value17 << 8) | value16) == 0;
        r->n = ((value17 << 8) | value16) & 0x8000;
        r->xf = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x3BEB, 0xC13D29); GUARD_JSR(c, sp_call, 0x3BEB); } /* allocate_spell_entity_heap_bytes */
        r->sp += 4;
        uint8_t db_ret3 = r->db;
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t value18 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x8238);
        RAM8(0x0000 + sp0 - 4) = value18 >> 8;
        RAM8(0x0000 + sp0 - 5) = (uint8_t)value18;
        BUS16_SET(c, (db_ret3 << 0x10) + 0x8238, 0x38);
        r->x = 0x125F;
        r->z = 0;
        r->n = 0;
        r->sp -= 6;
        { const uint16_t sp_call = r->sp; JSR(c, 0x3BFB, 0xC13D29); GUARD_JSR(c, sp_call, 0x3BFB); } /* allocate_spell_entity_heap_bytes */
        r->sp += 6;
        uint8_t db_ret4 = r->db;
        bool x_ret7 = r->xf;
        if (x_ret7) {
            c->fail = 3;
            return;
        } else {
            uint8_t value24 = RAM8(0x0000 + sp0 - 5);
            uint8_t value25 = RAM8(0x0000 + sp0 - 4);
            BUS16_SET(c, (db_ret4 << 0x10) + 0x8238, (value25 << 8) | value24);
            uint8_t value26 = RAM8(0x0000 + sp0 - 3);
            uint8_t value27 = RAM8(0x0000 + sp0 - 2);
            uint8_t value28 = RAM8(0x0000 + sp0 - 1);
            uint8_t value29 = RAM8(0x0000 + sp0);
            r->x = (value25 << 8) | value24;
            r->c = value27 & 0x01;
            r->z = ((value29 << 8) | value28) == 0;
            r->n = ((value29 << 8) | value28) & 0x8000;
            r->v = value27 & 0x40;
            r->mf = value27 & 0x20;
            r->xf = value27 & 0x10;
            r->db = value26;
            r->dp = (value29 << 8) | value28;
            r->i = value27 & 0x04;
            r->d = value27 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    }
}
SOM_REGISTER(0xC13BD3, SOM_RTS, "gen", initialize_spell_entity_heap, SOM_UNWINDS, L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 7, 0, 0, 49, 27)
