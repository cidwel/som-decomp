.setcpu "65816"
.segment "CODE"
.org $1D66
map_control_0f1d66:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D2 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
