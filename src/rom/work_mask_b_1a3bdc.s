.setcpu "65816"
.segment "RODATA"
.org $3BDC
work_mask_b_1a3bdc:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (0 << 4) | (1 << 3) | (0 << 2) | (0 << 1) | (1 << 0)
