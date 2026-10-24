.setcpu "65816"
.segment "RODATA"
.org $FC8C
work_mask_b_1afc8c:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (0 << 4) | (1 << 3) | (0 << 2) | (1 << 1) | (0 << 0)
