#include "som_c.h"

/* C0CB90 load_map_piece_list   [class B, 50 bytes, 26 instructions]
 * Source: src/rom/load_map_piece_list.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: CV.
 */
static void load_map_piece_list(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x00DC);
    uint16_t value2 = BUS16(c, 0xC85000 + (uint16_t)(value << 1));
    RAM16_SET(0x0020, value2);
    uint16_t value3 = BUS16(c, 0xC85002 + (uint16_t)(value << 1));
    RAM16_SET(0x0024, value3);
    RAM8(0x0022) = 0xC8;
    uint8_t a_hi1 = value3 >> 8;
    bool carry1 = value & 0x8000;
    bool overflow1 = overflow;
    bool first_pass = true;
    for (;;) {
        if (first_pass) {
            r->a = (a_hi1 << 8) | a;
            r->c = carry1;
            r->v = overflow1;
            r->mf = 1;
            r->xf = 1;
            r->db = 0x7F;
            r->dp = 0;
            r->sp -= 1;
            JSR(c, 0xCBAF, 0xC0CBD1); /* load_conditional_map_piece */
            r->sp += 1;
            uint16_t value4 = RAM16(0x0020);
            RAM16_SET(0x0020, (uint16_t)(value4 + 5));
            uint16_t value5 = RAM16(0x0024);
            if ((uint16_t)(value4 + 5) < value5) {
                a_hi1 = (uint16_t)(value4 + 5) >> 8;
                carry1 = (uint16_t)(value4 + 5) >= value5;
                overflow1 = ((value4 ^ (uint16_t)(value4 + 5)) & ((uint16_t)(value4 + 5) ^ 5) & 0x8000) != 0;
                first_pass = false;
                continue;
            }
            a_hi1 = (uint16_t)(value4 + 5) >> 8;
            carry1 = (uint16_t)(value4 + 5) >= value5;
            overflow1 = ((value4 ^ (uint16_t)(value4 + 5)) & ((uint16_t)(value4 + 5) ^ 5) & 0x8000) != 0;
            break;
        } else {
            r->a = (a_hi1 << 8) | a;
            r->c = carry1;
            r->v = overflow1;
            r->mf = 0;
            r->xf = 0;
            r->db = 0x7F;
            r->dp = 0;
            r->sp -= 1;
            JSR(c, 0xCBAF, 0xC0CBD1); /* load_conditional_map_piece */
            r->sp += 1;
            uint16_t value6 = RAM16(0x0020);
            RAM16_SET(0x0020, (uint16_t)(value6 + 5));
            uint16_t value7 = RAM16(0x0024);
            if ((uint16_t)(value6 + 5) < value7) {
                a_hi1 = (uint16_t)(value6 + 5) >> 8;
                carry1 = (uint16_t)(value6 + 5) >= value7;
                overflow1 = ((value6 ^ (uint16_t)(value6 + 5)) & ((uint16_t)(value6 + 5) ^ 5) & 0x8000) != 0;
                continue;
            }
            a_hi1 = (uint16_t)(value6 + 5) >> 8;
            carry1 = (uint16_t)(value6 + 5) >= value7;
            overflow1 = ((value6 ^ (uint16_t)(value6 + 5)) & ((uint16_t)(value6 + 5) ^ 5) & 0x8000) != 0;
            break;
        }
    }
    r->c = carry1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 1;
    r->db = 0;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0CB90, SOM_RTS, "gen", load_map_piece_list, 0, L_C | L_V, 2, 1, 0, 50, 26)
