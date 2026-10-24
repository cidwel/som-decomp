#include "som_c.h"

/* C1DC48 prepare_queued_native_motion_presentation   [class B, 71 bytes, 36 instructions]
 * Source: src/rom/prepare_queued_native_motion_presentation.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYCV.
 */
static void prepare_queued_native_motion_presentation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    uint8_t value = RAM8(0x19F3);
    if (RAM8(0xE060 + (((value & 3) << 1 << 8) | 0)) == 0) {
        RAM8(0xE110 + (((value & 3) << 1 << 8) | 0)) = 0;
        RAM8(0xE108 + (((value & 3) << 1 << 8) | 0)) = 0;
        RAM8(0xE121 + (((value & 3) << 1 << 8) | 0)) = RAM8(0x19F1);
        RAM16_SET(0xE10C + (((value & 3) << 1 << 8) | 0), ((RAM8(0x19F2) & 3) << 1 << 8) | 0);
        uint16_t value5 = RAM16(0x19F1);
        RAM8(0x0000 + sp0) = (value5 & 0xFF) << 1 << 1 << 1 << 1 >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)((value5 & 0xFF) << 1 << 1 << 1 << 1);
        RAM8(0x0000 + sp0 - 2) = (value & 3) << 1;
        RAM8(0x0000 + sp0 - 3) = (uint8_t)(((value & 3) << 1 << 8) | 0);
        r->a = (value5 & 0xFF) << 1 << 1 << 1 << 1;
        r->x = (value5 & 0xFF) << 1 << 1 << 1 << 1;
        r->y = ((value & 3) << 1 << 8) | 0;
        r->c = (value5 & 0xFF) << 1 << 1 << 1 & 0x8000;
        r->z = (value5 & 0xFF) << 1 << 1 << 1 << 1 == 0;
        r->n = (value5 & 0xFF) << 1 << 1 << 1 << 1 & 0x8000;
        r->mf = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0xDC85, 0xC186C6); GUARD_JSR(c, sp_call, 0xDC85); } /* load_queued_native_motion_presentation_graphics */
        r->sp += 4;
        bool x_ret = r->xf;
        if (x_ret) {
            uint8_t value6 = RAM8(0x0000 + sp0 - 3);
            uint8_t value7 = RAM8(0x0000 + sp0 - 2);
            r->x = value7;
            r->y = value6;
            r->z = value7 == 0;
            r->n = value7 & 0x80;
            r->xf = 1;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSL(c, 0xDC8B, 0x02B49C); GUARD_JSL(c, sp_call, 0xDC8B); } /* publish_queued_native_motion_and_saved_restore_state */
            r->sp += 2;
            r->mf = 0;
            r->xf = 1;
            TAIL_CALL_FRAME(c, 0xC185D8, SOM_RTS, 2); /* load_object_weapon_palette_from_field_04f */
        } else {
            uint8_t value8 = RAM8(0x0000 + sp0 - 3);
            uint8_t value9 = RAM8(0x0000 + sp0 - 2);
            uint8_t value10 = RAM8(0x0000 + sp0 - 1);
            uint8_t value11 = RAM8(0x0000 + sp0);
            r->x = (value11 << 8) | value10;
            r->y = (value9 << 8) | value8;
            r->z = ((value11 << 8) | value10) == 0;
            r->n = ((value11 << 8) | value10) & 0x8000;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSL(c, 0xDC8B, 0x02B49C); GUARD_JSL(c, sp_call, 0xDC8B); } /* publish_queued_native_motion_and_saved_restore_state */
            r->mf = 0;
            r->xf = 0;
            TAIL_CALL(c, 0xC185D8, SOM_RTS); /* load_object_weapon_palette_from_field_04f */
        }
    }
    r->a = (r->a & 0x00FF) | (((value & 3) << 1) << 8);
    r->y = ((value & 3) << 1 << 8) | 0;
    r->c = value & 3 & 0x80;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1DC48, SOM_RTS, "gen", prepare_queued_native_motion_presentation, 0, L_B | L_Y | L_C | L_V, 4, 1, 0, 71, 36)
