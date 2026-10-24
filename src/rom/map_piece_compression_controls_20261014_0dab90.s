.setcpu "65816"
.segment "CODE"
.org $AB90
map_control_0dab90:
    .byte $E6 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
