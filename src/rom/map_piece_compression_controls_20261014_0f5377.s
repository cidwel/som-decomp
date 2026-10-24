.setcpu "65816"
.segment "CODE"
.org $5377
map_control_0f5377:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E6 ; previous-row copy count
