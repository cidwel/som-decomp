.setcpu "65816"
.segment "CODE"
.org $8519
map_control_0f8519:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
