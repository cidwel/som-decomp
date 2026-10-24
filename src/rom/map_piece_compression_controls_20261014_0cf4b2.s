.setcpu "65816"
.segment "CODE"
.org $F4B2
map_control_0cf4b2:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
    .byte $E2 ; previous-row copy count
