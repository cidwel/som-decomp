; Original numeric control only; tile values/layout selectors excluded.
.setcpu "65816"
.segment "RODATA"
.org $918D
map_subpiece_control_source_20261014_ce918d:
    .byte $E8 | ((10-1)>>1)
    .byte (((10-1)&1)<<7) | (3-1)
    .byte $FF
