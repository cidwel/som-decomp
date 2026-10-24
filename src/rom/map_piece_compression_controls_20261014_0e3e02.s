.setcpu "65816"
.segment "CODE"
.org $3E02
map_control_0e3e02:
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
    .byte $E2 ; previous-row copy count
