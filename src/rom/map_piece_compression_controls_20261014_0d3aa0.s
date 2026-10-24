.setcpu "65816"
.segment "CODE"
.org $3AA0
map_control_0d3aa0:
    .byte $E1 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
