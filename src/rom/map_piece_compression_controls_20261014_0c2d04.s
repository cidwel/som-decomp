.setcpu "65816"
.segment "CODE"
.org $2D04
map_control_0c2d04:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
