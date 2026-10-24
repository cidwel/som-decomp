#include "som_c.h"

/* C1F413 upload_map_graphics_descriptor_list   [class D, 67 bytes, 33 instructions]
 * Source: src/rom/upload_map_graphics_descriptor_list.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void upload_map_graphics_descriptor_list(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    BUS8_SET(c, 0x002115, 0x80);
    RAM8(0x0012) = 0xCC;
    uint8_t value = RAM8(0x001C);
    uint16_t value2 = BUS16(c, 0xCCE27E + (uint8_t)((a >> 8 << 8) | ((value & 0x3F) << 1)));
    RAM16_SET(0x0010, value2);
    uint16_t value3 = BUS16(c, 0xCCE280 + (uint8_t)((a >> 8 << 8) | ((value & 0x3F) << 1)));
    uint16_t value4 = RAM16(0x0010);
    RAM16_SET(0x0014, (uint16_t)(value3 - value4));
    BUS16_SET(c, 0x002116, 0);
    BUS16_SET(c, 0x004370, 0x1801);
    uint8_t a1 = 1;
    uint8_t a_hi1 = 0x18;
    uint16_t x1 = (uint8_t)((a >> 8 << 8) | ((value & 0x3F) << 1));
    uint16_t y1 = 0;
    bool carry1 = value3 >= value4;
    bool overflow1 = ((value3 ^ value4) & (value3 ^ (uint16_t)(value3 - value4)) & 0x8000) != 0;
    bool first_pass = true;
    for (;;) {
        if (first_pass) {
            uint16_t value5 = BUS16(c, (RAM8(0x0012) << 0x10) + RAM16(0x0010) + (uint8_t)y1);
            r->a = value5;
            r->y = (uint8_t)y1 + 2;
            r->v = overflow1;
            r->mf = 0;
            r->xf = 0;
            r->db = 0;
            r->dp = 0;
            r->sp -= 2;
            JSR(c, 0xF44C, 0xC1F456); /* upload_map_graphics_descriptor */
            r->sp += 2;
            uint16_t a_all = r->a;
            uint16_t x_ret = r->x;
            bool overflow_ret = r->v;
            uint16_t value6 = RAM16(0x0014);
            if ((uint8_t)y1 + 3 < value6) {
                uint8_t a1_next = (uint8_t)a_all;
                uint8_t a_hi1_next = a_all >> 8;
                uint16_t x1_next = x_ret;
                uint16_t y1_next = (uint8_t)y1 + 3;
                bool carry1_next = (uint8_t)y1 + 3 >= value6;
                bool overflow1_next = overflow_ret;
                a1 = a1_next;
                a_hi1 = a_hi1_next;
                x1 = x1_next;
                y1 = y1_next;
                carry1 = carry1_next;
                overflow1 = overflow1_next;
                first_pass = false;
                continue;
            }
            uint8_t a1_next2 = (uint8_t)a_all;
            uint8_t a_hi1_next2 = a_all >> 8;
            uint16_t x1_next2 = x_ret;
            uint16_t y1_next2 = (uint8_t)y1 + 3;
            bool carry1_next2 = (uint8_t)y1 + 3 >= value6;
            bool overflow1_next2 = overflow_ret;
            a1 = a1_next2;
            a_hi1 = a_hi1_next2;
            x1 = x1_next2;
            y1 = y1_next2;
            carry1 = carry1_next2;
            overflow1 = overflow1_next2;
            break;
        } else {
            uint16_t value7 = BUS16(c, (RAM8(0x0012) << 0x10) + RAM16(0x0010) + (uint8_t)y1);
            r->a = value7;
            r->y = (uint8_t)y1 + 2;
            r->v = overflow1;
            r->mf = 0;
            r->xf = 0;
            r->db = 0;
            r->dp = 0;
            r->sp -= 2;
            JSR(c, 0xF44C, 0xC1F456); /* upload_map_graphics_descriptor */
            r->sp += 2;
            uint16_t a_all2 = r->a;
            uint16_t x_ret2 = r->x;
            bool overflow_ret2 = r->v;
            uint16_t value8 = RAM16(0x0014);
            if ((uint8_t)y1 + 3 < value8) {
                uint8_t a1_next3 = (uint8_t)a_all2;
                uint8_t a_hi1_next3 = a_all2 >> 8;
                uint16_t x1_next3 = x_ret2;
                uint16_t y1_next3 = (uint8_t)y1 + 3;
                bool carry1_next3 = (uint8_t)y1 + 3 >= value8;
                bool overflow1_next3 = overflow_ret2;
                a1 = a1_next3;
                a_hi1 = a_hi1_next3;
                x1 = x1_next3;
                y1 = y1_next3;
                carry1 = carry1_next3;
                overflow1 = overflow1_next3;
                continue;
            }
            uint8_t a1_next4 = (uint8_t)a_all2;
            uint8_t a_hi1_next4 = a_all2 >> 8;
            uint16_t x1_next4 = x_ret2;
            uint16_t y1_next4 = (uint8_t)y1 + 3;
            bool carry1_next4 = (uint8_t)y1 + 3 >= value8;
            bool overflow1_next4 = overflow_ret2;
            a1 = a1_next4;
            a_hi1 = a_hi1_next4;
            x1 = x1_next4;
            y1 = y1_next4;
            carry1 = carry1_next4;
            overflow1 = overflow1_next4;
            break;
        }
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = (uint8_t)x1;
    r->y = (uint8_t)y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    r->db = 0;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1F413, SOM_RTS, "gen", upload_map_graphics_descriptor_list, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 2, 0, 1, 67, 33)
