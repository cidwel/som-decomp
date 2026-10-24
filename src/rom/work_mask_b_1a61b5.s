.setcpu "65816"
.segment "RODATA"
.org $61B5
work_mask_b_1a61b5:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (1 << 3) | (1 << 2) | (0 << 1) | (1 << 0)
