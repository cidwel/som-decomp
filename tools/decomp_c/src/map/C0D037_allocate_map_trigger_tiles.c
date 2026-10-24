#include "som_c.h"

/* C0D037 allocate_map_trigger_tiles   [class B, 139 bytes, 71 instructions]
 * Source: src/rom/allocate_map_trigger_tiles.s
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: CV.
 */
static void allocate_map_trigger_tiles(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 0;
    RAM8(0x0000 + sp0 - 1) = 0x7F;
    RAM8(0x0012) = RAM8(0x009C);
    RAM8(0x0014) = RAM8(0x009D);
    RAM8(0x0013) = 0;
    RAM8(0x0015) = 0;
    uint16_t value3 = RAM16(0x00C8);
    RAM16_SET(0x0010, value3);
    RAM16_SET(0x0018, 0);
    uint8_t a_hi1 = value3 >> 8;
    uint16_t y1 = 0;
    bool carry1 = carry;
    bool overflow1 = overflow;
    for (;;) {
        uint16_t value4 = BUS16_RDP(c, RAM16(0x0010) + 0x7F0000 + y1);
        uint16_t value5 = RAM16(0x1B800 + ((value4 & 0xFF) << 1 << 1));
        if (!(value5 & 0x8000)) {
            uint16_t value6 = RAM16(0x0012);
            if ((uint16_t)(y1 + 1) < value6) {
                uint8_t a_hi1_next = value5 >> 8;
                uint16_t y1_next = (uint16_t)(y1 + 1);
                bool carry1_next = (uint16_t)(y1 + 1) >= value6;
                a_hi1 = a_hi1_next;
                y1 = y1_next;
                carry1 = carry1_next;
                continue;
            }
            uint16_t value7 = RAM16(0x0010);
            RAM16_SET(0x0010, (uint16_t)(value7 + 0x80));
            RAM16_SET(0x0014, (uint16_t)(RAM16(0x0014) - 1));
            if (RAM16(0x0014) != 0) {
                a_hi1 = (uint16_t)(value7 + 0x80) >> 8;
                y1 = 0;
                carry1 = value7 + 0x80 > 0xFFFF;
                overflow1 = ((value7 ^ (uint16_t)(value7 + 0x80)) & ((uint16_t)(value7 + 0x80) ^ 0x80) & 0x8000) != 0;
                continue;
            }
            a_hi1 = (uint16_t)(value7 + 0x80) >> 8;
            y1 = 0;
            carry1 = value7 + 0x80 > 0xFFFF;
            overflow1 = ((value7 ^ (uint16_t)(value7 + 0x80)) & ((uint16_t)(value7 + 0x80) ^ 0x80) & 0x8000) != 0;
            break;
        }
        r->a = value5;
        r->x = (value4 & 0xFF) << 1 << 1;
        r->y = y1;
        r->c = (value4 & 0xFF) << 1 & 0x8000;
        r->z = value5 == 0;
        r->n = value5 & 0x8000;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 0;
        r->db = 0x7F;
        r->dp = 0;
        r->sp -= 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0xD066, 0x02B517); GUARD_JSL(c, sp_call, 0xD066); } /* clone_first_layer_trigger_tile */
        r->sp += 1;
        uint16_t a_all = r->a;
        uint16_t y_ret = r->y;
        bool overflow_ret = r->v;
        uint16_t value8 = RAM16(0x0012);
        if ((uint16_t)(y_ret + 1) < value8) {
            a_hi1 = a_all >> 8;
            y1 = (uint16_t)(y_ret + 1);
            carry1 = (uint16_t)(y_ret + 1) >= value8;
            overflow1 = overflow_ret;
            continue;
        }
        uint16_t value9 = RAM16(0x0010);
        RAM16_SET(0x0010, (uint16_t)(value9 + 0x80));
        RAM16_SET(0x0014, (uint16_t)(RAM16(0x0014) - 1));
        if (RAM16(0x0014) != 0) {
            a_hi1 = (uint16_t)(value9 + 0x80) >> 8;
            y1 = 0;
            carry1 = value9 + 0x80 > 0xFFFF;
            overflow1 = ((value9 ^ (uint16_t)(value9 + 0x80)) & ((uint16_t)(value9 + 0x80) ^ 0x80) & 0x8000) != 0;
            continue;
        }
        a_hi1 = (uint16_t)(value9 + 0x80) >> 8;
        y1 = 0;
        carry1 = value9 + 0x80 > 0xFFFF;
        overflow1 = ((value9 ^ (uint16_t)(value9 + 0x80)) & ((uint16_t)(value9 + 0x80) ^ 0x80) & 0x8000) != 0;
        break;
    }
    uint8_t value10 = RAM8(0x00A0);
    if (value10 == 0) {
        uint8_t value11 = RAM8(0x0000 + sp0);
        r->c = carry1;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 1;
        r->db = value11;
        r->dp = 0;
        RETURN_RTS(c);
    }
    RAM8(0x0012) = value10;
    RAM8(0x0014) = RAM8(0x00A1);
    RAM8(0x0013) = 0;
    RAM8(0x0015) = 0;
    uint16_t value13 = RAM16(0x00CA);
    RAM16_SET(0x0010, value13);
    RAM16_SET(0x0018, 0);
    uint8_t a_hi2 = value13 >> 8;
    uint16_t y2 = 0;
    bool carry2 = carry1;
    bool overflow2 = overflow1;
    for (;;) {
        uint16_t value14 = BUS16_RDP(c, RAM16(0x0010) + 0x7F0000 + y2);
        uint16_t value15 = RAM16(0x1BC00 + ((value14 & 0xFF) << 1 << 1));
        if (!(value15 & 0x8000)) {
            uint16_t value16 = RAM16(0x0012);
            if ((uint16_t)(y2 + 1) < value16) {
                uint8_t a_hi2_next = value15 >> 8;
                uint16_t y2_next = (uint16_t)(y2 + 1);
                bool carry2_next = (uint16_t)(y2 + 1) >= value16;
                a_hi2 = a_hi2_next;
                y2 = y2_next;
                carry2 = carry2_next;
                continue;
            }
            uint16_t value17 = RAM16(0x0010);
            RAM16_SET(0x0010, (uint16_t)(value17 + 0x80));
            RAM16_SET(0x0014, (uint16_t)(RAM16(0x0014) - 1));
            if (RAM16(0x0014) != 0) {
                a_hi2 = (uint16_t)(value17 + 0x80) >> 8;
                y2 = 0;
                carry2 = value17 + 0x80 > 0xFFFF;
                overflow2 = ((value17 ^ (uint16_t)(value17 + 0x80)) & ((uint16_t)(value17 + 0x80) ^ 0x80) & 0x8000) != 0;
                continue;
            }
            a_hi2 = (uint16_t)(value17 + 0x80) >> 8;
            y2 = 0;
            carry2 = value17 + 0x80 > 0xFFFF;
            overflow2 = ((value17 ^ (uint16_t)(value17 + 0x80)) & ((uint16_t)(value17 + 0x80) ^ 0x80) & 0x8000) != 0;
            break;
        }
        r->a = value15;
        r->x = (value14 & 0xFF) << 1 << 1;
        r->y = y2;
        r->c = (value14 & 0xFF) << 1 & 0x8000;
        r->z = value15 == 0;
        r->n = value15 & 0x8000;
        r->v = overflow2;
        r->mf = 0;
        r->xf = 0;
        r->db = 0x7F;
        r->dp = 0;
        r->sp -= 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0xD0A9, 0x02B55A); GUARD_JSL(c, sp_call, 0xD0A9); } /* clone_second_layer_trigger_tile */
        r->sp += 1;
        uint16_t a_all2 = r->a;
        uint16_t y_ret2 = r->y;
        bool overflow_ret2 = r->v;
        uint16_t value18 = RAM16(0x0012);
        if ((uint16_t)(y_ret2 + 1) < value18) {
            a_hi2 = a_all2 >> 8;
            y2 = (uint16_t)(y_ret2 + 1);
            carry2 = (uint16_t)(y_ret2 + 1) >= value18;
            overflow2 = overflow_ret2;
            continue;
        }
        uint16_t value19 = RAM16(0x0010);
        RAM16_SET(0x0010, (uint16_t)(value19 + 0x80));
        RAM16_SET(0x0014, (uint16_t)(RAM16(0x0014) - 1));
        if (RAM16(0x0014) != 0) {
            a_hi2 = (uint16_t)(value19 + 0x80) >> 8;
            y2 = 0;
            carry2 = value19 + 0x80 > 0xFFFF;
            overflow2 = ((value19 ^ (uint16_t)(value19 + 0x80)) & ((uint16_t)(value19 + 0x80) ^ 0x80) & 0x8000) != 0;
            continue;
        }
        a_hi2 = (uint16_t)(value19 + 0x80) >> 8;
        y2 = 0;
        carry2 = value19 + 0x80 > 0xFFFF;
        overflow2 = ((value19 ^ (uint16_t)(value19 + 0x80)) & ((uint16_t)(value19 + 0x80) ^ 0x80) & 0x8000) != 0;
        break;
    }
    uint8_t value20 = RAM8(0x0000 + sp0);
    r->c = carry2;
    r->v = overflow2;
    r->mf = 1;
    r->xf = 1;
    r->db = value20;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0D037, SOM_RTS, "gen", allocate_map_trigger_tiles, 0, L_C | L_V, 2, 1, 1, 139, 71)
