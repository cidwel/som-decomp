.setcpu "65816"
.segment "RODATA"
.org $432B
work_mask_b_1b432b:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (0 << 4) | (1 << 3) | (0 << 2) | (0 << 1) | (0 << 0)
