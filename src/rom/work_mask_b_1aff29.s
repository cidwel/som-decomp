.setcpu "65816"
.segment "RODATA"
.org $FF29
work_mask_b_1aff29:
    .byte (1 << 7) | (0 << 6) | (0 << 5) | (0 << 4) | (0 << 3) | (0 << 2) | (1 << 1) | (0 << 0)
