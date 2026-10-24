#include "som_c.h"

/* C286E4 prepare_native59_attack_and_allocate_target_linked_projectile   [class B, 98 bytes, 40 instructions]
 * Source: src/rom/prepare_native59_attack_and_allocate_target_linked_projectile.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void prepare_native59_attack_and_allocate_target_linked_projectile(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    RAM8(0x005A + value) = 0;
    uint16_t value3 = BUS16(c, 0xC28746 + RAM16(0x00B0 + value));
    uint16_t value4 = RAM16(0x0287);
    r->a = value3 & 0xFF;
    r->x = value4;
    r->z = value4 == 0;
    r->n = value4 & 0x8000;
    { const uint16_t sp_call = r->sp; JSL(c, 0x86FD, 0xC0006C); GUARD_JSL(c, sp_call, 0x86FD); } /* boss_attack_row_public_jump */
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret = r->xf;
    if (x_ret) {
        uint8_t value5 = RAM8(0x0287);
        RAM16_SET(0x0295, RAM16(0x002B + value5));
        RAM16_SET(0x0297, RAM16(0x0032 + value5));
        uint16_t value8 = RAM16(0x00A9 + value5);
        RAM16_SET(0x0299, value8);
        RAM16_SET(0x029B, (uint16_t)((uint16_t)((((uint8_t)value8 << 8) | (value8 >> 8)) << 1) + 0xE000));
        c->fail = 3; /* operand size does not fit the register width on this path */
        return;
    } else {
        uint16_t value9 = RAM16(0x0287);
        RAM16_SET(0x0295, RAM16(0x002B + value9));
        RAM16_SET(0x0297, RAM16(0x0032 + value9));
        uint16_t value12 = RAM16(0x00A9 + value9);
        RAM16_SET(0x0299, value12);
        RAM16_SET(0x029B, (uint16_t)((uint16_t)((((uint8_t)value12 << 8) | (value12 >> 8)) << 1) + 0xE000));
        r->a = (uint16_t)((uint16_t)((((uint8_t)value12 << 8) | (value12 >> 8)) << 1) + 0xE000);
        r->x = 0x89D1;
        r->y = 0xAA01;
        r->c = (uint16_t)((((uint8_t)value12 << 8) | (value12 >> 8)) << 1) + 0xE000 > 0xFFFF;
        r->z = 0;
        r->n = 1;
        r->v = (((uint16_t)((((uint8_t)value12 << 8) | (value12 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value12 << 8) | (value12 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value12 << 8) | (value12 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x871F, 0xC20D53); GUARD_JSR(c, sp_call, 0x871F); } /* allocate_boss_object_pool_slot */
        uint16_t x_ret3 = r->x;
        RAM16_SET(0x002B + x_ret3, RAM16(0x0295));
        RAM16_SET(0x0032 + x_ret3, RAM16(0x0297));
        RAM16_SET(0x00A9 + x_ret3, RAM16(0x0299));
        RAM16_SET(0x00B0 + x_ret3, RAM16(0x0287));
        RAM16_SET(0x00B2 + x_ret3, RAM16(0x029B));
        RAM16_SET(0x0070 + x_ret3, 1);
        RAM16_SET(0x003C + x_ret3, 0);
        RAM16_SET(0x0040 + x_ret3, 0);
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC286E4, SOM_RTS, "gen", prepare_native59_attack_and_allocate_target_linked_projectile, 0, 0, 1, 0, 0, 98, 40)
