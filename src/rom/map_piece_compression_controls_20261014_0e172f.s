.setcpu "65816"
.segment "CODE"
.org $172F
map_control_0e172f:
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E6 ; previous-row copy count
