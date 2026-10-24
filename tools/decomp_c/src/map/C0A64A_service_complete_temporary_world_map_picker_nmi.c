#include "som_c.h"

/* C0A64A service_complete_temporary_world_map_picker_nmi   [class D, 71 bytes, 40 instructions]
 * Source: src/rom/service_complete_temporary_world_map_picker_nmi.s
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void service_complete_temporary_world_map_picker_nmi(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint8_t x = r->x;
    const uint8_t y = r->y;
    const bool carry = r->c;
    RAM8(0x0000 + sp0) = a_hi;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)((a_hi << 8) | a);
    RAM8(0x0000 + sp0 - 2) = 0;
    RAM8(0x0000 + sp0 - 3) = x;
    RAM8(0x0000 + sp0 - 4) = 0;
    RAM8(0x0000 + sp0 - 5) = y;
    RAM8(0x0000 + sp0 - 6) = 0;
    RAM8(0x0000 + sp0 - 7) = 0;
    RAM8(0x0000 + sp0 - 8) = 0;
    uint8_t value = BUS8(c, 0x004210);
    RAM8(0x0000 + sp0 - 9) = 0;
    uint16_t value2 = RAM16(0x00F4);
    RAM16_SET(0x00F4, (uint16_t)(value2 + 1));
    r->a = (uint16_t)(value2 + 1);
    r->z = (uint16_t)(value2 + 1) == 0;
    r->n = (uint16_t)(value2 + 1) & 0x8000;
    r->mf = 0;
    r->sp -= 9;
    { const uint16_t sp_call = r->sp; JSL(c, 0xA669, 0x02A801); GUARD_JSL(c, sp_call, 0xA669); } /* blink_and_upload_four_world_map_picker_cursor_objects */
    r->sp += 9;
    uint16_t a_all = r->a;
    uint8_t value3 = RAM8(0x000D);
    bool m_flag4;
    bool carry2;
    if (value3 == 0) {
        uint8_t value4 = RAM8(0x000E);
        bool m_flag;
        if (value4 == 0) {
            m_flag = 1;
        } else {
            RAM8(0x000E) = (uint8_t)(value4 + 1) & 3;
            r->a = a_all >> 8 << 8 | ((uint8_t)(value4 + 1) & 3);
            r->y = (uint8_t)((a_all >> 8 << 8) | value4);
            r->z = ((uint8_t)(value4 + 1) & 3) == 0;
            r->n = (uint8_t)(value4 + 1) & 3 & 0x80;
            r->mf = 1;
            r->xf = 1;
            r->sp -= 9;
            { const uint16_t sp_call = r->sp; JSR(c, 0xA685, 0xC0A6F5); GUARD_JSR(c, sp_call, 0xA685); } /* upload_next_world_map_picker_tile_third */
            r->sp += 9;
            m_flag = 0;
        }
        m_flag4 = m_flag;
        carry2 = carry;
    } else {
        uint8_t value5 = RAM8(0x000C);
        bool m_flag3;
        bool carry1;
        if (value5 == 0) {
            uint8_t value6 = RAM8(0x000E);
            bool m_flag2;
            if (value6 == 0) {
                m_flag2 = 1;
            } else {
                RAM8(0x000E) = (uint8_t)(value6 + 1) & 3;
                r->a = a_all >> 8 << 8 | ((uint8_t)(value6 + 1) & 3);
                r->y = (uint8_t)((a_all >> 8 << 8) | value6);
                r->z = ((uint8_t)(value6 + 1) & 3) == 0;
                r->n = (uint8_t)(value6 + 1) & 3 & 0x80;
                r->mf = 1;
                r->xf = 1;
                r->sp -= 9;
                { const uint16_t sp_call = r->sp; JSR(c, 0xA685, 0xC0A6F5); GUARD_JSR(c, sp_call, 0xA685); } /* upload_next_world_map_picker_tile_third */
                r->sp += 9;
                m_flag2 = 0;
            }
            m_flag3 = m_flag2;
            carry1 = carry;
        } else {
            r->a = (a_all >> 8 << 8) | value5;
            r->z = value5 == 0;
            r->n = value5 & 0x80;
            r->mf = 1;
            r->xf = 1;
            r->sp -= 9;
            { const uint16_t sp_call = r->sp; JSR(c, 0xA676, 0xC0A6D4); GUARD_JSR(c, sp_call, 0xA676); } /* advance_world_map_picker_brightness_counter */
            r->sp += 9;
            bool carry_ret = r->c;
            m_flag3 = 1;
            carry1 = carry_ret;
        }
        m_flag4 = m_flag3;
        carry2 = carry1;
    }
    r->c = carry2;
    r->mf = m_flag4;
    r->xf = 1;
    r->sp -= 9;
    { const uint16_t sp_call = r->sp; JSR(c, 0xA688, 0xC0A691); GUARD_JSR(c, sp_call, 0xA688); } /* publish_world_map_picker_matrix_when_rows_are_complete */
    r->sp += 9;
    uint8_t value7 = RAM8(0x0000 + sp0 - 8);
    uint8_t value8 = RAM8(0x0000 + sp0 - 7);
    uint8_t value9 = RAM8(0x0000 + sp0 - 6);
    uint8_t value10 = RAM8(0x0000 + sp0 - 5);
    uint8_t value11 = RAM8(0x0000 + sp0 - 4);
    uint8_t value12 = RAM8(0x0000 + sp0 - 3);
    uint8_t value13 = RAM8(0x0000 + sp0 - 2);
    r->a = (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1);
    r->x = (value13 << 8) | value12;
    r->y = (value11 << 8) | value10;
    r->db = value7;
    r->dp = (value9 << 8) | value8;
    RETURN_RTI(c);
}
SOM_REGISTER(0xC0A64A, SOM_RTI, "gen", service_complete_temporary_world_map_picker_nmi, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 10, 1, 1, 71, 40)
