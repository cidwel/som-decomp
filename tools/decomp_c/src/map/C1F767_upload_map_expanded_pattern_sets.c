#include "som_c.h"

/* C1F767 upload_map_expanded_pattern_sets   [class D, 104 bytes, 47 instructions]
 * Source: src/rom/upload_map_expanded_pattern_sets.s
 * Entry: M=16 bit X=8 bit DB=$00 D=$0000.  Callers read: BXYV.
 */
static void upload_map_expanded_pattern_sets(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t a = r->a;
    const bool overflow = r->v;
    BUS16_SET(c, 0x004375, 0x80);
    BUS16_SET(c, 0x002116, 0x4000);
    BUS8_SET(c, 0x00420B, 0x80);
    BUS16_SET(c, 0x004372, 0x7F00);
    BUS16_SET(c, 0x004370, 0x1801);
    BUS8_SET(c, 0x004374, 0xD2);
    BUS8_SET(c, 0x002115, 0x80);
    BUS16_SET(c, 0x004375, 0x0300);
    BUS8_SET(c, 0x00420B, 0x80);
    BUS16_SET(c, 0x004372, 0xFF00);
    BUS8_SET(c, 0x004374, 0x7F);
    RAM8(0x0000 + sp0) = 0;
    RAM8(0x0000 + sp0 - 1) = 0x7F;
    RAM8(0x0002) = 8;
    uint8_t a_hi1 = 0xFF;
    uint8_t x1 = 0;
    uint8_t y1 = 8;
    bool overflow1 = overflow;
    bool first_pass = true;
    for (;;) {
        if (first_pass) {
            uint8_t a_hi2 = a_hi1;
            uint8_t x2 = x1;
            uint8_t y2 = 0;
            for (;;) {
                uint16_t value = BUS16(c, 0xD27E70 + x2);
                BUS16_SET(c, 0x7FFF10 + y2, value);
                a_hi2 = value >> 8;
                x2 = (uint8_t)(x2 + 2);
                y2 = (uint8_t)(y2 + 2);
                if (!(y2 < 0x10)) break;
            }
            RAM8(0x0000 + sp0 - 1) = x2;
            r->a = (a_hi2 << 8) | (uint8_t)a;
            r->x = x2;
            r->y = y2;
            r->v = overflow1;
            r->mf = 0;
            r->xf = 1;
            r->db = 0x7F;
            r->dp = 0;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSR(c, 0xF7C7, 0xC1F7CF); GUARD_JSR(c, sp_call, 0xF7C7); } /* expand_and_upload_map_pattern_record */
            r->sp += 2;
            uint16_t a_all = r->a;
            uint8_t y_ret = r->y;
            uint8_t value2 = RAM8(0x0000 + sp0 - 1);
            RAM8(0x0002)--;
            if (RAM8(0x0002) != 0) {
                a_hi1 = a_all >> 8;
                x1 = value2;
                y1 = y_ret;
                first_pass = false;
                continue;
            }
            a_hi1 = a_all >> 8;
            x1 = value2;
            y1 = y_ret;
            break;
        } else {
            uint8_t a_hi3 = a_hi1;
            uint8_t x3 = x1;
            uint8_t y3 = 0;
            for (;;) {
                uint16_t value3 = BUS16(c, 0xD27E70 + x3);
                BUS16_SET(c, 0x7FFF10 + y3, value3);
                a_hi3 = value3 >> 8;
                x3 = (uint8_t)(x3 + 2);
                y3 = (uint8_t)(y3 + 2);
                if (!(y3 < 0x10)) break;
            }
            RAM8(0x0000 + sp0 - 1) = x3;
            r->a = (a_hi3 << 8) | (uint8_t)a;
            r->x = x3;
            r->y = y3;
            r->v = overflow1;
            r->mf = 0;
            r->xf = 1;
            r->db = 0x7F;
            r->dp = 0;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSR(c, 0xF7C7, 0xC1F7CF); GUARD_JSR(c, sp_call, 0xF7C7); } /* expand_and_upload_map_pattern_record */
            r->sp += 2;
            uint16_t a_all2 = r->a;
            uint8_t y_ret2 = r->y;
            uint8_t value4 = RAM8(0x0000 + sp0 - 1);
            RAM8(0x0002)--;
            if (RAM8(0x0002) != 0) {
                a_hi1 = a_all2 >> 8;
                x1 = value4;
                y1 = y_ret2;
                continue;
            }
            a_hi1 = a_all2 >> 8;
            x1 = value4;
            y1 = y_ret2;
            break;
        }
    }
    uint8_t value5 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | (uint8_t)a;
    r->x = x1;
    r->y = y1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 1;
    r->db = value5;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1F767, SOM_RTS, "gen", upload_map_expanded_pattern_sets, 0, L_B | L_X | L_Y | L_V, 2, 0, 1, 104, 47)
