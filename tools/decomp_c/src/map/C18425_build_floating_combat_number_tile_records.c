#include "som_c.h"

/* C18425 build_floating_combat_number_tile_records   [class B, 164 bytes, 98 instructions]
 * Source: src/rom/build_floating_combat_number_tile_records.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYV.
 */
static void build_floating_combat_number_tile_records(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8427, 0xC184C9); GUARD_JSR(c, sp_call, 0x8427); } /* split_floating_combat_number_into_decimal_fields */
    { const uint16_t sp_call = r->sp; JSR(c, 0x842A, 0xC1852B); GUARD_JSR(c, sp_call, 0x842A); } /* clear_sixteen_floating_number_tile_words */
    uint16_t a_all2 = r->a;
    uint16_t y_ret = r->y;
    RAM16_SET(0x0008, (uint16_t)((uint16_t)(x << 3) + 0x2800));
    uint16_t value = RAM16(0x001E);
    if (value >= 0x32) {
        uint8_t a_hi1;
        bool overflow1;
        if (value >= 0xC8) {
            a_hi1 = value >> 8;
            overflow1 = (((uint16_t)(x << 3) ^ (uint16_t)((uint16_t)(x << 3) + 0x2800)) & ((uint16_t)((uint16_t)(x << 3) + 0x2800) ^ 0x2800) & 0x8000) != 0;
        } else {
            uint16_t value2 = RAM16(0x0008);
            RAM16_SET(0x0008, (uint16_t)(value2 + 0x0280));
            a_hi1 = (uint16_t)(value2 + 0x0280) >> 8;
            overflow1 = ((value2 ^ (uint16_t)(value2 + 0x0280)) & ((uint16_t)(value2 + 0x0280) ^ 0x0280) & 0x8000) != 0;
        }
        uint16_t value3 = RAM16(0x0004);
        uint8_t a_hi2;
        bool overflow2;
        if (value3 & 0x8000) {
            a_hi2 = value3 >> 8;
            overflow2 = overflow1;
        } else {
            uint16_t value4 = RAM16(0x0008);
            RAM16_SET(0x0000 + y_ret, (uint16_t)((uint16_t)(value3 << 6) + value4));
            RAM16_SET(0x0004 + y_ret, (uint16_t)((uint16_t)((uint16_t)(value3 << 6) + value4) + 0x20));
            a_hi2 = (uint16_t)((uint16_t)((uint16_t)(value3 << 6) + value4) + 0x20) >> 8;
            overflow2 = (((uint16_t)((uint16_t)(value3 << 6) + value4) ^ (uint16_t)((uint16_t)((uint16_t)(value3 << 6) + value4) + 0x20)) & ((uint16_t)((uint16_t)((uint16_t)(value3 << 6) + value4) + 0x20) ^ 0x20) & 0x8000) != 0;
        }
        uint16_t value5 = RAM16(0x0002);
        uint8_t a_hi3;
        bool overflow3;
        if (value5 & 0x8000) {
            a_hi3 = value5 >> 8;
            overflow3 = overflow2;
        } else {
            uint16_t value6 = RAM16(0x0008);
            RAM16_SET(0x0008 + y_ret, (uint16_t)((uint16_t)(value5 << 6) + value6));
            RAM16_SET(0x000C + y_ret, (uint16_t)((uint16_t)((uint16_t)(value5 << 6) + value6) + 0x20));
            a_hi3 = (uint16_t)((uint16_t)((uint16_t)(value5 << 6) + value6) + 0x20) >> 8;
            overflow3 = (((uint16_t)((uint16_t)(value5 << 6) + value6) ^ (uint16_t)((uint16_t)((uint16_t)(value5 << 6) + value6) + 0x20)) & ((uint16_t)((uint16_t)((uint16_t)(value5 << 6) + value6) + 0x20) ^ 0x20) & 0x8000) != 0;
        }
        uint16_t value7 = RAM16(0x0000);
        uint8_t a_hi4;
        bool overflow4;
        if (value7 & 0x8000) {
            a_hi4 = value7 >> 8;
            overflow4 = overflow3;
        } else {
            uint16_t value8 = RAM16(0x0008);
            RAM16_SET(0x0010 + y_ret, (uint16_t)((uint16_t)(value7 << 6) + value8));
            RAM16_SET(0x0014 + y_ret, (uint16_t)((uint16_t)((uint16_t)(value7 << 6) + value8) + 0x20));
            a_hi4 = (uint16_t)((uint16_t)((uint16_t)(value7 << 6) + value8) + 0x20) >> 8;
            overflow4 = (((uint16_t)((uint16_t)(value7 << 6) + value8) ^ (uint16_t)((uint16_t)((uint16_t)(value7 << 6) + value8) + 0x20)) & ((uint16_t)((uint16_t)((uint16_t)(value7 << 6) + value8) + 0x20) ^ 0x20) & 0x8000) != 0;
        }
        r->a = (a_hi4 << 8) | (uint8_t)a_all2;
        r->v = overflow4;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value9 = RAM16(0x0008);
    RAM16_SET(0x0008, (uint16_t)(value9 + 0x0500));
    uint16_t value10 = RAM16(0x0004);
    uint8_t a_hi5;
    bool overflow5;
    if (value10 & 0x8000) {
        a_hi5 = value10 >> 8;
        overflow5 = ((value9 ^ (uint16_t)(value9 + 0x0500)) & ((uint16_t)(value9 + 0x0500) ^ 0x0500) & 0x8000) != 0;
    } else {
        uint16_t value11 = RAM16(0x0008);
        RAM16_SET(0x0000 + y_ret, (uint16_t)((uint16_t)(value10 << 5) + value11));
        a_hi5 = (uint16_t)((uint16_t)(value10 << 5) + value11) >> 8;
        overflow5 = (((uint16_t)(value10 << 5) ^ (uint16_t)((uint16_t)(value10 << 5) + value11)) & (value11 ^ (uint16_t)((uint16_t)(value10 << 5) + value11)) & 0x8000) != 0;
    }
    uint16_t value12 = RAM16(0x0002);
    uint8_t a_hi6;
    bool overflow6;
    if (value12 & 0x8000) {
        a_hi6 = value12 >> 8;
        overflow6 = overflow5;
    } else {
        uint16_t value13 = RAM16(0x0008);
        RAM16_SET(0x0008 + y_ret, (uint16_t)((uint16_t)(value12 << 5) + value13));
        a_hi6 = (uint16_t)((uint16_t)(value12 << 5) + value13) >> 8;
        overflow6 = (((uint16_t)(value12 << 5) ^ (uint16_t)((uint16_t)(value12 << 5) + value13)) & (value13 ^ (uint16_t)((uint16_t)(value12 << 5) + value13)) & 0x8000) != 0;
    }
    uint16_t value14 = RAM16(0x0000);
    uint8_t a_hi7;
    bool overflow7;
    if (value14 & 0x8000) {
        a_hi7 = value14 >> 8;
        overflow7 = overflow6;
    } else {
        uint16_t value15 = RAM16(0x0008);
        RAM16_SET(0x0010 + y_ret, (uint16_t)((uint16_t)(value14 << 5) + value15));
        a_hi7 = (uint16_t)((uint16_t)(value14 << 5) + value15) >> 8;
        overflow7 = (((uint16_t)(value14 << 5) ^ (uint16_t)((uint16_t)(value14 << 5) + value15)) & (value15 ^ (uint16_t)((uint16_t)(value14 << 5) + value15)) & 0x8000) != 0;
    }
    r->a = (a_hi7 << 8) | (uint8_t)a_all2;
    r->v = overflow7;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC18425, SOM_RTS, "gen", build_floating_combat_number_tile_records, 0, L_B | L_X | L_Y | L_V, 1, 0, 0, 164, 98)
