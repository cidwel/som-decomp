.setcpu "65816"
.segment "CODE"
.org $31F8
map_control_0c31f8:
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
