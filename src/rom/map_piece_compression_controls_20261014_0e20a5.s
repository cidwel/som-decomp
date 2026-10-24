.setcpu "65816"
.segment "CODE"
.org $20A5
map_control_0e20a5:
    .byte $E5 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
