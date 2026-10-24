.setcpu "65816"
.segment "CODE"
.org $7ADD
map_control_0e7add:
    .byte $E7 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
