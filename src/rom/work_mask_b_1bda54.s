.setcpu "65816"
.segment "RODATA"
.org $DA54
work_mask_b_1bda54:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (0 << 4) | (0 << 3) | (0 << 2) | (1 << 1) | (1 << 0)
