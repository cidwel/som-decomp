.setcpu "65816"
.segment "RODATA"
.org $510C
work_c1_controls_20261014_01510c:
    .byte (0 << 7) | (0 << 6) | (1 << 5) | (1 << 4) | (1 << 3) | (0 << 2) | (1 << 1) | (1 << 0) ; history_mask_msb_first
