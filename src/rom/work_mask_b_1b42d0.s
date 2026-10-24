.setcpu "65816"
.segment "RODATA"
.org $42D0
work_mask_b_1b42d0:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (1 << 4) | (0 << 3) | (0 << 2) | (1 << 1) | (1 << 0)
