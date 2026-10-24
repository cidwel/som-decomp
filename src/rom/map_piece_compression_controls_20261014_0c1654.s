.setcpu "65816"
.segment "CODE"
.org $1654
map_control_0c1654:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
    .byte $C4 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
