.setcpu "65816"
.segment "RODATA"
.org $FBBA
work_mask_b_1afbba:
    .byte (0 << 7) | (1 << 6) | (0 << 5) | (1 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
