.setcpu "65816"
.segment "CODE"
.org $B823
map_control_0fb823:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
