.setcpu "65816"
.segment "RODATA"
.org $42FB
work_mask_b_1b42fb:
    .byte (0 << 7) | (0 << 6) | (1 << 5) | (0 << 4) | (1 << 3) | (0 << 2) | (1 << 1) | (1 << 0)
