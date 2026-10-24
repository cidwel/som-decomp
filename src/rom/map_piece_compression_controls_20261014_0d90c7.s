.setcpu "65816"
.segment "CODE"
.org $90C7
map_control_0d90c7:
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
