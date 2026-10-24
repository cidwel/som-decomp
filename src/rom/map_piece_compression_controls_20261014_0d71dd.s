.setcpu "65816"
.segment "CODE"
.org $71DD
map_control_0d71dd:
    .byte $E1 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
