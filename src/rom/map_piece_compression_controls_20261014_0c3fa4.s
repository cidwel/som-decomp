.setcpu "65816"
.segment "CODE"
.org $3FA4
map_control_0c3fa4:
    .byte $D7 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E1 ; previous-row copy count
