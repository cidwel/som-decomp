.setcpu "65816"
.segment "CODE"
.org $1546
map_control_0d1546:
    .byte $E0 ; previous-row copy escape
    .byte $AF ; row-distance/count
    .byte $C1 ; same-value copy count/distance
