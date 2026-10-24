.setcpu "65816"
.segment "CODE"
.org $D95E
map_control_0ed95e:
    .byte $E1 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
