.setcpu "65816"
.segment "CODE"
.org $1B92
map_control_0e1b92:
    .byte $C2 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
