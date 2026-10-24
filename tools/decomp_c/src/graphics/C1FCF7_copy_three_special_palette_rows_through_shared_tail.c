#include "som_c.h"

static void copy_fifteen_colors_from_hardware_multiplied_palette_index(SomCtx *c);
static void copy_fifteen_colors_from_hardware_multiplied_palette_index_v2(SomCtx *c);

/* C1FCF7 copy_three_special_palette_rows_through_shared_tail   [class B, 64 bytes, 29 instructions]
 * Source: src/rom/copy_three_special_palette_rows_through_shared_tail.s
 * Documented in docs/ui-native-music-palette-transition.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void copy_three_special_palette_rows_through_shared_tail(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    const bool overflow = r->v;
    r->a = (a_hi << 8) | 0x80;
    r->y = 0xA2;
    { const uint16_t sp_call = r->sp; JSR_LOCAL(c, 0xFD02, copy_fifteen_colors_from_hardware_multiplied_palette_index); GUARD_JSR(c, sp_call, 0xFD02); }
    uint16_t a_all = r->a;
    r->a = (a_all >> 8 << 8) | 0x81;
    r->y = 0xC2;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR_LOCAL(c, 0xFD0A, copy_fifteen_colors_from_hardware_multiplied_palette_index_v2); GUARD_JSR(c, sp_call, 0xFD0A); }
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret2 = r->db;
    uint16_t a_all2 = r->a;
    BUS8_SET(c, (db_ret2 << 0x10) + 0x4202, 0x82);
    BUS8_SET(c, (db_ret2 << 0x10) + 0x4203, 0x1E);
    RAM8(0x0000 + dp_ret2) = 0x0F;
    RAM8(0x0001 + dp_ret2) = 0;
    uint16_t value = BUS16(c, (db_ret2 << 0x10) + 0x4216);
    uint8_t a1 = 0x0F;
    uint8_t a_hi1 = a_all2 >> 8;
    uint16_t x1 = value;
    uint16_t y1 = 0xE2;
    bool zero1 = value == 0;
    bool negative1 = value & 0x8000;
    do {
        uint16_t value2 = BUS16(c, 0xC81000 + x1);
        BUS16_SET(c, (db_ret2 << 0x10) + 0x0700 + y1, value2);
        RAM16_SET(0x0000 + dp_ret2, (uint16_t)(RAM16(0x0000 + dp_ret2) - 1));
        a1 = (uint8_t)value2;
        a_hi1 = value2 >> 8;
        x1 = (uint16_t)(x1 + 2);
        y1 = (uint16_t)(y1 + 2);
        zero1 = RAM16(0x0000 + dp_ret2) == 0;
        negative1 = RAM16(0x0000 + dp_ret2) & 0x8000;
    } while (RAM16(0x0000 + dp_ret2) != 0);
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1FCF7, SOM_RTS, "gen", copy_three_special_palette_rows_through_shared_tail, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 64, 29)

/* C1FD10 copy_fifteen_colors_from_hardware_multiplied_palette_index   [class A, 39 bytes, 19 instructions]
 * Source: src/rom/copy_three_special_palette_rows_through_shared_tail.s
 * Subroutine of copy_three_special_palette_rows_through_shared_tail, translated in place.
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void copy_fifteen_colors_from_hardware_multiplied_palette_index(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    BUS8_SET(c, 0x004202, a);
    BUS8_SET(c, 0x004203, 0x1E);
    RAM8(0x0000) = 0x0F;
    RAM8(0x0001) = 0;
    uint16_t value = BUS16(c, 0x004216);
    uint8_t a1 = 0x0F;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = value;
    uint16_t y1 = y;
    bool zero1 = value == 0;
    bool negative1 = value & 0x8000;
    do {
        uint16_t value2 = BUS16(c, 0xC81000 + x1);
        BUS16_SET(c, 0x000700 + y1, value2);
        RAM16_SET(0x0000, (uint16_t)(RAM16(0x0000) - 1));
        a1 = (uint8_t)value2;
        a_hi1 = value2 >> 8;
        x1 = (uint16_t)(x1 + 2);
        y1 = (uint16_t)(y1 + 2);
        zero1 = RAM16(0x0000) == 0;
        negative1 = RAM16(0x0000) & 0x8000;
    } while (RAM16(0x0000) != 0);
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow;
    RETURN_RTS(c);
}

/* C1FD10 copy_fifteen_colors_from_hardware_multiplied_palette_index_v2   [class A, 39 bytes, 19 instructions]
 * Source: src/rom/copy_three_special_palette_rows_through_shared_tail.s
 * Subroutine of copy_three_special_palette_rows_through_shared_tail, translated in place.
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void copy_fifteen_colors_from_hardware_multiplied_palette_index_v2(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    BUS8_SET(c, (db << 0x10) + 0x4202, a);
    BUS8_SET(c, (db << 0x10) + 0x4203, 0x1E);
    RAM8(0x0000 + dp) = 0x0F;
    RAM8(0x0001 + dp) = 0;
    uint16_t value = BUS16(c, (db << 0x10) + 0x4216);
    uint8_t a1 = 0x0F;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = value;
    uint16_t y1 = y;
    bool zero1 = value == 0;
    bool negative1 = value & 0x8000;
    do {
        uint16_t value2 = BUS16(c, 0xC81000 + x1);
        BUS16_SET(c, (db << 0x10) + 0x0700 + y1, value2);
        RAM16_SET(0x0000 + dp, (uint16_t)(RAM16(0x0000 + dp) - 1));
        a1 = (uint8_t)value2;
        a_hi1 = value2 >> 8;
        x1 = (uint16_t)(x1 + 2);
        y1 = (uint16_t)(y1 + 2);
        zero1 = RAM16(0x0000 + dp) == 0;
        negative1 = RAM16(0x0000 + dp) & 0x8000;
    } while (RAM16(0x0000 + dp) != 0);
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow;
    RETURN_RTS(c);
}
