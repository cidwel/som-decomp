.setcpu "65816"
.segment "CODE"
.org $6E3A
map_control_0c6e3a:
    .byte $C3 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
