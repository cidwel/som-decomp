.setcpu "65816"
.segment "CODE"
.org $7096
map_control_0d7096:
    .byte $E5 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
