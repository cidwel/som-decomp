.setcpu "65816"
.segment "CODE"
.org $F0C1
map_control_0ef0c1:
    .byte $D7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
