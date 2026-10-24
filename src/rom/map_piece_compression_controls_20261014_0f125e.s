.setcpu "65816"
.segment "CODE"
.org $125E
map_control_0f125e:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
