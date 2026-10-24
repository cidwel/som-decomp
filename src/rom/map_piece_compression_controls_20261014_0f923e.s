.setcpu "65816"
.segment "CODE"
.org $923E
map_control_0f923e:
    .byte $C1 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
