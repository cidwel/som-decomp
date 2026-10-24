.setcpu "65816"
.segment "RODATA"
.org $410E
work_mask_b_1b410e:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (0 << 4) | (0 << 3) | (0 << 2) | (1 << 1) | (1 << 0)
