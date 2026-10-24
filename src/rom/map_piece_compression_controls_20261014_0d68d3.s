.setcpu "65816"
.segment "CODE"
.org $68D3
map_control_0d68d3:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
