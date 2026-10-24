.setcpu "65816"
.segment "RODATA"
.org $DDFF
work_mask_b_1bddff:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (1 << 3) | (1 << 2) | (0 << 1) | (0 << 0)
