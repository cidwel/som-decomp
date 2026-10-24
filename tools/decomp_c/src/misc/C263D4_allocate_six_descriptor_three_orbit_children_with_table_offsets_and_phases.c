#include "som_c.h"

/* C263D4 allocate_six_descriptor_three_orbit_children_with_table_offsets_and_phases   [class B, 73 bytes, 31 instructions]
 * Source: src/rom/allocate_six_descriptor_three_orbit_children_with_table_offsets_and_phases.s
 * Documented in docs/boss-descriptor-three-orbit.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void allocate_six_descriptor_three_orbit_children_with_table_offsets_and_phases(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM16_SET(0x0295, RAM16(0x0287));
    RAM16_SET(0x021A, 0);
    uint8_t a1 = 0;
    uint8_t a_hi1 = 0;
    uint16_t x1 = x;
    uint16_t y1 = y;
    bool carry1 = carry;
    bool zero1 = 1;
    bool negative1 = 0;
    bool overflow1 = overflow;
    for (;;) {
        r->a = (a_hi1 << 8) | a1;
        r->x = 0x641D;
        r->y = 0xA901;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0x0200;
        JSR(c, 0x63E5, 0xC20D53); /* allocate_boss_object_pool_slot */
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        bool carry_ret = r->c;
        bool zero_ret = r->z;
        bool negative_ret = r->n;
        bool overflow_ret = r->v;
        uint8_t a2;
        uint8_t a_hi2;
        uint16_t x2;
        uint16_t y2;
        bool carry2;
        bool zero2;
        bool negative2;
        if (carry_ret) {
            a2 = (uint8_t)a_all;
            a_hi2 = a_all >> 8;
            x2 = x_ret;
            y2 = 0xA901;
            carry2 = carry_ret;
            zero2 = zero_ret;
            negative2 = negative_ret;
        } else {
            uint16_t value2 = RAM16(0x021A);
            uint16_t value3 = BUS16(c, 0xDCE2C3 + (uint16_t)(value2 << 2));
            RAM16_SET(0x00B6 + x_ret, value3);
            uint16_t value4 = BUS16(c, 0xDCE2C5 + (uint16_t)(value2 << 2));
            RAM16_SET(0x00B8 + x_ret, value4);
            uint16_t value5 = RAM16(0x021A);
            uint16_t value6 = BUS16(c, 0xDCE2DB + (uint16_t)(value5 << 1));
            RAM16_SET(0x00B0 + x_ret, value6);
            uint16_t value7 = BUS16(c, 0xDCE2E7 + (uint16_t)(value5 << 1));
            RAM16_SET(0x00B2 + x_ret, value7);
            RAM16_SET(0x00BA + x_ret, RAM16(0x0295));
            RAM16_SET(0x021A, (uint16_t)(RAM16(0x021A) + 1));
            uint16_t value9 = RAM16(0x021A);
            if (value9 != 6) {
                a1 = (uint8_t)value9;
                a_hi1 = value9 >> 8;
                x1 = (uint16_t)(value5 << 1);
                y1 = x_ret;
                carry1 = value9 >= 6;
                zero1 = value9 == 6;
                negative1 = (uint16_t)(value9 - 6) & 0x8000;
                overflow1 = overflow_ret;
                continue;
            }
            a2 = (uint8_t)value9;
            a_hi2 = value9 >> 8;
            x2 = (uint16_t)(value5 << 1);
            y2 = x_ret;
            carry2 = value9 >= 6;
            zero2 = value9 == 6;
            negative2 = (uint16_t)(value9 - 6) & 0x8000;
        }
        a1 = a2;
        a_hi1 = a_hi2;
        x1 = x2;
        y1 = y2;
        carry1 = carry2;
        zero1 = zero2;
        negative1 = negative2;
        overflow1 = overflow_ret;
        break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0x0200;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC263D4, SOM_RTS, "gen", allocate_six_descriptor_three_orbit_children_with_table_offsets_and_phases, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 73, 31)
