.setcpu "65816"
.segment "RODATA"
.org $FA60
work_mask_b_1afa60:
    .byte (0 << 7) | (0 << 6) | (0 << 5) | (0 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
