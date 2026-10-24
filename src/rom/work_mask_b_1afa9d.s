.setcpu "65816"
.segment "RODATA"
.org $FA9D
work_mask_b_1afa9d:
    .byte (1 << 7) | (0 << 6) | (1 << 5) | (0 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
