.setcpu "65816"
.segment "CODE"
.org $BBA1
map_control_0dbba1:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
