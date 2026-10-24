.setcpu "65816"
.segment "CODE"
.org $1D2F
map_control_0f1d2f:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count
