.setcpu "65816"
.segment "RODATA"
.org $FE36
work_mask_b_1afe36:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (1 << 4) | (1 << 3) | (0 << 2) | (1 << 1) | (1 << 0)
