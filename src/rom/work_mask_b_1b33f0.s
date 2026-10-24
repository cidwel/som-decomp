.setcpu "65816"
.segment "RODATA"
.org $33F0
work_mask_b_1b33f0:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (0 << 4) | (1 << 3) | (1 << 2) | (0 << 1) | (0 << 0)
