.setcpu "65816"
.segment "CODE"
.org $2509
map_control_0d2509:
    .byte $E7 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
