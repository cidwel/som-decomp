.setcpu "65816"
.segment "RODATA"
.org $FA0F
work_mask_b_1afa0f:
    .byte (1 << 7) | (0 << 6) | (1 << 5) | (0 << 4) | (1 << 3) | (0 << 2) | (1 << 1) | (1 << 0)
