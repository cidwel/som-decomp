.setcpu "65816"
.segment "CODE"
.org $1404
map_control_0c1404:
    .byte $E0 ; previous-row copy escape
    .byte $41 ; row-distance/count
    .byte $C7 ; same-value copy count/distance
