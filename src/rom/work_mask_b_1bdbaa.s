.setcpu "65816"
.segment "RODATA"
.org $DBAA
work_mask_b_1bdbaa:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (1 << 3) | (1 << 2) | (0 << 1) | (0 << 0)
