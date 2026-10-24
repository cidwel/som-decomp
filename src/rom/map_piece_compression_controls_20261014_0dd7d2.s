.setcpu "65816"
.segment "CODE"
.org $D7D2
map_control_0dd7d2:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
