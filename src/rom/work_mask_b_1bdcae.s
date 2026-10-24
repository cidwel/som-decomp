.setcpu "65816"
.segment "RODATA"
.org $DCAE
work_mask_b_1bdcae:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (0 << 4) | (0 << 3) | (0 << 2) | (1 << 1) | (1 << 0)
