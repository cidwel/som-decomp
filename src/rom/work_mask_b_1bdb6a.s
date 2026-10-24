.setcpu "65816"
.segment "RODATA"
.org $DB6A
work_mask_b_1bdb6a:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (0 << 3) | (0 << 2) | (1 << 1) | (1 << 0)
