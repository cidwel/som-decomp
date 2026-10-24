.setcpu "65816"
.segment "CODE"
.org $0A13
map_control_0d0a13:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E2 ; previous-row copy count
