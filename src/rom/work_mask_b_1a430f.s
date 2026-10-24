.setcpu "65816"
.segment "RODATA"
.org $430F
work_mask_b_1a430f:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (0 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
