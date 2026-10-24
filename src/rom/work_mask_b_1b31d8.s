.setcpu "65816"
.segment "RODATA"
.org $31D8
work_mask_b_1b31d8:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (1 << 4) | (1 << 3) | (0 << 2) | (0 << 1) | (0 << 0)
