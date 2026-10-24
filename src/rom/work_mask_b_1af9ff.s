.setcpu "65816"
.segment "RODATA"
.org $F9FF
work_mask_b_1af9ff:
    .byte (0 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
