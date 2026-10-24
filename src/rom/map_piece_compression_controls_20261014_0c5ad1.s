.setcpu "65816"
.segment "CODE"
.org $5AD1
map_control_0c5ad1:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
