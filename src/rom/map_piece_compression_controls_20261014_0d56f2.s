.setcpu "65816"
.segment "CODE"
.org $56F2
map_control_0d56f2:
    .byte $C5 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
