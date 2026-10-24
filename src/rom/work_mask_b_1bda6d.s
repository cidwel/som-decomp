.setcpu "65816"
.segment "RODATA"
.org $DA6D
work_mask_b_1bda6d:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (0 << 4) | (0 << 3) | (0 << 2) | (1 << 1) | (1 << 0)
