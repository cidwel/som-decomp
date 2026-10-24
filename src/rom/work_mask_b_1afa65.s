.setcpu "65816"
.segment "RODATA"
.org $FA65
work_mask_b_1afa65:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (1 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
