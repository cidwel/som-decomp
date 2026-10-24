.setcpu "65816"
.segment "CODE"
.org $1C1C
map_control_0e1c1c:
    .byte $C9 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D7 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
