.setcpu "65816"
.segment "CODE"
.org $FA53
map_control_0cfa53:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
