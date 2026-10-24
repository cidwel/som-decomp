.setcpu "65816"
.segment "RODATA"
.org $3F03
work_mask_b_1b3f03:
    .byte (1 << 7) | (0 << 6) | (1 << 5) | (1 << 4) | (1 << 3) | (0 << 2) | (1 << 1) | (1 << 0)
