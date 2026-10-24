.setcpu "65816"
.segment "CODE"
.org $CC05
map_control_0ecc05:
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $D4 ; same-value copy count/distance
