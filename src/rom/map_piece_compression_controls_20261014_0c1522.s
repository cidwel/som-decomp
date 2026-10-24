.setcpu "65816"
.segment "CODE"
.org $1522
map_control_0c1522:
    .byte $D1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
