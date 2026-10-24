.setcpu "65816"
.segment "CODE"
.org $FCF8
map_control_0dfcf8:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
