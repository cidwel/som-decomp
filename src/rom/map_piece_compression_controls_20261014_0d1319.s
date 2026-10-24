.setcpu "65816"
.segment "CODE"
.org $1319
map_control_0d1319:
    .byte $C9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
