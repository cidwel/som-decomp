; Original numeric control only; tile values/layout selectors excluded.
.setcpu "65816"
.segment "RODATA"
.org $5483
map_subpiece_control_source_20261014_cd5483:
    .byte $C0 | ((1-1)<<3) | (3-1)
    .byte $E8 | ((10-1)>>1)
    .byte (((10-1)&1)<<7) | (4-1)
    .byte $FE
