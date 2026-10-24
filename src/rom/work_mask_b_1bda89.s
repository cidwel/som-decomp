.setcpu "65816"
.segment "RODATA"
.org $DA89
work_mask_b_1bda89:
    .byte (0 << 7) | (0 << 6) | (1 << 5) | (0 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
