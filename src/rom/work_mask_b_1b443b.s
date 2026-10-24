.setcpu "65816"
.segment "RODATA"
.org $443B
work_mask_b_1b443b:
    .byte (1 << 7) | (0 << 6) | (0 << 5) | (1 << 4) | (0 << 3) | (0 << 2) | (0 << 1) | (0 << 0)
