.setcpu "65816"
.segment "CODE"
.org $3B7E
map_control_0f3b7e:
    .byte $E7 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
