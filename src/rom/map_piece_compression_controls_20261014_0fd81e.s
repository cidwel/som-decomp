.setcpu "65816"
.segment "CODE"
.org $D81E
map_control_0fd81e:
    .byte $C7 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
