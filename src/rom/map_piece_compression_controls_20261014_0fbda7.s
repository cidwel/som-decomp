.setcpu "65816"
.segment "CODE"
.org $BDA7
map_control_0fbda7:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
