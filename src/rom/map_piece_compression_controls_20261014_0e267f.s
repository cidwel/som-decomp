.setcpu "65816"
.segment "CODE"
.org $267F
map_control_0e267f:
    .byte $E2 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
