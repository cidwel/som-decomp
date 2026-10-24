; Original numeric control only; tile values/layout selectors excluded.
.setcpu "65816"
.segment "RODATA"
.org $5657
map_subpiece_control_source_20261014_ce5657:
    .byte $E8 | ((1-1)>>1)
    .byte (((1-1)&1)<<7) | (41-1)
    .byte $FF
