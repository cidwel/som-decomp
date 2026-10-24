.setcpu "65816"
.segment "CODE"
.org $B6AE
map_control_0fb6ae:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E3 ; previous-row copy count
