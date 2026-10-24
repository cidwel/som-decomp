; Original numeric control only; tile values/layout selectors excluded.
.setcpu "65816"
.segment "RODATA"
.org $916E
map_subpiece_control_source_20261014_ce916e:
    .byte $E8 | ((13-1)>>1)
    .byte (((13-1)&1)<<7) | (7-1)
