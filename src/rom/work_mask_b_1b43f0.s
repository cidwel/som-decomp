.setcpu "65816"
.segment "RODATA"
.org $43F0
work_mask_b_1b43f0:
    .byte (1 << 7) | (0 << 6) | (0 << 5) | (1 << 4) | (0 << 3) | (0 << 2) | (1 << 1) | (1 << 0)
