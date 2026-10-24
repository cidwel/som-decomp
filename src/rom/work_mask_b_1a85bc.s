.setcpu "65816"
.segment "RODATA"
.org $85BC
work_mask_b_1a85bc:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (0 << 4) | (1 << 3) | (0 << 2) | (1 << 1) | (0 << 0)
