.setcpu "65816"
.segment "CODE"
.org $E4B3
map_control_0fe4b3:
    .byte $E7 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
