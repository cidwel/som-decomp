.setcpu "65816"
.segment "RODATA"
.org $3CF6
work_mask_b_1b3cf6:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (1 << 3) | (0 << 2) | (1 << 1) | (1 << 0)
