.setcpu "65816"
.segment "RODATA"
.org $2C4B
work_mask_b_1b2c4b:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (0 << 4) | (1 << 3) | (0 << 2) | (1 << 1) | (0 << 0)
