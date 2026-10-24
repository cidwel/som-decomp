.setcpu "65816"
.segment "RODATA"
.org $502F
work_mask_b_1a502f:
    .byte (1 << 7) | (0 << 6) | (1 << 5) | (1 << 4) | (0 << 3) | (0 << 2) | (1 << 1) | (1 << 0)
