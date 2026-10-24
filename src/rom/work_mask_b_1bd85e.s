.setcpu "65816"
.segment "RODATA"
.org $D85E
work_mask_b_1bd85e:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (0 << 4) | (0 << 3) | (0 << 2) | (0 << 1) | (0 << 0)
