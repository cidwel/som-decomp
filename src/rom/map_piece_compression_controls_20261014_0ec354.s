.setcpu "65816"
.segment "CODE"
.org $C354
map_control_0ec354:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E2 ; previous-row copy count
