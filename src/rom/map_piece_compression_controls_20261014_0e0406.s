.setcpu "65816"
.segment "CODE"
.org $0406
map_control_0e0406:
    .byte $ED ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E2 ; previous-row copy count
