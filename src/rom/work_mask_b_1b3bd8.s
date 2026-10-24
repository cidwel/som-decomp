.setcpu "65816"
.segment "RODATA"
.org $3BD8
work_mask_b_1b3bd8:
    .byte (1 << 7) | (0 << 6) | (1 << 5) | (0 << 4) | (1 << 3) | (0 << 2) | (1 << 1) | (0 << 0)
