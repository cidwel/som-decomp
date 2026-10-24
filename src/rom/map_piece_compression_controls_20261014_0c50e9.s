.setcpu "65816"
.segment "CODE"
.org $50E9
map_control_0c50e9:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $D5 ; same-value copy count/distance
