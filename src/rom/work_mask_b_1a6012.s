.setcpu "65816"
.segment "RODATA"
.org $6012
work_mask_b_1a6012:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (1 << 4) | (1 << 3) | (0 << 2) | (1 << 1) | (1 << 0)
