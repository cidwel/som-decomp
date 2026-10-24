.setcpu "65816"
.segment "RODATA"
.org $50C0
work_c1_controls_20261014_0150c0:
    .byte $01 ; mode
    .byte (0 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (1 << 3) | (0 << 2) | (1 << 1) | (0 << 0) ; history_mask_msb_first
