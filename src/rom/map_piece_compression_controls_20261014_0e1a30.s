.setcpu "65816"
.segment "CODE"
.org $1A30
map_control_0e1a30:
    .byte $E9 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
