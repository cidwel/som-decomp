.setcpu "65816"
.segment "CODE"
.org $8C9E
map_control_0d8c9e:
    .byte $E7 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
