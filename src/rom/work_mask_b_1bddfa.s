.setcpu "65816"
.segment "RODATA"
.org $DDFA
work_mask_b_1bddfa:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (0 << 4) | (1 << 3) | (1 << 2) | (0 << 1) | (0 << 0)
