.setcpu "65816"
.segment "RODATA"
.org $FF5D
work_mask_b_1aff5d:
    .byte (1 << 7) | (0 << 6) | (0 << 5) | (0 << 4) | (1 << 3) | (0 << 2) | (1 << 1) | (0 << 0)
