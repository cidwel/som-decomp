.setcpu "65816"
.segment "CODE"
.org $67D3
map_control_0e67d3:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
