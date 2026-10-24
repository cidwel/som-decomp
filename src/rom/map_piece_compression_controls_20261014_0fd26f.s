.setcpu "65816"
.segment "CODE"
.org $D26F
map_control_0fd26f:
    .byte $E3 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
