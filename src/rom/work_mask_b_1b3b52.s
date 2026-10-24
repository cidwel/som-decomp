.setcpu "65816"
.segment "RODATA"
.org $3B52
work_mask_b_1b3b52:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (1 << 3) | (0 << 2) | (1 << 1) | (1 << 0)
