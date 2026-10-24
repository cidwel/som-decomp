.setcpu "65816"
.segment "RODATA"
.org $32CF
work_mask_b_1b32cf:
    .byte (0 << 7) | (0 << 6) | (1 << 5) | (0 << 4) | (1 << 3) | (0 << 2) | (1 << 1) | (1 << 0)
