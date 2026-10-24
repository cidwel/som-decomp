.setcpu "65816"
.segment "RODATA"
.org $43F5
work_mask_b_1b43f5:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (0 << 4) | (0 << 3) | (0 << 2) | (1 << 1) | (1 << 0)
