.setcpu "65816"
.segment "CODE"
.org $AEC1
map_control_0eaec1:
    .byte $E9 ; backreference distance high bits
    .byte $05 ; distance low bit/count
