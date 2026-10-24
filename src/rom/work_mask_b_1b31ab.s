.setcpu "65816"
.segment "RODATA"
.org $31AB
work_mask_b_1b31ab:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (0 << 4) | (1 << 3) | (1 << 2) | (0 << 1) | (0 << 0)
