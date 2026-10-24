; Original numeric control only; tile values/layout selectors excluded.
.setcpu "65816"
.segment "RODATA"
.org $5317
map_subpiece_control_source_20261014_cd5317:
    .byte $E8 | ((2-1)>>1)
    .byte (((2-1)&1)<<7) | (3-1)
    .byte $FE
