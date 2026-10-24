.setcpu "65816"
.segment "RODATA"
.org $2D2C
work_mask_b_1b2d2c:
    .byte (1 << 7) | (0 << 6) | (1 << 5) | (1 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
