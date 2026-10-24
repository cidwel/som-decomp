.setcpu "65816"
.segment "CODE"
.org $2470
map_control_0d2470:
    .byte $E2 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E1 ; previous-row copy count
