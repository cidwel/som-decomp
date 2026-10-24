.setcpu "65816"
.segment "CODE"
.org $D38F
map_control_0fd38f:
    .byte $E6 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $D4 ; same-value copy count/distance
