.setcpu "65816"
.segment "CODE"
.org $C885
map_control_0ec885:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E6 ; previous-row copy count
