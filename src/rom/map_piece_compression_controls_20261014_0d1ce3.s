.setcpu "65816"
.segment "CODE"
.org $1CE3
map_control_0d1ce3:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $B3 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
