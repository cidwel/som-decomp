.setcpu "65816"
.segment "RODATA"
.org $DB1E
work_mask_b_1bdb1e:
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (1 << 4) | (0 << 3) | (1 << 2) | (0 << 1) | (1 << 0)
