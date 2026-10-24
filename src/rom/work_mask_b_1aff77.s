.setcpu "65816"
.segment "RODATA"
.org $FF77
work_mask_b_1aff77:
    .byte (1 << 7) | (0 << 6) | (1 << 5) | (0 << 4) | (0 << 3) | (0 << 2) | (0 << 1) | (0 << 0)
