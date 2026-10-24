.setcpu "65816"
.segment "RODATA"
.org $DC17
work_mask_b_1bdc17:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (0 << 4) | (1 << 3) | (0 << 2) | (1 << 1) | (0 << 0)
