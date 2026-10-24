.setcpu "65816"
.segment "CODE"
.org $56B2
map_control_0d56b2:
    .byte $D3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
