.setcpu "65816"
.segment "RODATA"
.org $31FF
work_mask_b_1b31ff:
    .byte (0 << 7) | (0 << 6) | (0 << 5) | (0 << 4) | (1 << 3) | (0 << 2) | (1 << 1) | (1 << 0)
