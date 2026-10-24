.setcpu "65816"
.segment "CODE"
.org $49D3
map_control_0d49d3:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
