.setcpu "65816"
.segment "CODE"
.org $1B9B
map_control_0e1b9b:
    .byte $C2 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
