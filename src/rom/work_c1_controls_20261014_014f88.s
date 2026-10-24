.setcpu "65816"
.segment "RODATA"
.org $4F88
work_c1_controls_20261014_014f88:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (0 << 4) | (1 << 3) | (0 << 2) | (1 << 1) | (0 << 0) ; history_mask_msb_first
