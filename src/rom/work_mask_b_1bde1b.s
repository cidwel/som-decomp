.setcpu "65816"
.segment "RODATA"
.org $DE1B
work_mask_b_1bde1b:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
