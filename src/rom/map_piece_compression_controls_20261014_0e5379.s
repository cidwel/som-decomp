.setcpu "65816"
.segment "CODE"
.org $5379
map_control_0e5379:
    .byte $E7 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
