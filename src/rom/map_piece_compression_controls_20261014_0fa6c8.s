.setcpu "65816"
.segment "CODE"
.org $A6C8
map_control_0fa6c8:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
