.setcpu "65816"
.segment "RODATA"
.org $31E0
work_mask_b_1b31e0:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (1 << 4) | (0 << 3) | (0 << 2) | (0 << 1) | (0 << 0)
