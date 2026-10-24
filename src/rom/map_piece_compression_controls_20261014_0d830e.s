.setcpu "65816"
.segment "CODE"
.org $830E
map_control_0d830e:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
