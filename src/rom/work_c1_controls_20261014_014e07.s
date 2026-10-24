.setcpu "65816"
.segment "RODATA"
.org $4E07
work_c1_controls_20261014_014e07:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (0 << 4) | (1 << 3) | (0 << 2) | (1 << 1) | (0 << 0) ; history_mask_msb_first
