.setcpu "65816"
.segment "CODE"
.org $90B9
map_control_0d90b9:
    .byte $D2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
