.setcpu "65816"
.segment "RODATA"
.org $FD75
work_mask_b_1afd75:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (0 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
