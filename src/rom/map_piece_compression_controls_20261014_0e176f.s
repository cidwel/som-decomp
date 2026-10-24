.setcpu "65816"
.segment "CODE"
.org $176F
map_control_0e176f:
    .byte $E6 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $4F ; distance low bit/count
