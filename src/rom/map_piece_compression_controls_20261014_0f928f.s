.setcpu "65816"
.segment "CODE"
.org $928F
map_control_0f928f:
    .byte $E7 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
