.setcpu "65816"
.segment "RODATA"
.org $588C
work_c1_controls_20261014_01588c:
    .byte $01 ; mode
    .byte (1 << 7) | (1 << 6) | (0 << 5) | (0 << 4) | (0 << 3) | (0 << 2) | (0 << 1) | (0 << 0) ; history_mask_msb_first
