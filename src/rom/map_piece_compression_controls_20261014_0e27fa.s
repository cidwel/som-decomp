.setcpu "65816"
.segment "CODE"
.org $27FA
map_control_0e27fa:
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E4 ; previous-row copy count
