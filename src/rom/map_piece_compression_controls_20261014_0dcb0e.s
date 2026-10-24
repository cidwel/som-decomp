.setcpu "65816"
.segment "CODE"
.org $CB0E
map_control_0dcb0e:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
