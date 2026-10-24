.setcpu "65816"
.segment "CODE"
.org $5399
map_control_0d5399:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
