.setcpu "65816"
.segment "CODE"
.org $A35F
map_control_0ea35f:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
