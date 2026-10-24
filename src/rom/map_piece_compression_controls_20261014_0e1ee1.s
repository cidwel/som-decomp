.setcpu "65816"
.segment "CODE"
.org $1EE1
map_control_0e1ee1:
    .byte $E2 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E1 ; previous-row copy count
