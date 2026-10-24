.setcpu "65816"
.segment "CODE"
.org $799F
map_control_0d799f:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
    .byte $C7 ; same-value copy count/distance
