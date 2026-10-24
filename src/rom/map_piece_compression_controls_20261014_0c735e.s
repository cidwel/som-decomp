.setcpu "65816"
.segment "CODE"
.org $735E
map_control_0c735e:
    .byte $E5 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
