.setcpu "65816"
.segment "CODE"
.org $3E65
map_control_0e3e65:
    .byte $CC ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E7 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
