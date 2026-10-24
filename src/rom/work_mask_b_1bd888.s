.setcpu "65816"
.segment "RODATA"
.org $D888
work_mask_b_1bd888:
    .byte (0 << 7) | (1 << 6) | (0 << 5) | (1 << 4) | (0 << 3) | (0 << 2) | (0 << 1) | (0 << 0)
