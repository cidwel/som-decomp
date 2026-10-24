.setcpu "65816"
.segment "RODATA"
.org $DA37
work_mask_b_1bda37:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (0 << 4) | (0 << 3) | (0 << 2) | (0 << 1) | (0 << 0)
