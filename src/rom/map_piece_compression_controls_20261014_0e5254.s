.setcpu "65816"
.segment "CODE"
.org $5254
map_control_0e5254:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
