.setcpu "65816"
.segment "RODATA"
.org $DA7B
work_mask_b_1bda7b:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (0 << 4) | (1 << 3) | (0 << 2) | (1 << 1) | (0 << 0)
