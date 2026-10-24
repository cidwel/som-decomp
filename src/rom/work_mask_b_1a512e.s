.setcpu "65816"
.segment "RODATA"
.org $512E
work_mask_b_1a512e:
    .byte (0 << 7) | (0 << 6) | (1 << 5) | (1 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
