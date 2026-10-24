.setcpu "65816"
.segment "RODATA"
.org $43FA
work_mask_b_1b43fa:
    .byte (1 << 7) | (0 << 6) | (0 << 5) | (1 << 4) | (0 << 3) | (0 << 2) | (1 << 1) | (1 << 0)
