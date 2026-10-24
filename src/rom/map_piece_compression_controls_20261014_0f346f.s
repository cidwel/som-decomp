.setcpu "65816"
.segment "CODE"
.org $346F
map_control_0f346f:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E1 ; previous-row copy count
