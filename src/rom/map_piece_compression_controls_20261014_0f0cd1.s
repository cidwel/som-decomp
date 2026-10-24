.setcpu "65816"
.segment "CODE"
.org $0CD1
map_control_0f0cd1:
    .byte $E9 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E1 ; previous-row copy count
