.setcpu "65816"
.segment "RODATA"
.org $41F4
work_mask_b_1a41f4:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (0 << 3) | (0 << 2) | (1 << 1) | (1 << 0)
