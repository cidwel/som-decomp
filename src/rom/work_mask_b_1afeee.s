.setcpu "65816"
.segment "RODATA"
.org $FEEE
work_mask_b_1afeee:
    .byte (1 << 7) | (0 << 6) | (1 << 5) | (1 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (0 << 0)
