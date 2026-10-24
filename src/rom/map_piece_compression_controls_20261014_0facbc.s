.setcpu "65816"
.segment "CODE"
.org $ACBC
map_control_0facbc:
    .byte $C3 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
