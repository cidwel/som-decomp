.setcpu "65816"
.segment "CODE"
.org $6EE9
map_control_0c6ee9:
    .byte $E6 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
