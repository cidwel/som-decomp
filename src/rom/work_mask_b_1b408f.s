.setcpu "65816"
.segment "RODATA"
.org $408F
work_mask_b_1b408f:
    .byte (0 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
