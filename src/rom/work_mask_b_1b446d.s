.setcpu "65816"
.segment "RODATA"
.org $446D
work_mask_b_1b446d:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (0 << 3) | (0 << 2) | (0 << 1) | (0 << 0)
