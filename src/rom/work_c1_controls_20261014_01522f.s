.setcpu "65816"
.segment "RODATA"
.org $522F
work_c1_controls_20261014_01522f:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (0 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (0 << 0) ; history_mask_msb_first
