.setcpu "65816"
.segment "CODE"
.org $56C2
map_control_0e56c2:
    .byte $C5 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
