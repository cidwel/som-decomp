.setcpu "65816"
.segment "CODE"
.org $A2BA
map_control_0ea2ba:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
