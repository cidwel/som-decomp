.setcpu "65816"
.segment "CODE"
.org $1951
map_control_0d1951:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E2 ; previous-row copy count
