.setcpu "65816"
.segment "RODATA"
.org $F86E
work_mask_b_1af86e:
    .byte (1 << 7) | (0 << 6) | (1 << 5) | (0 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
