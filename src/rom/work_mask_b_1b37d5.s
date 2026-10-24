.setcpu "65816"
.segment "RODATA"
.org $37D5
work_mask_b_1b37d5:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
