.setcpu "65816"
.segment "CODE"
.org $3DE2
map_control_0d3de2:
    .byte $EF ; backreference distance high bits
    .byte $08 ; distance low bit/count
