.setcpu "65816"
.segment "CODE"
.org $2D38
map_control_0d2d38:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
