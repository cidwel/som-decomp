.setcpu "65816"
.segment "CODE"
.org $B3A1
map_control_0db3a1:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
    .byte $C4 ; same-value copy count/distance
