.setcpu "65816"
.segment "CODE"
.org $1990
map_control_0d1990:
    .byte $C6 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E1 ; previous-row copy count
