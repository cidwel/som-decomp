; Original numeric control only; tile values/layout selectors excluded.
.setcpu "65816"
.segment "RODATA"
.org $5314
map_subpiece_control_source_20261014_cd5314:
    .byte $E8 | ((2-1)>>1)
    .byte (((2-1)&1)<<7) | (3-1)
