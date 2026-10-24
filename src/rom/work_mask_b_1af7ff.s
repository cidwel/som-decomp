.setcpu "65816"
.segment "RODATA"
.org $F7FF
work_mask_b_1af7ff:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (0 << 4) | (0 << 3) | (0 << 2) | (0 << 1) | (0 << 0)
