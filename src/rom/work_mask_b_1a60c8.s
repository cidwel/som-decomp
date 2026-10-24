.setcpu "65816"
.segment "RODATA"
.org $60C8
work_mask_b_1a60c8:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
