.setcpu "65816"
.segment "CODE"
.org $22F8
map_control_0f22f8:
    .byte $E7 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $05 ; distance low bit/count
