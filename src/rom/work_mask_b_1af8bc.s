.setcpu "65816"
.segment "RODATA"
.org $F8BC
work_mask_b_1af8bc:
    .byte (1 << 7) | (0 << 6) | (0 << 5) | (0 << 4) | (0 << 3) | (1 << 2) | (0 << 1) | (1 << 0)
