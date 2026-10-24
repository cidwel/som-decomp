.setcpu "65816"
.segment "CODE"
.org $F2E1
map_control_0ff2e1:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $38 ; row-distance/count
