.setcpu "65816"
.segment "RODATA"
.org $5194
work_c1_controls_20261014_015194:
    .byte $01 ; mode
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (0 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (0 << 0) ; history_mask_msb_first
