.setcpu "65816"
.segment "RODATA"
.org $5112
work_c1_controls_20261014_015112:
    .byte (0 << 7) | (0 << 6) | (0 << 5) | (0 << 4) | (0 << 3) | (0 << 2) | (0 << 1) | (0 << 0) ; history_mask_msb_first
    .byte (0 << 7) | (0 << 6) | (0 << 5) | (0 << 4) | (0 << 3) | (0 << 2) | (0 << 1) | (0 << 0) ; history_mask_msb_first
    .byte $01 ; mode
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (0 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (0 << 0) ; history_mask_msb_first
