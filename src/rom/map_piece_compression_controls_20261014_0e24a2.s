.setcpu "65816"
.segment "CODE"
.org $24A2
map_control_0e24a2:
    .byte $E3 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
    .byte $E2 ; previous-row copy count
