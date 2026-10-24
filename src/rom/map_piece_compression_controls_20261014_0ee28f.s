.setcpu "65816"
.segment "CODE"
.org $E28F
map_control_0ee28f:
    .byte $C1 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
