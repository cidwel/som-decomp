.setcpu "65816"
.segment "RODATA"
.org $64B0
work_mask_b_1a64b0:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (0 << 4) | (1 << 3) | (1 << 2) | (0 << 1) | (0 << 0)
