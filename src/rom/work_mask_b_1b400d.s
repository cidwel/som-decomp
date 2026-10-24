.setcpu "65816"
.segment "RODATA"
.org $400D
work_mask_b_1b400d:
    .byte (1 << 7) | (0 << 6) | (1 << 5) | (1 << 4) | (1 << 3) | (0 << 2) | (0 << 1) | (0 << 0)
