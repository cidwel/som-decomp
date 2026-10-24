.setcpu "65816"
.segment "CODE"
.org $1ECA
map_control_0e1eca:
    .byte $E4 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
