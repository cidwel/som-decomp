.setcpu "65816"
.segment "RODATA"
.org $3BF1
work_mask_b_1b3bf1:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
