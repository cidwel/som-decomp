.setcpu "65816"
.segment "RODATA"
.org $DA1B
work_mask_b_1bda1b:
    .byte (1 << 7) | (0 << 6) | (1 << 5) | (0 << 4) | (0 << 3) | (0 << 2) | (1 << 1) | (0 << 0)
