.setcpu "65816"
.segment "CODE"
.org $D024
map_control_0fd024:
    .byte $C6 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E4 ; previous-row copy count
