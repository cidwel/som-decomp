.setcpu "65816"
.segment "RODATA"
.org $384E
work_mask_b_1b384e:
    .byte (1 << 7) | (0 << 6) | (1 << 5) | (0 << 4) | (1 << 3) | (0 << 2) | (1 << 1) | (0 << 0)
