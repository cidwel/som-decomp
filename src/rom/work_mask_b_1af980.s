.setcpu "65816"
.segment "RODATA"
.org $F980
work_mask_b_1af980:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (1 << 3) | (1 << 2) | (0 << 1) | (1 << 0)
