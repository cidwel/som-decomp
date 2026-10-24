.setcpu "65816"
.segment "CODE"
.org $7F65
map_control_0c7f65:
    .byte $E4 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
