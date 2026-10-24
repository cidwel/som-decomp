.setcpu "65816"
.segment "RODATA"
.org $61C5
work_mask_b_1a61c5:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (1 << 4) | (0 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
