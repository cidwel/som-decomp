.setcpu "65816"
.segment "CODE"
.org $7E24
map_control_0c7e24:
    .byte $ED ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1D ; distance low bit/count
