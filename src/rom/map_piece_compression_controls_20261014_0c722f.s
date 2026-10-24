.setcpu "65816"
.segment "CODE"
.org $722F
map_control_0c722f:
    .byte $C5 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $1D ; distance low bit/count
