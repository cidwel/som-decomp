.setcpu "65816"
.segment "RODATA"
.org $54AF
work_mask_b_1a54af:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (0 << 4) | (0 << 3) | (0 << 2) | (0 << 1) | (1 << 0)
