.setcpu "65816"
.segment "CODE"
.org $23EE
map_control_0f23ee:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $D3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D2 ; same-value copy count/distance
