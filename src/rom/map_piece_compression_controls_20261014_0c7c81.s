.setcpu "65816"
.segment "CODE"
.org $7C81
map_control_0c7c81:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
