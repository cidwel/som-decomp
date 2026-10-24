.setcpu "65816"
.segment "CODE"
.org $B830
map_control_0eb830:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
