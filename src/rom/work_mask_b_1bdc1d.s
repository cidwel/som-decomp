.setcpu "65816"
.segment "RODATA"
.org $DC1D
work_mask_b_1bdc1d:
    .byte (1 << 7) | (0 << 6) | (1 << 5) | (0 << 4) | (0 << 3) | (0 << 2) | (1 << 1) | (0 << 0)
