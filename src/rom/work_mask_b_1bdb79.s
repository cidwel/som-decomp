.setcpu "65816"
.segment "RODATA"
.org $DB79
work_mask_b_1bdb79:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (0 << 3) | (0 << 2) | (1 << 1) | (1 << 0)
