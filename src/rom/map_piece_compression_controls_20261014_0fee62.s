.setcpu "65816"
.segment "CODE"
.org $EE62
map_control_0fee62:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
