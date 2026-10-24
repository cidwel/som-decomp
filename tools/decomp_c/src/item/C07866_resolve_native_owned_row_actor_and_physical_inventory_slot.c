#include "som_c.h"

/* C07866 resolve_native_owned_row_actor_and_physical_inventory_slot   [class A, 24 bytes, 15 instructions]
 * Source: src/rom/resolve_native_owned_row_actor_and_physical_inventory_slot.s
 * Documented in docs/event-menu-equipment-swap.md
 * Entry: M=any X=16 bit DB=any D=any.  Callers read: BXYV.
 */
static void resolve_native_owned_row_actor_and_physical_inventory_slot(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t a = r->a;
    const uint8_t db = r->db;
    uint16_t value = BUS16_RDP(c, (db << 0x10) + 0x18A0 + ((a & 0xFF) << 1));
    RAM8(0x0000 + sp0) = (uint16_t)((value & 0x0F) - 1) >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)((value & 0x0F) - 1);
    r->a = (uint16_t)((value & 0x0F) - 1);
    r->c = a & 0xFF & 0x8000;
    r->z = (uint16_t)((value & 0x0F) - 1) == 0;
    r->n = (uint16_t)((value & 0x0F) - 1) & 0x8000;
    r->mf = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7877, 0xC076C7); GUARD_JSR(c, sp_call, 0x7877); } /* find_native_inventory_owner_wrapper */
    r->sp += 2;
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t x_ret2 = r->x;
    if (x_ret) {
        if (m_ret) {
            c->fail = 3;
            return;
        } else {
            uint8_t value3 = RAM8(0x0000 + sp0 - 1);
            uint8_t value4 = RAM8(0x0000 + sp0);
            r->a = (uint16_t)((((uint8_t)((value4 << 8) | value3) << 8) | value4) << 1);
            r->x = (uint8_t)((((uint8_t)((value4 << 8) | value3) << 8) | value4) << 1);
            r->y = (uint8_t)x_ret2;
            r->mf = 0;
            r->xf = 1;
            RETURN_RTS(c);
        }
    } else {
        if (m_ret) {
            c->fail = 3;
            return;
        } else {
            uint8_t value6 = RAM8(0x0000 + sp0 - 1);
            uint8_t value7 = RAM8(0x0000 + sp0);
            r->a = (uint16_t)((((uint8_t)((value7 << 8) | value6) << 8) | value7) << 1);
            r->x = (uint16_t)((((uint8_t)((value7 << 8) | value6) << 8) | value7) << 1);
            r->y = x_ret2;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
    }
}
SOM_REGISTER(0xC07866, SOM_RTS, "gen", resolve_native_owned_row_actor_and_physical_inventory_slot, 0, L_B | L_X | L_Y | L_V, 2, -1, 0, 24, 15)
