.setcpu "65816"
.segment "CODE"
.org $1DD5
map_control_0d1dd5:
    .byte $E3 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
