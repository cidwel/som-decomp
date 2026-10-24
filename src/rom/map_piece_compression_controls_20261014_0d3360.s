.setcpu "65816"
.segment "CODE"
.org $3360
map_control_0d3360:
    .byte $C4 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
