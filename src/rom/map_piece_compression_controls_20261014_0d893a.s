.setcpu "65816"
.segment "CODE"
.org $893A
map_control_0d893a:
    .byte $D2 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
