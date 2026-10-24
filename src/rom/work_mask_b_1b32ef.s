.setcpu "65816"
.segment "RODATA"
.org $32EF
work_mask_b_1b32ef:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (0 << 4) | (1 << 3) | (0 << 2) | (1 << 1) | (1 << 0)
