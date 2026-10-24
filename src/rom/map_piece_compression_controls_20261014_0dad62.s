.setcpu "65816"
.segment "CODE"
.org $AD62
map_control_0dad62:
    .byte $E3 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
