.setcpu "65816"
.segment "CODE"
.org $2120
map_control_0f2120:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
