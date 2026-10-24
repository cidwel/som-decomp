.setcpu "65816"
.segment "CODE"
.org $705F
map_control_0d705f:
    .byte $E5 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
