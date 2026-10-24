.setcpu "65816"
.segment "CODE"
.org $3EA9
map_control_0c3ea9:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
