#include "som_c.h"

/* C077E7 publish_native_inventory_owner_bits_after_equipment_exchange   [class B, 55 bytes, 30 instructions]
 * Source: src/rom/publish_native_inventory_owner_bits_after_equipment_exchange.s
 * Entry: M=any X=16 bit DB=any D=any.  Callers read: BXYCV.
 */
static void publish_native_inventory_owner_bits_after_equipment_exchange(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    const uint8_t db = r->db;
    RAM8(0x0000 + sp0) = a >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)a;
    uint16_t value = BUS16_RDP(c, (db << 0x10) + 0x1853);
    r->a = (uint16_t)(a + value);
    r->x = (uint16_t)(a + value);
    r->c = a + value > 0xFFFF;
    r->z = (uint16_t)(a + value) == 0;
    r->n = (uint16_t)(a + value) & 0x8000;
    r->v = ((a ^ (uint16_t)(a + value)) & (value ^ (uint16_t)(a + value)) & 0x8000) != 0;
    r->mf = 1;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x77F3, 0xC07A54); GUARD_JSR(c, sp_call, 0x77F3); } /* read_native_actor_equipment_field_and_restore_index_status */
    r->sp += 2;
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    bool overflow_ret = r->v;
    if (x_ret) {
        c->fail = 3;
        return;
    } else {
        uint8_t value10 = RAM8(0x0000 + sp0 - 1);
        uint8_t value11 = RAM8(0x0000 + sp0);
        uint8_t a_hi4;
        bool carry4;
        bool overflow4;
        if ((uint8_t)a_all != 0x15) {
            RAM8(0x0000 + sp0) = RAM8(0xCC00 + y);
            RAM8(0x0000 + sp0) = (uint8_t)((((value11 << 8) | value10) >> 1) + 0x0100 >> 2) | RAM8(0x0000 + sp0);
            RAM8(0xCC00 + y) = RAM8(0x0000 + sp0);
            a_hi4 = (((value11 << 8) | value10) >> 1) + 0x0100 >> 2 >> 8;
            carry4 = (((value11 << 8) | value10) >> 1) + 0x0100 >> 1 & 0x01;
            overflow4 = (((((value11 << 8) | value10) >> 1) ^ (((value11 << 8) | value10) >> 1) + 0x0100) & ((((value11 << 8) | value10) >> 1) + 0x0100 ^ 0x0100) & 0x8000) != 0;
        } else {
            uint8_t value15 = BUS8_RDP(c, (db << 0x10) + 0x1809);
            uint8_t a_hi3;
            bool carry3;
            bool overflow3;
            if (value15 != 3) {
                a_hi3 = a_all >> 8;
                carry3 = value15 >= 3;
                overflow3 = overflow_ret;
            } else {
                RAM8(0x0000 + sp0) = RAM8(0xCC00 + y);
                RAM8(0x0000 + sp0) = (uint8_t)((((value11 << 8) | value10) >> 1) + 0x0100 >> 2) | RAM8(0x0000 + sp0);
                RAM8(0xCC00 + y) = RAM8(0x0000 + sp0);
                a_hi3 = (((value11 << 8) | value10) >> 1) + 0x0100 >> 2 >> 8;
                carry3 = (((value11 << 8) | value10) >> 1) + 0x0100 >> 1 & 0x01;
                overflow3 = (((((value11 << 8) | value10) >> 1) ^ (((value11 << 8) | value10) >> 1) + 0x0100) & ((((value11 << 8) | value10) >> 1) + 0x0100 ^ 0x0100) & 0x8000) != 0;
            }
            a_hi4 = a_hi3;
            carry4 = carry3;
            overflow4 = overflow3;
        }
        r->a = (a_hi4 << 8) | (uint8_t)a_all;
        r->x = y;
        r->y = (value11 << 8) | value10;
        r->c = carry4;
        r->v = overflow4;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC077E7, SOM_RTS, "gen", publish_native_inventory_owner_bits_after_equipment_exchange, 0, L_B | L_X | L_Y | L_C | L_V, 2, -1, 0, 55, 30)
