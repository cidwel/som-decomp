.setcpu "65816"
.segment "CODE"
.org $9977
map_control_0d9977:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E1 ; previous-row copy count
