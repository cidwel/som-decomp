.setcpu "65816"
.segment "CODE"
.org $7A3A
map_control_0c7a3a:
    .byte $E4 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
