.setcpu "65816"
.segment "CODE"
.org $B344
map_control_0fb344:
    .byte $E3 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
    .byte $E6 ; previous-row copy count
