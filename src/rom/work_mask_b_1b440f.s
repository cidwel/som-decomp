.setcpu "65816"
.segment "RODATA"
.org $440F
work_mask_b_1b440f:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (0 << 3) | (0 << 2) | (1 << 1) | (1 << 0)
