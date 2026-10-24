.setcpu "65816"
.segment "CODE"
.org $BBA7
map_control_0dbba7:
    .byte $ED ; backreference distance high bits
    .byte $08 ; distance low bit/count
