.setcpu "65816"
.segment "CODE"
.org $3104
map_control_0d3104:
    .byte $E5 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
