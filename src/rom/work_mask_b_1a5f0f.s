.setcpu "65816"
.segment "RODATA"
.org $5F0F
work_mask_b_1a5f0f:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (1 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
