.setcpu "65816"
.segment "RODATA"
.org $2F0F
work_mask_b_1b2f0f:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (0 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
