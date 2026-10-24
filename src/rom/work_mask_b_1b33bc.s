.setcpu "65816"
.segment "RODATA"
.org $33BC
work_mask_b_1b33bc:
    .byte (1 << 7) | (0 << 6) | (1 << 5) | (1 << 4) | (1 << 3) | (1 << 2) | (0 << 1) | (0 << 0)
