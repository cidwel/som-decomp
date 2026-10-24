.setcpu "65816"
.segment "RODATA"
.org $FADD
work_mask_b_1afadd:
    .byte (1 << 7) | (0 << 6) | (1 << 5) | (0 << 4) | (1 << 3) | (0 << 2) | (1 << 1) | (1 << 0)
