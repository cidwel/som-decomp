.setcpu "65816"
.segment "CODE"
.org $BF4D
map_control_0dbf4d:
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
