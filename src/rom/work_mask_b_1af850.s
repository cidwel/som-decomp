.setcpu "65816"
.segment "RODATA"
.org $F850
work_mask_b_1af850:
    .byte (1 << 7) | (0 << 6) | (1 << 5) | (0 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
