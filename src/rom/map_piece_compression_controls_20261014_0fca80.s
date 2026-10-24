.setcpu "65816"
.segment "CODE"
.org $CA80
map_control_0fca80:
    .byte $C4 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $24 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
