.setcpu "65816"
.segment "CODE"
.org $8A2A
map_control_0f8a2a:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
    .byte $E7 ; previous-row copy count
