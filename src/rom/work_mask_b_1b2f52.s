.setcpu "65816"
.segment "RODATA"
.org $2F52
work_mask_b_1b2f52:
    .byte (1 << 7) | (0 << 6) | (1 << 5) | (0 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
