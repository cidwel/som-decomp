.setcpu "65816"
.segment "RODATA"
.org $32E2
work_mask_b_1b32e2:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (0 << 4) | (0 << 3) | (0 << 2) | (1 << 1) | (1 << 0)
