.setcpu "65816"
.segment "CODE"
.org $9C05
map_control_0d9c05:
    .byte $E1 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
