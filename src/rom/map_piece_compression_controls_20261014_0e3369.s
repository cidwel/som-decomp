.setcpu "65816"
.segment "CODE"
.org $3369
map_control_0e3369:
    .byte $EA ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E2 ; previous-row copy count
