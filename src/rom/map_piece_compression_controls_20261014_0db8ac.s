.setcpu "65816"
.segment "CODE"
.org $B8AC
map_control_0db8ac:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E6 ; previous-row copy count
