.setcpu "65816"
.segment "CODE"
.org $B88E
map_control_0db88e:
    .byte $C4 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
