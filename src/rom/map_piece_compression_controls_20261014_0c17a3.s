.setcpu "65816"
.segment "CODE"
.org $17A3
map_control_0c17a3:
    .byte $E6 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
