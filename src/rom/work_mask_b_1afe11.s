.setcpu "65816"
.segment "RODATA"
.org $FE11
work_mask_b_1afe11:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (0 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
