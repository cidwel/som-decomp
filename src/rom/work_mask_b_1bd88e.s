.setcpu "65816"
.segment "RODATA"
.org $D88E
work_mask_b_1bd88e:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (0 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
