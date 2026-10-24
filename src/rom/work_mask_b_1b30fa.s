.setcpu "65816"
.segment "RODATA"
.org $30FA
work_mask_b_1b30fa:
    .byte (1 << 7) | (0 << 6) | (1 << 5) | (0 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
