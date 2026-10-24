.setcpu "65816"
.segment "RODATA"
.org $3B90
work_mask_b_1b3b90:
    .byte (1 << 7) | (0 << 6) | (0 << 5) | (0 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
