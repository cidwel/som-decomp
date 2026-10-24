.setcpu "65816"
.segment "RODATA"
.org $F815
work_mask_b_1af815:
    .byte (0 << 7) | (0 << 6) | (0 << 5) | (1 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
