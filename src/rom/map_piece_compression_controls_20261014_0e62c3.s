.setcpu "65816"
.segment "CODE"
.org $62C3
map_control_0e62c3:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C9 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
