.setcpu "65816"
.segment "CODE"
.org $3E32
map_control_0e3e32:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
