.setcpu "65816"
.segment "RODATA"
.org $FE8F
work_mask_b_1afe8f:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (1 << 4) | (1 << 3) | (0 << 2) | (1 << 1) | (1 << 0)
