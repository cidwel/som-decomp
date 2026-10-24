.setcpu "65816"
.segment "CODE"
.org $5907
map_control_0e5907:
    .byte $C2 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
