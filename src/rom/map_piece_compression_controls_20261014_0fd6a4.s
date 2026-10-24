.setcpu "65816"
.segment "CODE"
.org $D6A4
map_control_0fd6a4:
    .byte $E3 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $0A ; distance low bit/count
