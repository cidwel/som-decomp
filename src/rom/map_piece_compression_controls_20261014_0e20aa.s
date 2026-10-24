.setcpu "65816"
.segment "CODE"
.org $20AA
map_control_0e20aa:
    .byte $C1 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $5B ; row-distance/count
