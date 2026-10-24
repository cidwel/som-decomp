.setcpu "65816"
.segment "CODE"
.org $7650
map_control_0e7650:
    .byte $E7 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
