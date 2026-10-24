.setcpu "65816"
.segment "CODE"
.org $2842
map_control_0d2842:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E2 ; previous-row copy count
