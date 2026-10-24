.setcpu "65816"
.segment "RODATA"
.org $3FF1
work_mask_b_1a3ff1:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (0 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
