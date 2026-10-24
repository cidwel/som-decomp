.setcpu "65816"
.segment "CODE"
.org $239D
map_control_0f239d:
    .byte $E8 ; backreference distance high bits
    .byte $1D ; distance low bit/count
    .byte $E7 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $30 ; distance low bit/count
