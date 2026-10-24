.setcpu "65816"
.segment "CODE"
.org $7F17
map_control_0d7f17:
    .byte $E4 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
