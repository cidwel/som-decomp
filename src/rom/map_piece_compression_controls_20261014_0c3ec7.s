.setcpu "65816"
.segment "CODE"
.org $3EC7
map_control_0c3ec7:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
