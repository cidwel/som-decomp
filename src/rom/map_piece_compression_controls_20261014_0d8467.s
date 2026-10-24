.setcpu "65816"
.segment "CODE"
.org $8467
map_control_0d8467:
    .byte $E9 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E7 ; previous-row copy count
