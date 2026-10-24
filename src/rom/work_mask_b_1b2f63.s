.setcpu "65816"
.segment "RODATA"
.org $2F63
work_mask_b_1b2f63:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (0 << 4) | (0 << 3) | (0 << 2) | (0 << 1) | (0 << 0)
