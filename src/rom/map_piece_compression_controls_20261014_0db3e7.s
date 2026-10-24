.setcpu "65816"
.segment "CODE"
.org $B3E7
map_control_0db3e7:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E6 ; previous-row copy count
