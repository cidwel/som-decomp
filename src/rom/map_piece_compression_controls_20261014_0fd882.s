.setcpu "65816"
.segment "CODE"
.org $D882
map_control_0fd882:
    .byte $C6 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E7 ; previous-row copy count
