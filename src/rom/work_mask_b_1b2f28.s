.setcpu "65816"
.segment "RODATA"
.org $2F28
work_mask_b_1b2f28:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (0 << 4) | (0 << 3) | (0 << 2) | (1 << 1) | (1 << 0)
