.setcpu "65816"
.segment "CODE"
.org $7BE6
map_control_0d7be6:
    .byte $C5 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count
