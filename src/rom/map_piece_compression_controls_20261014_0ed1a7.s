.setcpu "65816"
.segment "CODE"
.org $D1A7
map_control_0ed1a7:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
