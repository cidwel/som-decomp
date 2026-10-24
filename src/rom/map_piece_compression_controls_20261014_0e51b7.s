.setcpu "65816"
.segment "CODE"
.org $51B7
map_control_0e51b7:
    .byte $D6 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
