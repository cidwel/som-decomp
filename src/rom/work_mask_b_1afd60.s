.setcpu "65816"
.segment "RODATA"
.org $FD60
work_mask_b_1afd60:
    .byte (1 << 7) | (0 << 6) | (1 << 5) | (1 << 4) | (0 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
