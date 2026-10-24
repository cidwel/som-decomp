.setcpu "65816"
.segment "RODATA"
.org $43BB
work_mask_b_1b43bb:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (1 << 4) | (0 << 3) | (1 << 2) | (0 << 1) | (1 << 0)
