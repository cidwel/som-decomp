.setcpu "65816"
.segment "RODATA"
.org $35D9
work_mask_b_1b35d9:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (1 << 3) | (0 << 2) | (1 << 1) | (0 << 0)
