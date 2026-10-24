.setcpu "65816"
.segment "CODE"
.org $6ED9
map_control_0d6ed9:
    .byte $E1 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E1 ; previous-row copy count
