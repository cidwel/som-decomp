; Original numeric control only; tile values/layout selectors excluded.
.setcpu "65816"
.segment "RODATA"
.org $F334
map_subpiece_control_source_20261014_ccf334:
    .byte $E8 | ((1-1)>>1)
    .byte (((1-1)&1)<<7) | (41-1)
    .byte $FE
