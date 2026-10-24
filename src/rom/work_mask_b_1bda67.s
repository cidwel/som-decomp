.setcpu "65816"
.segment "RODATA"
.org $DA67
work_mask_b_1bda67:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (1 << 3) | (0 << 2) | (0 << 1) | (0 << 0)
