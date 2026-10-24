.setcpu "65816"
.segment "CODE"
.org $1512
map_control_0e1512:
    .byte $C5 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
