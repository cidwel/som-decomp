.setcpu "65816"
.segment "CODE"
.org $1E8A
map_control_0e1e8a:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E7 ; previous-row copy count
