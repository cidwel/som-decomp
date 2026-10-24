.setcpu "65816"
.segment "RODATA"
.org $DBEA
work_mask_b_1bdbea:
    .byte (0 << 7) | (0 << 6) | (0 << 5) | (0 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
