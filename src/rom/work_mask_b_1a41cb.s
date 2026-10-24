.setcpu "65816"
.segment "RODATA"
.org $41CB
work_mask_b_1a41cb:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (0 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
