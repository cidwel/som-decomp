.setcpu "65816"
.segment "CODE"
.org $8600
map_control_0e8600:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E2 ; previous-row copy count
