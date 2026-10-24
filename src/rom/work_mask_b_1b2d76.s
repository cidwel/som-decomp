.setcpu "65816"
.segment "RODATA"
.org $2D76
work_mask_b_1b2d76:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (0 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
