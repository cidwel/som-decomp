.setcpu "65816"
.segment "CODE"
.org $1719
map_control_0d1719:
    .byte $E9 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
