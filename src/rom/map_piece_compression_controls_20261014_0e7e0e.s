.setcpu "65816"
.segment "CODE"
.org $7E0E
map_control_0e7e0e:
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
