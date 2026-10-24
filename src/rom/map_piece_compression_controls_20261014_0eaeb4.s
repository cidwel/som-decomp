.setcpu "65816"
.segment "CODE"
.org $AEB4
map_control_0eaeb4:
    .byte $E9 ; backreference distance high bits
    .byte $05 ; distance low bit/count
