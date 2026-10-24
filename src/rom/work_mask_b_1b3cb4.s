.setcpu "65816"
.segment "RODATA"
.org $3CB4
work_mask_b_1b3cb4:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (1 << 4) | (0 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
