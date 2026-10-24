.setcpu "65816"
.segment "RODATA"
.org $DB5C
work_mask_b_1bdb5c:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (0 << 3) | (0 << 2) | (1 << 1) | (1 << 0)
