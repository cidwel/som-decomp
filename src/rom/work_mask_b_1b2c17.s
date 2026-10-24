.setcpu "65816"
.segment "RODATA"
.org $2C17
work_mask_b_1b2c17:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (1 << 3) | (0 << 2) | (1 << 1) | (1 << 0)
