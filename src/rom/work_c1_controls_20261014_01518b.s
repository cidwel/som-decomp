.setcpu "65816"
.segment "RODATA"
.org $518B
work_c1_controls_20261014_01518b:
    .byte (1 << 7) | (0 << 6) | (1 << 5) | (0 << 4) | (1 << 3) | (0 << 2) | (0 << 1) | (0 << 0) ; history_mask_msb_first
