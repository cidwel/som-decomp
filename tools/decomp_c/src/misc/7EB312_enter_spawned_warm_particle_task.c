#include "som_c.h"

/* 7EB312 enter_spawned_warm_particle_task   [class C, 33 bytes, 22 instructions]
 * Source: src/boot/enter_spawned_warm_particle_task.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void enter_spawned_warm_particle_task(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 5) + 0x2 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 5) = 0x7E;
    RAM8(0x0000 + sp0 - 6) = 0x7F;
    r->a = ((uint16_t)(sp0 - 5) >> 8 << 8) | 0x7F;
    r->z = 0;
    r->n = 0;
    r->db = 0x7F;
    r->dp = (uint16_t)(sp0 - 5);
    r->sp -= 6;
    { const uint16_t sp_call = r->sp; JSR(c, 0xB322, 0x7EB342); GUARD_JSR(c, sp_call, 0xB322); } /* construct_warm_particle_sprite_and_six_byte_workspace */
    r->sp += 6;
    bool x_ret = r->xf;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret = r->y;
    if (x_ret) {
        RAM8(0x0001 + (uint16_t)(sp0 - 5)) = (uint8_t)x_ret2;
        r->x = (uint8_t)x_ret2;
        r->y = (uint8_t)y_ret;
        r->xf = 1;
        r->sp -= 6;
        { const uint16_t sp_call = r->sp; JSR(c, 0xB327, 0x7EB3A8); GUARD_JSR(c, sp_call, 0xB327); } /* publish_warm_particle_each_tick_until_animation_finishes */
        r->sp += 6;
        uint16_t dp_ret = r->dp;
        bool x_ret3 = r->xf;
        uint16_t y_ret2 = r->y;
        if (x_ret3) {
            uint8_t value = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
            r->x = value;
            r->y = (uint8_t)y_ret2;
            r->z = value == 0;
            r->n = value & 0x80;
            r->xf = 1;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSR(c, 0xB32C, 0x7EB416); GUARD_JSR(c, sp_call, 0xB32C); } /* release_warm_particle_sprite_and_heap_workspace */
            r->sp += 6;
            bool m_ret3 = r->mf;
            uint16_t a_all3 = r->a;
            uint8_t value2 = RAM8(0x0000 + sp0 - 5);
            if (m_ret3) {
                uint8_t value4 = RAM8(0x0000 + sp0 - 3);
                uint8_t value5 = RAM8(0x0000 + sp0 - 2);
                uint8_t value6 = RAM8(0x0000 + sp0 - 1);
                uint8_t value7 = RAM8(0x0000 + sp0);
                r->a = (a_all3 >> 8 << 8) | value4;
                r->c = value5 & 0x01;
                r->z = ((value7 << 8) | value6) == 0;
                r->n = ((value7 << 8) | value6) & 0x8000;
                r->v = value5 & 0x40;
                r->mf = value5 & 0x20;
                r->xf = value5 & 0x10;
                r->db = value2;
                r->dp = (value7 << 8) | value6;
                r->i = value5 & 0x04;
                r->d = value5 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTL(c);
            } else {
                c->fail = 3;
                return;
            }
        } else {
            uint16_t value13 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
            r->x = value13;
            r->z = value13 == 0;
            r->n = value13 & 0x8000;
            r->xf = 0;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSR(c, 0xB32C, 0x7EB416); GUARD_JSR(c, sp_call, 0xB32C); } /* release_warm_particle_sprite_and_heap_workspace */
            r->sp += 6;
            bool m_ret4 = r->mf;
            uint16_t a_all4 = r->a;
            uint8_t value14 = RAM8(0x0000 + sp0 - 5);
            if (m_ret4) {
                uint8_t value16 = RAM8(0x0000 + sp0 - 3);
                uint8_t value17 = RAM8(0x0000 + sp0 - 2);
                uint8_t value18 = RAM8(0x0000 + sp0 - 1);
                uint8_t value19 = RAM8(0x0000 + sp0);
                r->a = (a_all4 >> 8 << 8) | value16;
                r->c = value17 & 0x01;
                r->z = ((value19 << 8) | value18) == 0;
                r->n = ((value19 << 8) | value18) & 0x8000;
                r->v = value17 & 0x40;
                r->mf = value17 & 0x20;
                r->xf = value17 & 0x10;
                r->db = value14;
                r->dp = (value19 << 8) | value18;
                r->i = value17 & 0x04;
                r->d = value17 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTL(c);
            } else {
                c->fail = 3;
                return;
            }
        }
    } else {
        RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), x_ret2);
        r->xf = 0;
        r->sp -= 6;
        { const uint16_t sp_call = r->sp; JSR(c, 0xB327, 0x7EB3A8); GUARD_JSR(c, sp_call, 0xB327); } /* publish_warm_particle_each_tick_until_animation_finishes */
        r->sp += 6;
        uint16_t dp_ret4 = r->dp;
        bool x_ret9 = r->xf;
        uint16_t y_ret5 = r->y;
        if (x_ret9) {
            uint8_t value25 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 1));
            r->x = value25;
            r->y = (uint8_t)y_ret5;
            r->z = value25 == 0;
            r->n = value25 & 0x80;
            r->xf = 1;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSR(c, 0xB32C, 0x7EB416); GUARD_JSR(c, sp_call, 0xB32C); } /* release_warm_particle_sprite_and_heap_workspace */
            r->sp += 6;
            bool m_ret6 = r->mf;
            uint16_t a_all6 = r->a;
            uint8_t value26 = RAM8(0x0000 + sp0 - 5);
            if (m_ret6) {
                uint8_t value28 = RAM8(0x0000 + sp0 - 3);
                uint8_t value29 = RAM8(0x0000 + sp0 - 2);
                uint8_t value30 = RAM8(0x0000 + sp0 - 1);
                uint8_t value31 = RAM8(0x0000 + sp0);
                r->a = (a_all6 >> 8 << 8) | value28;
                r->c = value29 & 0x01;
                r->z = ((value31 << 8) | value30) == 0;
                r->n = ((value31 << 8) | value30) & 0x8000;
                r->v = value29 & 0x40;
                r->mf = value29 & 0x20;
                r->xf = value29 & 0x10;
                r->db = value26;
                r->dp = (value31 << 8) | value30;
                r->i = value29 & 0x04;
                r->d = value29 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTL(c);
            } else {
                c->fail = 3;
                return;
            }
        } else {
            uint16_t value37 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 1));
            r->x = value37;
            r->z = value37 == 0;
            r->n = value37 & 0x8000;
            r->xf = 0;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSR(c, 0xB32C, 0x7EB416); GUARD_JSR(c, sp_call, 0xB32C); } /* release_warm_particle_sprite_and_heap_workspace */
            r->sp += 6;
            bool m_ret7 = r->mf;
            uint16_t a_all7 = r->a;
            uint8_t value38 = RAM8(0x0000 + sp0 - 5);
            if (m_ret7) {
                uint8_t value40 = RAM8(0x0000 + sp0 - 3);
                uint8_t value41 = RAM8(0x0000 + sp0 - 2);
                uint8_t value42 = RAM8(0x0000 + sp0 - 1);
                uint8_t value43 = RAM8(0x0000 + sp0);
                r->a = (a_all7 >> 8 << 8) | value40;
                r->c = value41 & 0x01;
                r->z = ((value43 << 8) | value42) == 0;
                r->n = ((value43 << 8) | value42) & 0x8000;
                r->v = value41 & 0x40;
                r->mf = value41 & 0x20;
                r->xf = value41 & 0x10;
                r->db = value38;
                r->dp = (value43 << 8) | value42;
                r->i = value41 & 0x04;
                r->d = value41 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTL(c);
            } else {
                c->fail = 3;
                return;
            }
        }
    }
}
SOM_REGISTER(0x7EB312, SOM_RTL, "gen", enter_spawned_warm_particle_task, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 7, 1, 0, 33, 22)
