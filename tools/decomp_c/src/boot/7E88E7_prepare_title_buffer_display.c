#include "som_c.h"
#include "som_hand.h"

/* 7E88E7 prepare_title_buffer_display   [class B, 365 bytes, 154 instructions]
 * Source: src/boot/prepare_title_buffer_display.s
 * Entry: M=16 bit X=16 bit DB=$7F D=$06F1.  Callers read: nothing.
 */
static void prepare_title_buffer_display(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    if (r->dp != 0x06F1) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t i_entry = r->i;
    i_phd(c);
    i_php(c);
    RAM8(0x10056) = 0x78;
    RAM8(0x10059) = 0x1F;
    RAM8(0x1005C) = 0x38;
    RAM8(0x1005F) = 1;
    RAM8(0x10062) = 0;
    RAM16_SET(0x10057, 0);
    RAM16_SET(0x1005A, 0);
    RAM16_SET(0x1005D, 0);
    RAM16_SET(0x10060, 0);
    r->a = 5;
    r->z = 0;
    r->n = 0;
    JSR(c, 0x8917, 0x7E8FC7); /* allocate_transfer_descriptor */
    uint16_t x_ret = r->x;
    RAM16_SET(0x1003A, x_ret);
    RAM16_SET(0x10002 + x_ret, 0x56);
    RAM8(0x10004 + x_ret) = 0x7F;
    RAM8(0x10001 + x_ret) = 0x10;
    RAM8(0x10000 + x_ret) = 2;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x8934, 0x7E90DA); /* submit_transfer_or_program_hdma */
    bool carry_ret2 = r->c;
    bool overflow_ret2 = r->v;
    i_php(c); /* PHP, then SEI for the three HDMA programs */
    r->x = 0x4A;
    r->y = 0x5CFB;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    r->i = 1;
    JSR(c, 0x893F, 0x7E886E); /* prepare_title_auxiliary_hdma */
    r->x = 0x46;
    r->y = 0x5CC7;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x8948, 0x7E886E); /* prepare_title_auxiliary_hdma */
    r->x = 0x42;
    r->y = 0x5C93;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x8951, 0x7E886E); /* prepare_title_auxiliary_hdma */
    uint16_t a_all5 = r->a;
    r->a = (a_all5 >> 8 << 8) | 5;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x8956, 0x7E8FC7); /* allocate_transfer_descriptor */
    uint16_t x_ret6 = r->x;
    RAM16_SET(0x10040, x_ret6);
    RAM16_SET(0x10002 + x_ret6, 0x5C75);
    RAM8(0x10004 + x_ret6) = 0x7E;
    RAM8(0x10001 + x_ret6) = 0x21;
    RAM8(0x10000 + x_ret6) = 0;
    r->z = 1;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x8975, 0x7E90DA); /* submit_transfer_or_program_hdma */
    r->sp++; som_pull_p(c, r->sp); /* PLP */
    r->x = 0x11;
    r->y = 0x5C64;
    r->c = carry_ret2;
    r->z = 0;
    r->n = 0;
    r->v = overflow_ret2;
    r->mf = 1;
    r->xf = 0;
    r->i = i_entry;
    push16(c, 0x11);
    push8(c, 0x7E);
    push16(c, 0x5C64);
    JSR(c, 0x8984, 0x7EB081); /* allocate_boot_heap_bytes_without_fill */
    uint16_t x_ret8 = r->x;
    RAM16_SET(0x10054, x_ret8);
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    push8(c, 0x7F);
    push16(c, x_ret8);
    JSR(c, 0x898E, 0x7EC44E); /* copy_far_stack_arguments */
    r->sp += 8; /* TSC, CLC, ADC #$0008, TCS drops the arguments */
    r->a = ((uint16_t)((uint16_t)(sp0 - 0x0B) + 8) >> 8 << 8) | 5;
    r->c = (uint16_t)(sp0 - 0x0B) + 8 > 0xFFFF;
    r->z = 0;
    r->n = 0;
    r->v = (((uint16_t)(sp0 - 0x0B) ^ (uint16_t)((uint16_t)(sp0 - 0x0B) + 8)) & ((uint16_t)((uint16_t)(sp0 - 0x0B) + 8) ^ 8) & 0x8000) != 0;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x899D, 0x7E8FC7); /* allocate_transfer_descriptor */
    uint16_t x_ret10 = r->x;
    RAM16_SET(0x1003E, x_ret10);
    RAM16_SET(0x10002 + x_ret10, RAM16(0x10054));
    RAM8(0x10004 + x_ret10) = 0x7F;
    RAM8(0x10001 + x_ret10) = 0x2D;
    RAM8(0x10000 + x_ret10) = 0;
    r->z = 1;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x89BC, 0x7E90DA); /* submit_transfer_or_program_hdma */
    r->x = 0x11;
    r->y = 0x5C53;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    push16(c, 0x11);
    push8(c, 0x7E);
    push16(c, 0x5C53);
    JSR(c, 0x89CA, 0x7EB081); /* allocate_boot_heap_bytes_without_fill */
    uint16_t x_ret12 = r->x;
    RAM16_SET(0x10052, x_ret12);
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    push8(c, 0x7F);
    push16(c, x_ret12);
    JSR(c, 0x89D4, 0x7EC44E); /* copy_far_stack_arguments */
    r->sp += 8; /* TSC, CLC, ADC #$0008, TCS drops the arguments */
    r->a = ((uint16_t)((uint16_t)(sp0 - 0x0B) + 8) >> 8 << 8) | 5;
    r->c = (uint16_t)(sp0 - 0x0B) + 8 > 0xFFFF;
    r->z = 0;
    r->n = 0;
    r->v = (((uint16_t)(sp0 - 0x0B) ^ (uint16_t)((uint16_t)(sp0 - 0x0B) + 8)) & ((uint16_t)((uint16_t)(sp0 - 0x0B) + 8) ^ 8) & 0x8000) != 0;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x89E3, 0x7E8FC7); /* allocate_transfer_descriptor */
    uint16_t x_ret14 = r->x;
    RAM16_SET(0x1003C, x_ret14);
    RAM16_SET(0x10002 + x_ret14, RAM16(0x10052));
    RAM8(0x10004 + x_ret14) = 0x7F;
    RAM8(0x10001 + x_ret14) = 0x27;
    RAM8(0x10000 + x_ret14) = 0;
    r->z = 1;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x8A02, 0x7E90DA); /* submit_transfer_or_program_hdma */
    uint16_t a_all15 = r->a;
    r->a = (a_all15 >> 8 << 8) | 0x26;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x8A07, 0x7EC030); /* allocate_ppu_register_entry */
    uint16_t x_ret16 = r->x;
    RAM8(0x10002 + x_ret16) = 0;
    r->z = 1;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x8A0F, 0x7EC097); /* append_oneshot_ppu_entry */
    uint16_t a_all17 = r->a;
    r->a = (a_all17 >> 8 << 8) | 0x27;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x8A14, 0x7EC030); /* allocate_ppu_register_entry */
    uint16_t x_ret17 = r->x;
    RAM8(0x10002 + x_ret17) = 0xFF;
    r->z = 0;
    r->n = 1;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x8A1C, 0x7EC097); /* append_oneshot_ppu_entry */
    uint16_t a_all19 = r->a;
    r->a = (a_all19 >> 8 << 8) | 0x30;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x8A21, 0x7EC030); /* allocate_ppu_register_entry */
    uint16_t x_ret18 = r->x;
    RAM8(0x10002 + x_ret18) = 2;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x8A29, 0x7EC097); /* append_oneshot_ppu_entry */
    uint16_t a_all21 = r->a;
    r->a = (a_all21 >> 8 << 8) | 0x31;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x8A2E, 0x7EC030); /* allocate_ppu_register_entry */
    uint16_t x_ret19 = r->x;
    RAM8(0x10002 + x_ret19) = 0x31;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x8A36, 0x7EC097); /* append_oneshot_ppu_entry */
    uint16_t a_all23 = r->a;
    r->a = (a_all23 >> 8 << 8) | 0x2E;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x8A3B, 0x7EC030); /* allocate_ppu_register_entry */
    uint16_t x_ret20 = r->x;
    RAM8(0x10002 + x_ret20) = 2;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x8A43, 0x7EC097); /* append_oneshot_ppu_entry */
    uint16_t a_all25 = r->a;
    r->a = (a_all25 >> 8 << 8) | 0x23;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x8A48, 0x7EC030); /* allocate_ppu_register_entry */
    uint16_t x_ret21 = r->x;
    RAM8(0x10002 + x_ret21) = 0x30;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x8A50, 0x7EC097); /* append_oneshot_ppu_entry */
    r->sp++;
    som_pull_p(c, r->sp); /* PLP */
    r->dp = RAM16(r->sp + 1); /* PLD */
    r->sp += 2;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E88E7, SOM_RTS, "hand", prepare_title_buffer_display, 0, 0, 11, 0, 0, 365, 154)
