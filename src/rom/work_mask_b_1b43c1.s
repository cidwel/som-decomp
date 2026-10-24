.setcpu "65816"
.segment "RODATA"
.org $43C1
work_mask_b_1b43c1:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (1 << 3) | (0 << 2) | (0 << 1) | (0 << 0)
