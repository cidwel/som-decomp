.setcpu "65816"
.segment "RODATA"
.org $DCBA
work_mask_b_1bdcba:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (0 << 4) | (0 << 3) | (0 << 2) | (0 << 1) | (0 << 0)
