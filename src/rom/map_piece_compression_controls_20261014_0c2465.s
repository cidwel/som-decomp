.setcpu "65816"
.segment "CODE"
.org $2465
map_control_0c2465:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
    .byte $C1 ; same-value copy count/distance
