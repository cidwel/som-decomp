.setcpu "65816"
.segment "CODE"
.org $F58B
map_control_0ff58b:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
