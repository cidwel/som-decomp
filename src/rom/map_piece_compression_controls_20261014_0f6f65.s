.setcpu "65816"
.segment "CODE"
.org $6F65
map_control_0f6f65:
    .byte $C4 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
