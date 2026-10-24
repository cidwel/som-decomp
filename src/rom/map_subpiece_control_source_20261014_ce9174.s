; Original numeric control only; tile values/layout selectors excluded.
.setcpu "65816"
.segment "RODATA"
.org $9174
map_subpiece_control_source_20261014_ce9174:
    .byte $E8 | ((14-1)>>1)
    .byte (((14-1)&1)<<7) | (8-1)
    .byte $E8 | ((12-1)>>1)
    .byte (((12-1)&1)<<7) | (3-1)
