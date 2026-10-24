.setcpu "65816"
.segment "CODE"
.org $BD7E
map_control_0fbd7e:
    .byte $C3 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
