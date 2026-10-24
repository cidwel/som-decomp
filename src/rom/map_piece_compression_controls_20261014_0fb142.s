.setcpu "65816"
.segment "CODE"
.org $B142
map_control_0fb142:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E5 ; previous-row copy count
