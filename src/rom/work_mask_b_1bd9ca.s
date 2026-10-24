.setcpu "65816"
.segment "RODATA"
.org $D9CA
work_mask_b_1bd9ca:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (0 << 4) | (0 << 3) | (0 << 2) | (0 << 1) | (0 << 0)
