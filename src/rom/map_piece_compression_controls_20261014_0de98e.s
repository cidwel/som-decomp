.setcpu "65816"
.segment "CODE"
.org $E98E
map_control_0de98e:
    .byte $C5 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
