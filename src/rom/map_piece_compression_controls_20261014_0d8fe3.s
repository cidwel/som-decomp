.setcpu "65816"
.segment "CODE"
.org $8FE3
map_control_0d8fe3:
    .byte $C5 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
