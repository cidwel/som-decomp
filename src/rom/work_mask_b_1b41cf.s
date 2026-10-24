.setcpu "65816"
.segment "RODATA"
.org $41CF
work_mask_b_1b41cf:
    .byte (0 << 7) | (0 << 6) | (0 << 5) | (0 << 4) | (1 << 3) | (0 << 2) | (1 << 1) | (0 << 0)
