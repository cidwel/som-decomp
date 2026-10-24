.setcpu "65816"
.segment "CODE"
.org $EEBC
map_control_0eeebc:
    .byte $E7 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
