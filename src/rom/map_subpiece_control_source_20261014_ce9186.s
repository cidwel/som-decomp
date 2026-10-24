; Original numeric control only; tile values/layout selectors excluded.
.setcpu "65816"
.segment "RODATA"
.org $9186
map_subpiece_control_source_20261014_ce9186:
    .byte $E8 | ((12-1)>>1)
    .byte (((12-1)&1)<<7) | (4-1)
    .byte $C0 | ((1-1)<<3) | (2-1)
